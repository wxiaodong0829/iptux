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


#include "CoreThread.h"
#include "RecvFile.h"
#include "RecvFileData.h"
#include "ProgramData.h"
#include "callback.h"
#include "utils.h"
extern ProgramData progdt;
extern CoreThread cthrd;

/**
 * 类构造函数.
 */
RecvFile::RecvFile()
{
}

/**
 * 类析构函数.
 */
RecvFile::~RecvFile()
{
}

/**
 * 文件接受入口.
 * @param para 文件参数
 */
void RecvFile::RecvEntry(GData *para)
{
        RecvFile *rfile;

        rfile = new RecvFile;
        rfile->ParseFilePara(&para);
        g_datalist_clear(&para);        //para提供的数据已经没用了，秒掉它
        delete rfile;//待接上文件的信息已存入中心节点可以删除了
}
/**
 * 分析文件参数.
 * @param para 文件参数
 */
void RecvFile::ParseFilePara(GData **para)
{
        PalInfo *pal;
        FileInfo *file;
        char *extra;
        uint32_t packetn;

        pal = (PalInfo *)g_datalist_get_data(para, "palinfo");
        extra = (char *)g_datalist_get_data(para, "extra-data");
        packetn = GPOINTER_TO_UINT(g_datalist_get_data(para, "packetno"));

        while (extra && *extra) {
                file = DivideFileinfo(&extra);
                file->packetn = packetn;
                file->fileown = pal;
                cthrd.PushItemToEnclosureList(file);
        }
}

/**
 * 从文件信息串中分离出文件信息数据.
 * @param extra 文件信息串
 * @return 文件信息数据
 */
FileInfo *RecvFile::DivideFileinfo(char **extra)
{
        FileInfo *file;

        file = new FileInfo;
        file->fileid = iptux_get_dec_number(*extra, ':', 0);
        file->fileattr = iptux_get_hex_number(*extra, ':', 4);
        file->filesize = iptux_get_hex64_number(*extra, ':', 2);
        file->filepath = ipmsg_get_filename(*extra, ':', 1);
        file->filectime = iptux_get_hex_number(*extra, ':', 3);
        file->finishedsize = 0;

        //分割，格式1(\a) 格式2(:\a) 格式3(\a:) 格式4(:\a:)
        *extra = strchr(*extra, '\a');
        if (*extra)     //跳过'\a'字符
                (*extra)++;
        if (*extra && (**extra == ':')) //跳过可能存在的':'字符
                (*extra)++;

        return file;
}
