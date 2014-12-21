AM_CXXFLAGS = -Wall -Wextra
AM_CFLAGS = -Wall -Wextra

bin_PROGRAMS = mt2test

lib_LTLIBRARIES = libMT2Calculator.la

mt2test_SOURCES = mt2test.c
mt2test_LDADD = libMT2Calculator.la

libMT2Calculator_la_SOURCES = \
	MT2Calculator.cc          \
	MT2Calculator_c.cc
libMT2Calculator_la_CXXFLAGS = @ROOT_CXXFLAGS@
libMT2Calculator_la_LDFLAGS = @ROOT_LDFLAGS@

pkginclude_HEADERS =  \
	MT2Calculator.h   \
	MT2Calculator_c.h
