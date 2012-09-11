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

#ifndef OUTPUT_H
#define OUTPUT_H

#include "deplib.h"

/* 警告信息输出 */
#ifndef WARNING
#define pwarning(format,...) /*warnx(format,##__VA_ARGS__)*/
#else
#define pwarning(format,...) warnx(format,##__VA_ARGS__)
#endif

/* 常规消息输出 */
#ifndef MESSAGE
#define pmessage(format,...) /*printf(format,##__VA_ARGS__)*/
#else
#define pmessage(format,...) printf(format,##__VA_ARGS__)
#endif

/* 程序执行踪迹输出，用于调试 */
#ifndef TRACE
#define ptrace(format,...) /*printf(format,##__VA_ARGS__)*/
#else
#define ptrace(format,...) printf(format,##__VA_ARGS__)
#endif

void pop_info(GtkWidget *parent, const gchar *format, ...);
void pop_warning(GtkWidget *parent, const gchar *format, ...);
void pop_error(const gchar *format, ...);

#endif
