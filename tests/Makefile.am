
AM_CPPFLAGS = \
	-I$(top_srcdir) \
	-I$(top_srcdir)/source \
	-I$(top_srcdir)/source/lib \
	$(DEBUG_CPPFLAGS) 

AM_LDFLAGS = \
	$(top_srcdir)/source/libblitzortung.la \
	-lboost_program_options \
	-lcppunit

noinst_PROGRAMS = \
	test-lib \
	$(NULL)

test_lib_SOURCES = \
	test-lib.cc \
	test-lib-data-events.cc test-lib-data-events.h \
	test-lib-data-events-2_1_8.cc test-lib-data-events-2_1_8.h \
	test-lib-data-events-2_1_12.cc test-lib-data-events-2_1_12.h \
	test-lib-data-events-2_64_8.cc test-lib-data-events-2_64_8.h \
	test-lib-data-events-2_256_8.cc test-lib-data-events-2_256_8.h \
	test-lib-data-events-1_128_8.cc test-lib-data-events-1_128_8.h \
	test-lib-data-format.cc test-lib-data-format.h \
	test-lib-data-waveform.cc test-lib-data-waveform.h \
	test-lib-data-arrayof.cc test-lib-data-arrayof.h \
	$(NULL)

