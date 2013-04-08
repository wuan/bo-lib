#ifndef LIBBLITZORTUNG_DATA_GPS_H_
#define LIBBLITZORTUNG_DATA_GPS_H_

/*
 * libblitzortung - a shared library for Blitzortung.org tracker and data handling
 *
 * Copyright (c) 2013 Andreas Würl
 * Licensed under the MIT License
 */

#include "namespaces.h"

namespace blitzortung {
  namespace data {

    //! class for gps information
    class Gps {

      public:

	//! returns longitude
	virtual float getLongitude() const = 0;

	//! returns latitude
	virtual float getLatitude() const = 0;

	//! returns altitude
	virtual short getAltitude() const = 0;

	//! returns the number of satellites available to the gps module
	virtual unsigned short getSatelliteCount() const = 0;

	//! returns the acquisition status of the gps module
	virtual char getStatus() const = 0;

        virtual ~Gps() {};
    };

  }
}
#endif
