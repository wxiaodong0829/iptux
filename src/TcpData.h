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

#ifndef TCPDATA_H
#define TCPDATA_H

#include "mess.h"

class TcpData {
public:
        TcpData();
        ~TcpData();

        static void TcpDataEntry(int sock);
private:
        void DispatchTcpData();

        void RequestData(uint32_t fileattr);
        void RecvSublayer(uint32_t cmdopt);

        void RecvSublayerData(int fd, size_t len);
        void RecvPhotoPic(PalInfo *pal, const char *path);
        void RecvMsgPic(PalInfo *pal, const char *path);

        int sock;       //数据交流套接口
        size_t size;    //缓冲区已使用长度
        char buf[MAX_SOCKLEN];  //缓冲区
};

#endif
