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

#ifndef SHAREFILE_H
#define SHAREFILE_H

#include "mess.h"

class ShareFile {
public:
	ShareFile();
	~ShareFile();

	static void ShareEntry(GtkWidget * parent);
private:
	void InitSublayer();
	void ClearSublayer();

	GtkWidget *CreateMainDialog(GtkWidget * parent);
	GtkWidget *CreateAllArea();

	GtkTreeModel *CreateFileModel();
	void FillFileModel(GtkTreeModel * model);
	GtkWidget *CreateFileTree(GtkTreeModel * model);

	void ApplySharedData();
	void AttachSharedFiles(GSList * list);
	GSList *PickSharedFile(uint32_t fileattr);

	GData *widset;
	GData *mdlset;
//回调处理部分
private:
	static void AddRegular(ShareFile * sfile);
	static void AddFolder(ShareFile * sfile);
	static void DeleteFiles(GData ** widset);
	static void SetPassword(GData ** widset);
	static void ClearPassword(GData ** widset);

	static void DragDataReceived(ShareFile * sfile, GdkDragContext * context,
				     gint x, gint y, GtkSelectionData * data,
				     guint info, guint time);
	static gint FileTreeCompareFunc(GtkTreeModel * model, GtkTreeIter * a,
					GtkTreeIter * b);
};

#endif
