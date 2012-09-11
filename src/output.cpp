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

#include "output.h"
#include "sys.h"

/**
 * 弹出消息提示.
 * @param parent parent window
 * @param format as in printf()
 * @param ...
 */
void pop_info(GtkWidget *parent, const gchar *format, ...)
{
        GtkWidget *dialog;
        gchar *msg;
        va_list ap;

        va_start(ap, format);
        msg = g_strdup_vprintf(format, ap);
        va_end(ap);
        dialog = gtk_message_dialog_new(GTK_WINDOW(parent),
                         GTK_DIALOG_MODAL,  GTK_MESSAGE_INFO,
                         GTK_BUTTONS_OK, NULL);
        gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(dialog), msg);
        g_free(msg);
        gtk_window_set_title(GTK_WINDOW(dialog), _("Infomation"));
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
}

/**
 * 弹出警告信息.
 * @param parent parent window
 * @param format as in printf()
 * @param ...
 */
void pop_warning(GtkWidget *parent, const gchar *format, ...)
{
        GtkWidget *dialog;
        gchar *msg;
        va_list ap;

        va_start(ap, format);
        msg = g_strdup_vprintf(format, ap);
        va_end(ap);
        dialog = gtk_message_dialog_new(GTK_WINDOW(parent),
                         GTK_DIALOG_MODAL, GTK_MESSAGE_INFO,
                         GTK_BUTTONS_OK, NULL);
        gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(dialog), msg);
        g_free(msg);
        gtk_window_set_title(GTK_WINDOW(dialog), _("Warning"));
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
}

/**
 * 严重错误，程序将有可能自行强制退出.
 * @param format as in printf()
 * @param ...
 */
void pop_error(const gchar *format, ...)
{
        GtkWidget *dialog;
        gchar *msg;
        va_list ap;

        va_start(ap, format);
        msg = g_strdup_vprintf(format, ap);
        va_end(ap);
        dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL,
                         GTK_MESSAGE_INFO, GTK_BUTTONS_OK, NULL);
        gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(dialog), msg);
        g_free(msg);
        gtk_window_set_title(GTK_WINDOW(dialog), _("Error"));
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
}

