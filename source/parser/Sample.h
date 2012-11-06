#ifndef BLITZORTUNG_PARSER_SAMPLE_H_
#define BLITZORTUNG_PARSER_SAMPLE_H_

#include <boost/shared_ptr.hpp>

#include <string>
#include <vector>

#include "namespaces.h"
#include "Logger.h"
#include "parser/Base.h"
#include "data/Waveform.h"

namespace blitzortung {
  namespace parser {

    //! base class for gps hardware objects      
    class Sample : public Base {

      private:

	static const data::Format FORMAT_8_2_1;
	static const data::Format FORMAT_12_2_1;
	static const data::Format FORMAT_8_2_64;
	static const data::Format FORMAT_8_1_128;
	static const data::Format FORMAT_8_2_256;

	//! parsed waveform
	data::Waveform::AP waveform_;

	//! string containing the raw data transmitted from the hardware
	std::string rawData_;

	//! bits per data sample
	unsigned char bitsPerSample_;

	//! logger for this class
	mutable Logger logger_;

	//! set parsed waveform
	void setWaveform(const data::Format&, const pt::ptime&, const pt::time_duration&&, const std::string&&, unsigned char bitsPerSample=0);

      public:

	//! constructor
	Sample(const data::Format& format, const pt::ptime& timestamp, const unsigned short samplePeriod, const std::string& data);

	//! get raw sample data string
	const std::string& getRawData() const;

	//! get parsed waveform
	data::Waveform::AP getWaveform();
    };

  }
}
#endif
