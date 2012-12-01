#include "parser/Tick.h"
#include "exception/Base.h"

namespace blitzortung {
  namespace parser {

    Tick::Tick(const std::vector<std::string>& fields) :
      Base(),
      dateTime_(),
      status_(),
      longitude_(),
      latitude_(),
      altitude_(),
      satelliteCount_(),
      firmwareVersion_(),
      logger_("hardware.parsing.Tick()")
    {
      unsigned int counterIndex = 0;
      unsigned int gpsStatusIndex = 0;
      unsigned int timeIndex = 0;
      unsigned int dateIndex = 0;
      unsigned int longitudeIndex = 0;
      unsigned int longitudeHemisphereIndex = 0;
      unsigned int latitudeIndex = 0;
      unsigned int latitudeHemisphereIndex = 0;
      unsigned int altitudeIndex = 0;
      unsigned int satelliteCountIndex = 0;
      unsigned int firmwareVersionIndex = 0;

      unsigned int index = 1;
      if (fields[0] == "BS" || fields[0] == "S") {
	counterIndex = index++;
	gpsStatusIndex =  index++;
	timeIndex = index++;
	dateIndex = index++;
	latitudeIndex = index++;
	latitudeHemisphereIndex = index++;
	longitudeIndex = index++;
	longitudeHemisphereIndex = index++;
	altitudeIndex = index++;
	satelliteCountIndex = index++;
	firmwareVersionIndex = index++;
	valid_ = true;
      } else if (fields[0] == "BLSEC") {
	if (fields.size() == 12) {
	  counterIndex = index++;
	  gpsStatusIndex =  index++;
	  timeIndex = index++;
	  dateIndex = index++;
	  latitudeIndex = index++;
	  latitudeHemisphereIndex = index++;
	  longitudeIndex = index++;
	  longitudeHemisphereIndex = index++;
	  altitudeIndex = index++;
	  index++;
	  satelliteCountIndex = index++;
	  valid_ = true;
	} else if (fields.size() == 9) {
	  timeIndex = index++;
	  dateIndex = index++;
	  gpsStatusIndex = index++;
	  latitudeIndex = index++;
	  latitudeHemisphereIndex = index++;
	  longitudeIndex = index++;
	  longitudeHemisphereIndex = index++;
	  counterIndex = index++;
	  valid_ = true;
	}
      }

      if (valid_) {
	// read counter value
	counter_ = parseHex(fields[counterIndex]);

	// set GPS reception status
	status_ = fields[gpsStatusIndex];

	// set GPS PPS time
	pt::time_input_facet *facet = new pt::time_input_facet();
	facet->format("%d%m%y %H%M%S");
	std::string dateTime = fields[dateIndex] + " " + fields[timeIndex];
	std::istringstream dateTimeInput(dateTime);
	dateTimeInput.imbue(std::locale(std::locale::classic(), facet));
	dateTimeInput >> dateTime_;

	if (dateTime_.is_not_a_date_time())
	  logger_.warnStream() << "Tick() could not parse datetime '" << dateTime << "'";

	longitude_ = parseGpsCoord(fields[longitudeIndex], fields[longitudeHemisphereIndex]);
	latitude_ = parseGpsCoord(fields[latitudeIndex], fields[latitudeHemisphereIndex]);

	if (altitudeIndex > 0) {
	  altitude_ = round(parseFloat(fields[altitudeIndex]));
	} else {
	  altitude_ = 0;
	}

	if (satelliteCountIndex > 0) {
	  satelliteCount_ = parseInt(fields[satelliteCountIndex]);
	} else {
	  satelliteCount_ = 0;
	}

	if (firmwareVersionIndex > 0) {
	  firmwareVersion_ = fields[firmwareVersionIndex];
	} else {
	  firmwareVersion_ = "";
	}
      }

    }

    unsigned short Tick::getSatelliteCount() const {
      return satelliteCount_;
    }

    float Tick::getLongitude() const {
      return longitude_;
    }

    float Tick::getLatitude() const {
      return latitude_;
    }

    short Tick::getAltitude() const {
      return altitude_;
    }

    char Tick::getGpsStatus() const {
      return status_[0];
    }

    const pt::ptime& Tick::getDateTime() const {
      return dateTime_;
    }

    const std::string& Tick::getFirmwareVersion() const {
      return firmwareVersion_;
    }

  }
}
