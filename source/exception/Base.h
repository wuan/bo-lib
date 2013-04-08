#ifndef LIBBLITZORTUNG_EXCEPTION_BASE_H_
#define LIBBLITZORTUNG_EXCEPTION_BASE_H_

/*
 * libblitzortung - a shared library for Blitzortung.org tracker and data handling
 *
 * Copyright (c) 2013 Andreas Würl
 * Licensed under the MIT License
 */

#include <string>
#include <exception>

namespace blitzortung {
  namespace exception {

    class Base : public std::exception {
      protected:
	std::string msg_;

	Base() throw();

      public:
	Base(const std::string&) throw();
	virtual ~Base() throw();

	//! return the error description
	virtual const char* what() const throw();
    };
  }
}

#endif /* BASE_H_ */
