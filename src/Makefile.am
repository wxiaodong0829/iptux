# main program
bin_PROGRAMS = iptux
iptux_SOURCES = AnalogFS.cpp Command.cpp CoreThread.cpp DataSettings.cpp \
	DetectPal.cpp DialogBase.cpp DialogGroup.cpp DialogPeer.cpp HelpDialog.cpp LogSystem.cpp \
	MainWindow.cpp ProgramData.cpp RecvFile.cpp RecvFileData.cpp RevisePal.cpp \
	SendFile.cpp SendFileData.cpp ShareFile.cpp SoundSystem.cpp StatusIcon.cpp \
	TcpData.cpp UdpData.cpp callback.cpp dialog.cpp iptux.cpp mess.cpp output.cpp \
	support.cpp utils.cpp wrapper.cpp

AM_CXXFLAGS = -Wall

# set the include path found by configure
AM_CPPFLAGS = $(PACKAGE_CFLAGS) -I$(top_srcdir)/include

# the library search path.
iptux_LDADD = $(INTLLIBS) @PACKAGE_LIBS@
LIBS = $(all_libraries)

SUBDIRS = uninstall
