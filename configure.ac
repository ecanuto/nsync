AC_PREREQ(2.61)
AC_INIT([nsync],[0.1.0])
AM_INIT_AUTOMAKE([1.11 subdir-objects foreign dist-xz no-dist-gzip])

AC_CONFIG_SRCDIR([src/nsyncd.c])
AC_CONFIG_HEADERS([config.h])

AC_PROG_CC
AC_PROG_INSTALL

AC_CHECK_LIB(pthread, pthread_create, PTHREAD_LIBS="-lpthread")
AC_SUBST(PTHREAD_LIBS)

AC_SUBST(PACKAGE_CFLAGS)
AC_SUBST(PACKAGE_LIBS)

AC_CONFIG_FILES([Makefile])

AC_OUTPUT