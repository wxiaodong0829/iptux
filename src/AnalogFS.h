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
 *
 * Description:
 * 虚拟文件系统，接口函数使用方法尽量与库函数相同
 * 意义在于使用此类操作文件可保证多线程安全
 */

#ifndef ANALOGFS_H
#define ANALOGFS_H

#include "mess.h"

class AnalogFS {
public:
        AnalogFS();
        ~AnalogFS();

        int chdir(const char *dir);
        int open(const char *fn, int flags, ...);
        int stat(const char *fn, struct stat64 *st);
        int mkdir(const char *dir, mode_t mode);
        int64_t ftwsize(const char *dir);
        DIR *opendir(const char *dir);
private:
        int mergepath(char tpath[], const char *npath);

        char path[MAX_PATHLEN]; //当前工作路径
public:
        inline char* cwd() {
                        return path;
                }
};

#endif
