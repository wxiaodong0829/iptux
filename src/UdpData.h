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

#ifndef UDPDATA_H
#define UDPDATA_H

#include "mess.h"

class UdpData {
public:
        UdpData();
        ~UdpData();

        static void UdpDataEntry(in_addr_t ipv4, const char buf[], size_t size);
private:
        void DispatchUdpData();

        void SomeoneLost();
        void SomeoneEntry();
        void SomeoneExit();
        void SomeoneAnsentry();
        void SomeoneAbsence();
        void SomeoneSendmsg();
        void SomeoneRecvmsg();
        void SomeoneAskShared();
        void SomeoneSendIcon();
        void SomeoneSendSign();
        void SomeoneBcstmsg();

        PalInfo *CreatePalInfo();
        void UpdatePalInfo(PalInfo *pal);

        void InsertMessage(PalInfo *pal, GroupBelongType btype, const char *msg);
        void ConvertEncode(const char *enc);
        char *GetPalGroup();
        char *GetPalIcon();
        char *GetPalEncode();
        char *RecvPalIcon();
        PalInfo *AssertPalOnline();
        void RecvPalFile();

        in_addr_t ipv4;                 //数据来自
        size_t size;                    //缓冲区数据有效长度
        char buf[MAX_UDPLEN];   //数据缓冲区
        char *encode;                   //原数据编码(NULL意味着utf8)
private:
        static void ThreadAskSharedPasswd(PalInfo *pal);
        static void ThreadAskSharedFile(PalInfo *pal);
};

#endif
