# uninstall program
bin_PROGRAMS = ihateiptux
ihateiptux_SOURCES = ihateiptux.cpp utils.cpp

AM_CXXFLAGS = -Wall

# set the include path found by configure
AM_CPPFLAGS = $(PACKAGE_CFLAGS) -I$(top_srcdir)/include

# the library search path.
ihateiptux_LDFLAGS = $(all_libraries)

noinst_HEADERS = utils.h
