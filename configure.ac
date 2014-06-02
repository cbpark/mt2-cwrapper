#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([mt2_cwrapper], [0.1.0.0], [chanbeom.park@cern.ch])
AC_CONFIG_SRCDIR([src/Makefile.am])
AC_CONFIG_AUX_DIR([config])
AC_CONFIG_HEADERS([config/config.h])
AC_CONFIG_MACRO_DIR([m4])
# m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

# use the C++ compiler for the following checks
AC_LANG([C++])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
# Checks for programs.
AC_PROG_CXX([clang++ llvm-g++ g++])
AC_PROG_CC([clang llvm-gcc gcc])
AM_PROG_AR

# If you want static libraries, configure with --enable-static
AC_DISABLE_STATIC
AC_PROG_LIBTOOL

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([iostream])
AC_CHECK_HEADERS([vector])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.
AC_CHECK_FUNCS([pow sqrt fabs])

# If CXX is Clang, check that it can find and parse C++ standard library
# headers.
if $CXX -dM -E - < /dev/null | grep -q __clang__ ; then
   AC_MSG_RESULT([Using clang])
   clang='yes'
 else
   AC_MSG_RESULT([not using clang])
   clang='no'
fi

if test $clang = "yes"; then
  AC_MSG_CHECKING([whether clang works])
  AC_LANG_PUSH([C++])
  # Note that space between 'include' and '(' is required.  There's a broken
  # regex in aclocal that otherwise will think that we call m4's include
  # builtin.
  AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <limits>
#if __has_include (<cxxabi.h>)
#include <cxxabi.h>
#endif
#if __has_include (<unwind.h>)
#include <unwind.h>
#endif
]])],
[
  AC_MSG_RESULT([yes])
],
[
  AC_MSG_RESULT([no])
  AC_MSG_ERROR([Selected compiler could not find or parse C++ standard library headers. Rerun with CC=c-compiler CXX=c++-compiler ./configure ...])
])
  AC_LANG_POP([C++])

  # Add -Qunused-arguments to Clang compiler flags
  CXXFLAGS+=" -Qunused-arguments"
  LDFLAGS+=" -Qunused-arguments"
fi

# Add the ROOT libraries
AC_SUBST([ROOTDIR])
AC_SUBST([ROOT_CXXFLAGS])
AC_SUBST([ROOT_LDFLAGS])

AC_ARG_WITH([root],
    [AS_HELP_STRING([--with-root=DIR],
        [location of ROOT])],
    [rootPATHSET=1, ROOTDIR=$withval],
    [rootPATHSET=0])

if test $rootPATHSET = 0 ; then
   AC_MSG_ERROR([Cannot build without ROOT. Please set --with-root. You can also try --with-root=$ROOTSYS])
else
   AC_LANG_PUSH([C++])

   ROOT_CXXFLAGS="`${ROOTDIR}/bin/root-config --cflags`"
   CPPFLAGS+="${ROOT_CXXFLAGS}"
   ROOT_LDFLAGS="`${ROOTDIR}/bin/root-config --libs`"

   AC_CHECK_HEADER([Minuit2/MnSimplex.h],
   [ROOT_LDFLAGS="${ROOT_LDFLAGS} -lMinuit2"],
   [AC_MSG_ERROR([Your ROOT is not configured with Minuit2. Try to reinstall the ROOT with the option --enable-minuit2 or --all.])])

   AC_LANG_POP([C++])
fi

AC_CONFIG_FILES([Makefile
                 src/Makefile])

AC_OUTPUT
