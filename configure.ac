dnl Process this file with autoconf to produce a configure script.

AC_INIT([libblitzortung],[1.3.0])

dnl Every other copy of the package version number gets its value from here
AM_INIT_AUTOMAKE([foreign])

AC_CONFIG_MACRO_DIR([m4])

dnl create a config.h file (Automake will add -DHAVE_CONFIG_H)
AC_CONFIG_HEADERS([config.h])

CXXFLAGS="${CXXFLAGS} -std=gnu++0x -pthread"
CXXFLAGS="${CXXFLAGS} -fsigned-char -Wall -Wextra -pedantic -Weffc++ -DBOOST_DATE_TIME_POSIX_TIME_STD_CONFIG"
AC_SUBST(CXXFLAGS)

BLITZORTUNG_LDFLAGS="-llog4cpp -ljson -lboost_regex"
AC_SUBST(BLITZORTUNG_LDFLAGS)

AC_PROG_CXX
# include libtool support
LT_INIT([pic-only, disable-static])

AC_LANG_PUSH([C++])
AC_CHECK_HEADERS([boost/date_time.hpp], [], [AC_MSG_ERROR(You need the boost date-time libraries)])
AC_CHECK_HEADERS([boost/regex.hpp], [], [AC_MSG_ERROR(You need the boost regex libraries)])
AC_CHECK_HEADERS([log4cpp/Category.hh], [], [AC_MSG_ERROR(You need the log4cpp libraries)])
AC_CHECK_HEADERS([cppunit/TestFixture.h], [], [AC_MSG_ERROR(You need the cppunit libraries)])
AC_CHECK_HEADERS([json/json.h], [], [AC_MSG_ERROR(You need the json-c libraries)])
AC_LANG_POP([C++])

AC_CONFIG_FILES([\
	Makefile \
        blitzortung.pc \
	source/Makefile \
	tests/Makefile
    ])

AC_OUTPUT
