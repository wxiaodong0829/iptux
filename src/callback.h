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
 *
 * Description:
 *   UI and callback functions.
 */

#ifndef CALLBACK_H
#define CALLBACK_H

#include "mess.h"

/* interface mode */
gboolean alter_interface_mode();

/* entry */
gboolean entry_query_tooltip(GtkWidget * entry, gint x, gint y,
			     gboolean key, GtkTooltip * tooltip, char *text);
void entry_insert_numeric(GtkWidget * entry, gchar * text, gint length);

/* file-chooser */
gchar *choose_file_with_preview(const gchar * title, GtkWidget * parent);
void chooser_update_preview(GtkFileChooser * chooser, GtkWidget * preview);

/* model:0 G_TYPE_BOOLEAN */
void model_select_all(GtkTreeModel * model);
void model_turn_all(GtkTreeModel * model);
void model_clear_all(GtkTreeModel * model);
void model_turn_select(GtkTreeModel * model, gchar * path);

/* text view link */
void textview_follow_if_link(GtkWidget * textview, GtkTextIter * iter);
void textview_set_cursor_if_appropriate(GtkTextView * textview, gint x, gint y);
gboolean textview_key_press_event(GtkWidget * textview, GdkEventKey * event);
void textview_event_after(GtkWidget * textview, GdkEvent * ev);
gboolean textview_motion_notify_event(GtkWidget * textview, GdkEventMotion * event);
gboolean textview_visibility_notify_event(GtkWidget * textview,
					  GdkEventVisibility * event);

#endif
