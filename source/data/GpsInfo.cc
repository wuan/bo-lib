#include "data/GpsInfo.h"
#include "data/Gps.h"
#include "util/Stream.h"
#include "util/Size.h"

namespace blitzortung {
  namespace data {

    GpsInfo::GpsInfo(const data::Gps& gps) :
      longitude_(gps.getLongitude()),
      latitude_(gps.getLatitude()),
      altitude_(gps.getAltitude()),
      numberOfSatellites_(gps.getNumberOfSatellites()),
      status_(gps.getStatus())
    {
    }

    GpsInfo::GpsInfo(std::iostream& stream) {
	util::Stream::ReadValue(stream, longitude_);
	util::Stream::ReadValue(stream, latitude_);
	util::Stream::ReadValue(stream, altitude_);
	util::Stream::ReadValue(stream, numberOfSatellites_);
	util::Stream::ReadValue(stream, status_);
    }

    GpsInfo::GpsInfo(float longitude, float latitude, short altitude) :
      longitude_(longitude),
      latitude_(latitude),
      altitude_(altitude),
      numberOfSatellites_(0),
      status_(0)
    {
    }

    GpsInfo::~GpsInfo()
    {
    }

    float GpsInfo::getLongitude() const {
      return longitude_;
    }

    float GpsInfo::getLatitude() const {
      return latitude_;
    }

    short GpsInfo::getAltitude() const {
      return altitude_;
    }

    unsigned short GpsInfo::getNumberOfSatellites() const {
      return numberOfSatellites_;
    }

    char GpsInfo::getStatus() const {
      return status_;
    }

    void GpsInfo::toStream(std::iostream& stream) {
      // write gps information to stream
      util::Stream::WriteValue(stream, longitude_);
      util::Stream::WriteValue(stream, latitude_);
      util::Stream::WriteValue(stream, altitude_);
      util::Stream::WriteValue(stream, numberOfSatellites_);
      util::Stream::WriteValue(stream, status_);
    }

    size_t GpsInfo::getSize() {

      util::Size size;
      size.add(longitude_);
      size.add(latitude_);
      size.add(altitude_);
      size.add(numberOfSatellites_);
      size.add(status_);

      return size.get();
    }

    size_t GpsInfo::GetSize() {
      static GpsInfo gpsInfo(0,0,0);

      return gpsInfo.getSize();
    }

    std::ostream& operator <<(std::ostream& os, const bo::data::GpsInfo &gpsInfo) {
      os.setf(std::ios::fixed);
      os.precision(4);

      os << gpsInfo.getLongitude() << " " << gpsInfo.getLatitude();
      os << " " << gpsInfo.getAltitude();
      os << " " << (int) gpsInfo.getNumberOfSatellites();

      return os;
    }


  }
}
