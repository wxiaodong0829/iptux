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

#include "mess.h"
#include "utils.h"

PalInfo::PalInfo():ipv4(0), segdes(NULL), version(NULL), user(NULL), host(NULL),
 name(NULL), group(NULL), photo(NULL), sign(NULL), iconfile(NULL), encode(NULL),
 flags(0), packetn(0), rpacketn(0)
{}
PalInfo::~PalInfo()
{
        g_free(segdes);
        g_free(version);
        g_free(user);
        g_free(host);
        g_free(name);
        g_free(group);
        g_free(photo);
        g_free(sign);
        g_free(iconfile);
        g_free(encode);
}

GroupInfo::GroupInfo():grpid(0), type(GROUP_BELONG_TYPE_REGULAR), name(NULL),
 member(NULL), buffer(NULL), dialog(NULL)
{}
GroupInfo::~GroupInfo()
{
        g_free(name);
        g_slist_free(member);
        g_object_unref(buffer);
}

FileInfo::FileInfo():fileid(0), packetn(0), fileattr(0), filesize(-1),
    finishedsize(0),fileown(NULL), filepath(NULL)
{}
FileInfo::~FileInfo()
{
        g_free(filepath);
}

MsgPara::MsgPara():pal(NULL), stype(MESSAGE_SOURCE_TYPE_PAL),
 btype(GROUP_BELONG_TYPE_REGULAR), dtlist(NULL)
{}
MsgPara::~MsgPara()
{
        for (GSList *tlist = dtlist; tlist; tlist = g_slist_next(tlist))
                delete (ChipData *)tlist->data;
        g_slist_free(dtlist);
}

ChipData::ChipData():type(MESSAGE_CONTENT_TYPE_STRING), data(NULL)
{}
ChipData::~ChipData()
{
        g_free(data);
}

NetSegment::NetSegment():startip(NULL), endip(NULL), description(NULL)
{}
NetSegment::~NetSegment()
{
        g_free(startip);
        g_free(endip);
        g_free(description);
}

SessionAbstract::SessionAbstract()
{}
SessionAbstract::~SessionAbstract()
{}

TransAbstract::TransAbstract()
{}
TransAbstract::~TransAbstract()
{}
