/* iptux
 * Copyright (C) 2009 Jally <jallyx@163.com>
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

#ifndef DIALOG_H
#define DIALOG_H

#include "mess.h"

bool pop_request_quit();
bool pop_request_shared_file(PalInfo *pal);
char *pop_obtain_shared_passwd(PalInfo *pal);
char *pop_password_settings(GtkWidget *parent);
char *pop_save_path(GtkWidget *parent);
#endif
