#ifndef LIBBLITZORTUNG_IPC_UNIXSOCKET_H_
#define LIBBLITZORTUNG_IPC_UNIXSOCKET_H_

/*
 * libblitzortung - a shared library for Blitzortung.org tracker and data handling
 *
 * Copyright (c) 2013 Andreas Würl
 * Licensed under the MIT License
 */

#include "Logger.h"
#include "ipc/server/factory/Base.h"

namespace blitzortung {
  namespace ipc {

    class UnixSocket  {

      private:

	//! generated ѕocket
	unsigned int socket_;

	//! name of socket file	
	const std::string socketFileName_;

	//! logger for this class
	mutable Logger logger_;

	// make class objects noncopyable
	UnixSocket(const UnixSocket&) = delete;
	UnixSocket& operator=(const UnixSocket&) = delete;

      public:

	//! construct socket
	UnixSocket(const std::string& socketFileName, const ipc::server::factory::Base& serverFactory);

	//! destruct socket
	virtual ~UnixSocket();
    };
  }
}

#endif
