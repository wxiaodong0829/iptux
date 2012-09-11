# iptux
# Copyright (C) 2012 Wanlong Gao <gaowanlong@cn.fujitsu.com>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

AUTOMAKE_OPTIONS = foreign 1.4

SUBDIRS = src desktop pixmaps po sound

EXTRA_DIST = Makefile.cvs protocol style

# When doing 'make dist' update a few files automatically
dist-hook:
	git log --pretty="format:%an <%ae>" | sort -u | uniq -w 10 > AUTHORS-t
	mv AUTHORS-t AUTHORS
