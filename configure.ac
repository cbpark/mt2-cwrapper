#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([mt2_cwrapper], [0.1.0.0], [cbpark@gmail.com])
AC_CONFIG_SRCDIR([src/Makefile.am])
AC_CONFIG_AUX_DIR([config])
AC_CONFIG_HEADERS([config/config.h])
AC_CONFIG_MACRO_DIR([m4])
# m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

# Checks for programs.
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_PROG_CXX([clang++ llvm-g++ g++])
AC_PROG_CC([clang llvm-gcc gcc])
AC_LANG([C++], [C])
AX_CXX_COMPILE_STDCXX_11(noext,mandatory)
AC_PROG_INSTALL
AM_PROG_AR
LT_INIT

# Adds flags for clang.
if test "$CXX" = "clang++"; then
   CXXFLAGS="${CXXFLAGS} -stdlib=libc++"
fi

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([vector])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.

# Adds ROOT libraries.
AC_SUBST([ROOTDIR])
AC_SUBST([ROOT_CXXFLAGS])
AC_SUBST([ROOT_LDFLAGS])

AC_ARG_WITH([root], [AS_HELP_STRING([--with-root=DIR], [location of ROOT])],
            [rootPATHSET=1, ROOTDIR=$withval],
            [rootPATHSET=0])

if test $rootPATHSET = 0; then
   AC_MSG_ERROR([It cannot be built without ROOT. Please set --with-root. You may try --with-root=$ROOTSYS])
else
   AC_LANG_PUSH([C++])

   ROOT_CXXFLAGS="`${ROOTDIR}/bin/root-config --cflags`"
   ROOT_LDFLAGS="`${ROOTDIR}/bin/root-config --libs`"

   AC_LANG(C++)
   SAVED_CXXFLAGS=$CXXFLAGS
   CXXFLAGS="$CXXFLAGS $ROOT_CXXFLAGS"
   SAVED_CPPFLAGS=$CPPFLAGS
   CPPFLAGS="$CPPFLAGS $ROOT_CXXFLAGS"
   AC_CHECK_HEADER([Minuit2/MnSimplex.h], [ROOT_LDFLAGS="${ROOT_LDFLAGS} -lMinuit2"],
                   [AC_MSG_ERROR([Your ROOT is not configured with Minuit.])])
   CXXFLAGS=$SAVED_CXXFLAGS
   CPPFLAGS=$SAVED_CPPFLAGS

   AC_LANG_POP([C++])
fi

AC_CONFIG_FILES([Makefile
                 src/Makefile])

AC_OUTPUT
