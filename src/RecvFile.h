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
 *
 * 把文件接收确认和选择放在了聊天窗口，所以这个类的大部分功能都不用了
 */

#ifndef RECVFILE_H
#define RECVFILE_H

#include "mess.h"

class RecvFile {
public:
        RecvFile();
        ~RecvFile();
        static void RecvEntry(GData *para);
private:
        void ParseFilePara(GData **para);
        FileInfo *DivideFileinfo(char **extra);
};

#endif
