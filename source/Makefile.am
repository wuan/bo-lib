AUTOMAKE_OPTIONS = subdir-objects

AM_LDFLAGS = \
	$(NULL)

lib_LTLIBRARIES = libblitzortung.la

libblitzortung_la_LDFLAGS = \
	${BLITZORTUNG_LDFLAGS} \
	-release ${VERSION} \
	-version_info ${LIBRARY_VERSION} \
	-no undefined

libblitzortung_la_SOURCES = \
	data/Array.h data/Array.cc \
	data/ArrayOf.h data/ArrayOf.cc \
	data/Format.h data/Format.cc \
	data/Event.h data/Event.cc \
	data/MEvent.h data/MEvent.cc \
	data/Events.h data/Events.cc \
	data/EventsFile.h data/EventsFile.cc \
	data/EventsHeader.h data/EventsHeader.cc \
	data/Waveform.h data/Waveform.cc \
	data/WaveformOf.h data/WaveformOf.cc \
	data/GpsInfo.h data/GpsInfo.cc \
	data/Gps.h \
	\
	exception/Base.h exception/Base.cc \
	\
	Logger.h Logger.cc \
	\
	namespaces.h \
	\
	ipc/UnixSocket.h ipc/UnixSocket.cc \
	ipc/Listener.h ipc/Listener.cc \
	ipc/Queue.h ipc/Queue.cc \
	ipc/server/Base.h ipc/server/Base.cc \
	ipc/server/factory/Base.h ipc/server/factory/Base.cc \
	\
	parser/Base.h parser/Base.cc \
	parser/Sample.h parser/Sample.cc \
	parser/Tick.h parser/Tick.cc\
	\
	util/RingBuffer.h util/RingBuffer.cc \
	util/Size.h \
	util/String.h util/String.cc \
	util/Stream.h \
	\
	$(NULL)

libblitzortungincludedir = $(includedir)/blitzortung
libblitzortunginclude_HEADERS = \
	Logger.h \
	namespaces.h \
	$(NULL)

libblitzortungdataincludedir = $(includedir)/blitzortung/data
libblitzortungdatainclude_HEADERS = \
	data/Array.h \
	data/ArrayOf.h \
	data/Format.h \
	data/Event.h \
	data/MEvent.h \
	data/Events.h \
	data/EventsFile.h \
	data/EventsHeader.h \
	data/Waveform.h \
	data/WaveformOf.h \
	data/GpsInfo.h data/GpsInfo.cc \
	data/Gps.h \
	$(NULL)

libblitzortungexceptionincludedir = $(includedir)/blitzortung/exception
libblitzortungexceptioninclude_HEADERS = \
	exception/Base.h \
	$(NULL)

libblitzortungipcincludedir = $(includedir)/blitzortung/ipc
libblitzortungipcinclude_HEADERS = \
	ipc/UnixSocket.h \
	ipc/Listener.h \
	ipc/Queue.h \
	$(NULL)

libblitzortungipcserverincludedir = $(includedir)/blitzortung/ipc/server
libblitzortungipcserverinclude_HEADERS = \
	ipc/server/Base.h \
	$(NULL)

libblitzortungipcserverfactoryincludedir = $(includedir)/blitzortung/ipc/server/factory
libblitzortungipcserverfactoryinclude_HEADERS = \
	ipc/server/factory/Base.h \
	$(NULL)

libblitzortungparserincludedir = $(includedir)/blitzortung/parser
libblitzortungparserinclude_HEADERS = \
	parser/Base.h \
	parser/Sample.h \
	parser/Tick.h \
	$(NULL)


libblitzortungutilincludedir = $(includedir)/blitzortung/util
libblitzortungutilinclude_HEADERS = \
	util/RingBuffer.h \
	util/Size.h \
	util/String.h \
	util/Stream.h \
	$(NULL)
