/* iptux
 * Copyright (C) 2008 Jally <jallyx@163.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef SYS_H
#define SYS_H

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

/* <stdint.h> */
#define __STDC_LIMIT_MACROS
/* <inttypes.h> */
#define __STDC_FORMAT_MACROS

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <err.h>
#include <time.h>
#include <iconv.h>
#include <ctype.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/queue.h>
#include <fcntl.h>
#include <dirent.h>
#include <ftw.h>
#include <signal.h>
#include <sys/vfs.h>
#include <pwd.h>
#include <getopt.h>
#include <locale.h>
#include <libintl.h>

#ifndef _
#define _(string) gettext(string)
#endif

#endif
