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

#ifndef DEPLIB_H
#define DEPLIB_H

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#ifdef HAVE_GST
#include <gst/gst.h>
#endif

#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>
#undef _
#include <glib/gi18n.h>
#include <gconf/gconf-client.h>

#define ATOM_OBJECT 0xFFFC
#define OCCUPY_OBJECT 0x01
#define NULL_OBJECT 0x02
#define GINT(x) ((gint)(x))

#define GCONF_PATH "/apps/iptux"
#define IPTUX_PATH "/iptux"
#define LOG_PATH "/iptux/log"
#define PIC_PATH "/iptux/pic"
#define ICON_PATH "/iptux/icon"
#define PHOTO_PATH "/iptux/photo"

#ifndef _
#define _(string) gettext(string)
#endif

#endif
