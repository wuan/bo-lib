#ifndef LIBBLITZORTUNG_NAMESPACES_H_
#define LIBBLITZORTUNG_NAMESPACES_H_

/*
 * libblitzortung - a shared library for Blitzortung.org tracker and data handling
 *
 * Copyright (c) 2013 Andreas Würl
 * Licensed under the MIT License
 */

#include "config.h"

#include <boost/date_time.hpp>
#include <boost/program_options.hpp>

#ifdef HAVE_BOOST_ACCUMULATORS_ACCUMULATORS_HPP
#include <boost/accumulators/accumulators.hpp>
namespace ac = boost::accumulators;
#endif

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;
namespace po = boost::program_options;

namespace blitzortung {
}

namespace bo = blitzortung;

#endif
