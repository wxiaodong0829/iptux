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

#ifndef HelpDialog_H
#define HelpDialog_H

#include "deplib.h"

class HelpDialog {
public:
        HelpDialog();
        ~HelpDialog();

        static void AboutEntry();
        static void MoreEntry();
private:
        GtkWidget *CreateAboutDialog();
        GtkWidget *CreateMoreDialog();
        void RunHelpDialog(GtkWidget **dialog);

        static GtkWidget *about;
        static GtkWidget *more;
//回调处理部分
private:
        static void DialogOpenEmail(GtkWidget *dialog, const gchar *link);
        static void DialogOpenUrl(GtkWidget *dialog, const gchar *link);
        static void DialogDestroy(GtkWidget **dialog);
};

#endif
