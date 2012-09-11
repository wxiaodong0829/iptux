/* iptux
 * Copyright (C) 2008 Jally <jallyx@163.com>
 * Copyright (C) 2012 cwll <cwll2009@126.com>
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

#ifndef DIALOGPEER_H
#define DIALOGPEER_H

#include "mess.h"
#include "DialogBase.h"

class DialogPeer: public DialogBase {
public:
        DialogPeer(GroupInfo *grp);
        virtual ~DialogPeer();

        static void PeerDialogEntry(GroupInfo *grpinf);

        virtual void UpdatePalData(PalInfo *pal);
        virtual void InsertPalData(PalInfo *pal);
        virtual void DelPalData(PalInfo *pal);
        virtual void ClearAllPalData();
        virtual GSList *GetSelPal();
        static void ShowDialogPeer(DialogPeer *dlgpr);
private:
        void ReadUILayout();
        void WriteUILayout();

        GtkWidget *CreateMainWindow();
        GtkWidget *CreateAllArea();

        GtkWidget *CreateMenuBar();
        GtkWidget *CreateInfoArea();
        GtkWidget *CreateFileArea();
        GtkWidget *CreateFileReceiveArea();
        GtkWidget *CreateFileToReceiveArea();
        GtkWidget *CreateFileReceivedArea();
        GtkWidget *CreateFileToReceiveTree(GtkTreeModel *model);
        GtkTreeModel *CreateFileToReceiveModel();
        GtkWidget *CreateFileReceivedTree(GtkTreeModel *model);
        GtkTreeModel *CreateFileReceivedModel();
        GtkWidget *CreateFileMenu();
        GtkWidget *CreateToolMenu();
        void FillPalInfoToBuffer(GtkTextBuffer *buffer, PalInfo *pal);

private:
        void BroadcastEnclosureMsg(GSList *list);
        bool SendTextMsg();
        void FeedbackMsg(const GSList *dtlist);
        MsgPara *PackageMsg(GSList *dtlist);
//回调处理部分
private:
        static void DragPicReceived(DialogPeer *dlgpr, GdkDragContext *context,
                                         gint x, gint y, GtkSelectionData *data,
                                         guint info, guint time);
        static void AskSharedFiles(GroupInfo *grpinf);
        static void InsertPicture(DialogPeer *dlgpr);
        static void DialogPeerDestroy(DialogPeer *dlgpr);
        static void ReceiveFile(DialogPeer *dlgpr);
        static void ThreadRecvFile(FileInfo *file);
        static void ShowInfoEnclosure(DialogPeer *dlgpr);
        static bool UpdataEnclosureRcvUI(DialogPeer *dlgpr);
        static void RemoveSelectedRcv(GtkWidget *widget);
        static gint RcvTreePopup(GtkWidget *treeview,GdkEvent *event);
//线程处理
private:
        static void ThreadSendTextMsg(MsgPara *para);
protected:
        int64_t torcvsize;  //总计待接收大小(包括已接收)
        int64_t rcvdsize;   //总计已接收大小
        guint timerrcv;     //接收文件界面更新计时器ID
};

#endif
