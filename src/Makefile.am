AM_CXXFLAGS = -Wall -Wextra
AM_CFLAGS = -Wall -Wextra

bin_PROGRAMS = mt2test

lib_LTLIBRARIES = libmt2calculator.la

mt2test_SOURCES = mt2test.c
mt2test_LDADD = libmt2calculator.la

libmt2calculator_la_SOURCES = \
	mt2calculator.cc          \
	mt2calculator_c.cc
libmt2calculator_la_CXXFLAGS = @ROOT_CXXFLAGS@
libmt2calculator_la_LDFLAGS = @ROOT_LDFLAGS@

pkginclude_HEADERS =  \
	mt2calculator.h   \
	mt2calculator_c.h
