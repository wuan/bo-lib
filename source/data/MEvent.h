#ifndef LIBBLITZORTUNG_DATA_MEVENT_H_
#define LIBBLITZORTUNG_DATA_MEVENT_H_

/*
 * libblitzortung - a shared library for Blitzortung.org tracker and data handling
 *
 * Copyright (c) 2013 Andreas Würl
 * Licensed under the MIT License
 */

#include "namespaces.h"
#include "data/Event.h"

namespace blitzortung {
  namespace data {

    //! class for gps information
    class MEvent : public Event {

      public:

	typedef boost::ptr_vector<MEvent> V;
	typedef V::iterator VI;
	typedef V::const_iterator CVI;
	typedef std::shared_ptr<V> VP;
	typedef std::unique_ptr<MEvent> AP;

      private:

	const std::string rawData_;

      public:

	MEvent(Waveform::AP&&, GpsInfo::AP&&, const std::string&);

	virtual ~MEvent();

	//! get the raw data string
	const std::string& getRawData() const;
    };

  }
}
#endif
