AUTOMAKE_OPTIONS = subdir-objects

AM_LDFLAGS = \
	$(NULL)

lib_LTLIBRARIES = libblitzortung.la

libblitzortung_la_LDFLAGS = \
	-llog4cpp \
	-ljson \
	-lboost_regex \
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
	\
	exception/Base.h exception/Base.cc \
	\
	Logger.h Logger.cc \
	\
	namespace.h \
	\
	ipc/UnixSocket.h ipc/UnixSocket.cc \
	ipc/Listener.h ipc/Listener.cc \
	ipc/Queue.h ipc/Queue.cc \
	ipc/server/Base.h ipc/server/Base.cc \
	ipc/server/factory/Base.h ipc/server/factory/Base.cc \
	ipc/server/Json.h ipc/server/Json.cc \
	ipc/server/factory/Json.h ipc/server/factory/Json.cc \
	\
	util/RingBuffer.h util/RingBuffer.cc \
	util/Size.h \
	util/String.h util/String.cc \
	util/Stream.h \
	\
	$(NULL)

