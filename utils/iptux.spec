Name:		iptux
Version:	1.0
Release:	0%{?dist}
Summary:	A software for communication in LAN
Summary(zh_CN):	一款局域网即时通讯与文件分享软件
Packager:	Wanlong Gao <gaowanlong@cn.fujitsu.com>
License:	GPLv2+
URL:		https://github.com/gaowanlong/iptux
Source:		https://github.com/downloads/gaowanlong/iptux/%{name}-%{version}.tar.bz2
%if 0%{?suse_version}
Group:		Productivity/Networking/Talk/Clients
BuildRequires:	dbus-1-devel , gconf2-devel , gtk2-devel , desktop-file-utils , gettext , gstreamer-devel , gcc , gcc-c++ , update-desktop-files
%else
Group:		Applications/Internet
BuildRequires:	dbus-devel , GConf2-devel , gtk2-devel , desktop-file-utils , gettext , gstreamer-devel , gcc , gcc-c++
%endif
BuildRoot:      %{_tmppath}/%{name}-%{version}-%{release}

%description
A software for sharing and transporting files and directories in LAN.
It is written by C++ and the skin is designed by Gtk. Iptux is based
on ipmsg, so you can use it send files to a Windows PC which has an
ipmsg Windows edition in LAN.

%description -l zh_CN
Iptux 是一款采用 GTK+ 编写的开源局域网即时通讯与文件分享软件，兼容 Windows
平台下的飞鸽传书协议，具有自动识别编码字符集的功能。另外还实现文件夹共享的功能,
更加方便局域网好友之间的数据分享。

%package ihateiptux
Summary:	The uninstaller of %{name}
Summary(zh_CN):	用于卸载 %{name} 的程序
%if 0%{?suse_version}
Group:		Productivity/Networking/Talk/Clients
%else
Group:		Applications/Internet
%endif
Requires:	%{name} = %{version}-%{release}

%description ihateiptux
The uninstaller of iptux. Is there anyone who can tell me a reason to install it?

%description ihateiptux -l zh_CN
Iptux 的卸载程序。不知道谁可以给我一个安装它的理由~


%prep
%setup -q -n %{name}-%{version}
sed -i "s/@PACKAGE_LIBS@//g" src/Makefile.am
sed -i '16i\iptux_LDADD = $(INTLLIBS) @PACKAGE_LIBS@' src/Makefile.am

%build
%configure
make %{?_smp_mflags}

%install
make install DESTDIR=$RPM_BUILD_ROOT INSTALL="install -p"
%find_lang %{name}
%if 0%{?suse_version}
%suse_update_desktop_file iptux InstantMessaging
%else
desktop-file-install \
  --delete-original \
  --dir ${RPM_BUILD_ROOT}/%{_datadir}/applications \
  ${RPM_BUILD_ROOT}/%{_datadir}/applications/%{name}.desktop
%endif

%clean
rm -rf $RPM_BUILD_ROOT

%files -f %{name}.lang
%defattr(-,root,root,-)
%doc AUTHORS ChangeLog README style
%{_bindir}/%{name}
%{_bindir}/ihate%{name}
%{_datadir}/applications/iptux.desktop
%{_datadir}/%{name}/
%{_datadir}/icons/hicolor/64x64/apps/i-tux.png
%{_datadir}/icons/hicolor/64x64/apps/ip-tux.png
%{_datadir}/icons/hicolor/48x48/apps/i-tux.png
%{_datadir}/icons/hicolor/48x48/apps/ip-tux.png
%{_datadir}/icons/hicolor/32x32/apps/i-tux.png
%{_datadir}/icons/hicolor/32x32/apps/ip-tux.png
%{_datadir}/icons/hicolor/24x24/apps/i-tux.png
%{_datadir}/icons/hicolor/24x24/apps/ip-tux.png
%{_datadir}/icons/hicolor/22x22/apps/i-tux.png
%{_datadir}/icons/hicolor/22x22/apps/ip-tux.png
%{_datadir}/icons/hicolor/16x16/apps/i-tux.png
%{_datadir}/icons/hicolor/16x16/apps/ip-tux.png

%changelog
* Thu Sep 10 2012 Wanlong Gao <gaowanlong@cn.fujitsu.com> - initial
