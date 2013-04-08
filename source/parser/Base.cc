/*
 * libblitzortung - a shared library for Blitzortung.org tracker and data handling
 *
 * Copyright (c) 2013 Andreas Würl
 * Licensed under the MIT License
 */

#include <cmath>
#include <sstream>

#include "parser/Base.h"

namespace blitzortung {
  namespace parser {

    Base::Base() :
      valid_(false),
      counter_(0)
    {
    }

    Base::~Base() {}

    int Base::parseInt(const std::string& intString) const {
      int intValue;

      std::istringstream iss(intString);
      iss >> intValue;

      return intValue;
    }

    float Base::parseFloat(const std::string& floatString) const {
      float floatValue;

      std::istringstream iss(floatString);
      iss >> floatValue;

      return floatValue;
    }

    unsigned int Base::parseHex(const std::string& hexString) const {
      unsigned int value;

      std::istringstream iss(hexString);
      iss >> std::hex >> value;
      return value;
    }

    float Base::parseGpsCoord(const std::string& coordString, const std::string& hemisphere) const {
      double degreeMinuteValue;

      std::istringstream iss(coordString);
      iss >> degreeMinuteValue;

      double decimalDegreeValue = floor(degreeMinuteValue / 100.0);

      decimalDegreeValue += (degreeMinuteValue - decimalDegreeValue * 100.0) / 60.0;

      if (hemisphere == "W" || hemisphere == "S")
	decimalDegreeValue *= -1.0;

      return decimalDegreeValue;
    }

    unsigned int Base::getCounterValue() const {
      return counter_;
    }

    bool Base::isValid() const {
      return valid_;
    }

  }
}
