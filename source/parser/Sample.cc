#include "data/Format.h"
#include "parser/Sample.h"
#include "exception/Base.h"

namespace blitzortung {
  namespace parser {

    Sample::Sample(const data::Format& format, const pt::ptime& timestamp, const unsigned short samplePeriod, const std::string& data) :
      Base(),
      waveform_(),
      rawData_(),
      bitsPerSample_(0),
      logger_("hardware.parsing.Sample")
    {
      setWaveform(format, timestamp, std::move(pt::nanoseconds(samplePeriod)), std::move(data));
    }

    void Sample::setWaveform(const data::Format& format, const pt::ptime& eventtime, const pt::time_duration&& sampleDt, const std::string&& rawData, unsigned char numberOfBitsPerSample) {
      if (numberOfBitsPerSample == 0) {
	numberOfBitsPerSample = format.getNumberOfBytesPerSample() * 8;
      }

      std::ostringstream oss;
      oss << (int)format.getNumberOfChannels() << " " << format.getNumberOfSamples() << " "  << (int)numberOfBitsPerSample <<  " " << rawData;
      rawData_ = oss.str();

      // parse lighning event information
      if (format.isValid()) {
	int numberOfEvents = rawData.size() >> 2;

	waveform_ = format.createWaveform(eventtime, sampleDt);

	unsigned short hexCharsPerSample = (numberOfBitsPerSample + 3 ) / 4;
	unsigned short numberOfChannels = format.getNumberOfChannels();

	int offset =  -(1 << (numberOfBitsPerSample - 1));

	if (logger_.isDebugEnabled())
	  logger_.debugStream() << "#ch " << numberOfChannels << ", #chars/sample " << hexCharsPerSample << " zeroOffset " << offset;

	int index = 0;
	for (int sample=0; sample < numberOfEvents; sample++) {
	  for (int channel=0; channel < numberOfChannels; channel++) {
	    std::string hexString = rawData.substr(index, hexCharsPerSample);
	    waveform_->setInt(int(offset + parseHex(hexString)), sample, channel);
	    index += hexCharsPerSample;
	  }
	}

	valid_ = true;
      } else {
	logger_.warnStream() << "invalid format " << format;
      }
    }

    data::Waveform::AP Sample::getWaveform() {
      return std::move(waveform_);
    }

    const std::string& Sample::getRawData() const {
      return rawData_;
    }

    const data::Format Sample::FORMAT_8_2_1(1,2,1);
    const data::Format Sample::FORMAT_12_2_1(2,2,1);
    const data::Format Sample::FORMAT_8_2_64(1,2,64);
    const data::Format Sample::FORMAT_8_1_128(1,1,128);
    const data::Format Sample::FORMAT_8_2_256(1,2,256);
  }
}
