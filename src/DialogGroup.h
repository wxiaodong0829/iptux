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

#ifndef DIALOGGROUP_H
#define DIALOGGROUP_H

#include "mess.h"
#include "DialogBase.h"

class DialogGroup: public DialogBase {
public:
        DialogGroup(GroupInfo *grp);
        virtual ~DialogGroup();

        static void GroupDialogEntry(GroupInfo *grpinf);

        virtual void UpdatePalData(PalInfo *pal);
        virtual void InsertPalData(PalInfo *pal);
        virtual void DelPalData(PalInfo *pal);
        virtual void ClearAllPalData();
        virtual GSList *GetSelPal();
private:
        virtual void InitSublayerSpecify();
        void ReadUILayout();
        void SaveUILayout();

        GtkWidget *CreateMainWindow();
        GtkWidget *CreateAllArea();

        GtkWidget *CreateMenuBar();
        GtkWidget *CreateMemberArea();
        GtkWidget *CreateInputArea();
        GtkWidget *CreateToolMenu();

        GtkTreeModel *CreateMemberModel();
        void FillMemberModel(GtkTreeModel *model);
        GtkWidget *CreateMemberTree(GtkTreeModel *model);

        bool SendTextMsg();

private:
        void BroadcastEnclosureMsg(GSList *list);
        void BroadcastTextMsg(const gchar *msg);

        static GtkWidget *CreatePopupMenu(GtkTreeModel *model);
//回调处理部分
private:
        static gint MemberTreeCompareByNameFunc(GtkTreeModel *model,
                                         GtkTreeIter *a, GtkTreeIter *b);
        static gint MemberTreeCompareByIPFunc(GtkTreeModel *model,
                                         GtkTreeIter *a, GtkTreeIter *b);
        static void SetMemberTreeSortFunc(GtkWidget *menuitem, GtkTreeModel *model);
        static void SetMemberTreeSortType(GtkWidget *menuitem, GtkTreeModel *model);
        static void DragDataReceived(DialogGroup *dlggrp, GdkDragContext *context,
                                         gint x, gint y, GtkSelectionData *data,
                                         guint info, guint time);
        static gboolean PopupPickMenu(GtkWidget *treeview, GdkEventButton *event);
        static void MembertreeItemActivated(GtkWidget *treeview, GtkTreePath *path,
                                                         GtkTreeViewColumn *column);
        static void SendMessage(DialogGroup *dlggrp);
};

#endif
