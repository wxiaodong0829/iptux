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

#ifndef SUPPORT_H
#define SUPPORT_H

#include "mess.h"

void iptux_init();
void iptux_gui_quit();
void iptux_quit();

void analysis_parameter(int argc, char *const argv[]);
void print_version();
void print_usage();
void print_stun();

void iptux_open_url(const char *url);
void bind_iptux_port();
void init_iptux_environment();

void pixbuf_shrink_scale_1(GdkPixbuf ** pixbuf, int width, int height);
GdkPixbuf *obtain_pixbuf_from_stock(const gchar * stock_id);

void widget_enable_dnd_uri(GtkWidget * widget);
GSList *selection_data_get_path(GtkSelectionData * data);

char *ipv4_get_lan_name(in_addr_t ipv4);

void socket_enable_broadcast(int sock);
void socket_enable_reuse(int sock);
GSList *get_sys_broadcast_addr(int sock);
GSList *get_sys_host_addr(int sock);
char *get_sys_host_addr_string(int sock);

#endif
