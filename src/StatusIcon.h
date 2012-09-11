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

#ifndef STATUSICON_H
#define STATUSICON_H

#include "mess.h"

class StatusIcon {
public:
        StatusIcon();
        ~StatusIcon();

        void CreateStatusIcon();
	gboolean IsEmbedded();
        void AlterStatusIconMode();
private:
        GtkStatusIcon *statusicon;
        guint timerid;
	gboolean embedded;
private:
        static gboolean UpdateUI(StatusIcon *sicon);
        static GtkWidget *CreatePopupMenu(GtkStatusIcon *statusicon);
//回调处理部分
private:
        static void ShowTransWindow();
        static void StatusIconActivate();
        static void PopupWorkMenu(GtkStatusIcon *statusicon, guint button, guint time);
        static gboolean StatusIconQueryTooltip(GtkStatusIcon *statusicon, gint x, gint y,
                                                 gboolean key, GtkTooltip *tooltip);
};

#endif
