/*
 * libblitzortung - a shared library for Blitzortung.org tracker and data handling
 *
 * Copyright (c) 2013 Andreas Würl
 * Licensed under the MIT License
 */

#include "exception/Base.h"

namespace blitzortung {
  namespace exception {

    Base::Base() throw() :
      msg_()
    {
    }

    Base::Base(const std::string& msg) throw() :
      msg_(msg) {
    }

    Base::~Base() throw() {
    }

    const char* Base::what() const throw() {
      return msg_.c_str();
    }

  }
}
