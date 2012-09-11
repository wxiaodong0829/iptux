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
 */

#ifndef RECVFILEDATA_H
#define RECVFILEDATA_H

#include "mess.h"

class RecvFileData: public TransAbstract
{
public:
        RecvFileData(FileInfo *fl);
        ~RecvFileData();

        void RecvFileDataEntry();
        virtual GData **GetTransFilePara();
        virtual void TerminateTrans();
private:
        void CreateUIPara();
        void RecvRegularFile();
        void RecvDirFiles();

        int64_t RecvData(int sock, int fd, int64_t filesize, int64_t offset);
        void UpdateUIParaToOver();

        FileInfo *file;         //文件信息
        GData *para;            //UI参考数据
        bool terminate;         //终止标志(也作处理结果标识)
        int64_t sumsize;        //文件(目录)总大小
        char buf[MAX_SOCKLEN];  //数据缓冲区
        struct timeval tasktime, filetime;      //任务开始时间&文件开始时间
};

#endif
