AC_INIT([seabattle], [0.5])
AM_INIT_AUTOMAKE([-Wall -Werror])

AC_CONFIG_SRCDIR([src/main.c])
AC_PROG_CC
AM_PROG_CC_C_O

AM_CONFIG_HEADER(config.h)
AC_CHECK_HEADERS(ncurses.h)
AC_CHECK_LIB(ncurses, wclear)

AC_PREFIX_DEFAULT([/tmp/seabattle])

AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
