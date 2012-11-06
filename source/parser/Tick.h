#ifndef BLITZORTUNG_PARSER_TICK_H_
#define BLITZORTUNG_PARSER_TICK_H_

#include <boost/shared_ptr.hpp>

#include <string>
#include <vector>

#include "namespaces.h"
#include "Logger.h"
#include "parser/Base.h"

namespace blitzortung {
  namespace parser {

    //! base class for gps hardware objects      
    class Tick : public Base {

      private:

	//! combined date time string
	pt::ptime dateTime_;

	//! gps status character
	std::string status_;

	//! gps longitude
	float longitude_;

	//! gps latitude
	float latitude_;

	//! gps altitude
	short altitude_;

	//! gps number of satellites in use
	unsigned short numberOfSatellites_;

	//! controller firmware version
	std::string firmwareVersion_;

	//! logger for this class
	mutable Logger logger_;

      public:

	//! constructor
	Tick(const std::vector<std::string>&);

	//! parse incoming data
	bool parse(const std::vector<std::string>);

	//! read GPS status char
	char getGpsStatus() const;

	//! get longitude value
	float getLongitude() const;

	//! get latitude value
	float getLatitude() const;

	//! get altitude value
	short getAltitude() const;

	//! get average satellite count value
	unsigned short getNumberOfSatellites() const;

	//! get timestamp from counter value
	const pt::ptime& getDateTime() const;

	//! get firmware version
	const std::string& getFirmwareVersion() const;
    };

  }
}
#endif
