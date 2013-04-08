/*
 * libblitzortung - a shared library for Blitzortung.org tracker and data handling
 *
 * Copyright (c) 2013 Andreas Würl
 * Licensed under the MIT License
 */

#include "ipc/server/factory/Base.h"

namespace blitzortung {
  namespace ipc {
    namespace server {
      namespace factory {

	Base::Base() :
	  logger_("ipc.server.factory.Base")
	{
	  if (logger_.isDebugEnabled())
	    logger_.debugStream() << "initialize factory ";
	}

      }
    }
  }
}
