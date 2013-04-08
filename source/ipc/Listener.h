#ifndef LIBBLITZORTUNG_IPC_LISTENER_H_
#define LIBBLITZORTUNG_IPC_LISTENER_H_

/*
 * libblitzortung - a shared library for Blitzortung.org tracker and data handling
 *
 * Copyright (c) 2013 Andreas Würl
 * Licensed under the MIT License
 */

#include <sys/socket.h>

#include "Logger.h"
#include "ipc/server/factory/Base.h"

namespace blitzortung {
  namespace ipc {

    class Listener {

      private:

	//! socket for which this listener is active
	const unsigned int socket_;

	sockaddr& sockaddr_;

	socklen_t sockaddrSize_;
	
	// reference to server factory object	
	const ipc::server::factory::Base& serverFactory_;

	//! logger for this class
	mutable Logger logger_;

      public:

	//! construct socket
	Listener(const unsigned int socket, sockaddr& sockaddr, socklen_t sockaddrSize, const ipc::server::factory::Base& serverFactory);

	//! listener thread procedure
	void operator ()();
    };

  }
}

#endif
