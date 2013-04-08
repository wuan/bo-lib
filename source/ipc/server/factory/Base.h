#ifndef LIBBLITZORTUNG_IPC_SERVER_FACTORY_BASE_H_
#define LIBBLITZORTUNG_IPC_SERVER_FACTORY_BASE_H_

/*
 * libblitzortung - a shared library for Blitzortung.org tracker and data handling
 *
 * Copyright (c) 2013 Andreas Würl
 * Licensed under the MIT License
 */

#include <thread>

#include "Logger.h"
#include "ipc/server/Base.h"

namespace blitzortung {
  namespace ipc {
    namespace server {
      namespace factory {

	class Base {

	  private:

	    //! logger for this class
	    mutable Logger logger_;

	  public:

	    //! construct socket
	    Base();

	    //! virtual destructor
	    virtual ~Base() {};

	    virtual void createServerThread(const unsigned int socket) const = 0; 
	};

      }
    }
  }
}

#endif
