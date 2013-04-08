#ifndef LIBBLITZORTUNG_UTIL_STRING_H_
#define LIBBLITZORTUNG_UTIL_STRING_H_

/*
 * libblitzortung - a shared library for Blitzortung.org tracker and data handling
 *
 * Copyright (c) 2013 Andreas Würl
 * Licensed under the MIT License
 */

#include <string>

#include <boost/algorithm/string/regex.hpp>

namespace blitzortung {
  namespace util {

    class String {
      public:
	static void split(const std::string &input, std::vector<std::string> &results, const std::string &regexp);

    };

  }
}

#endif
