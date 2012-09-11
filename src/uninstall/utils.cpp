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

#include "utils.h"
#include "sys.h"
#define MAX_PATHLEN 1024

void check_privileged()
{
        struct passwd *pw;

        pw = getpwnam("root");
        endpwent();
        if (pw && (pw->pw_uid != geteuid()))
                errx(1, _("The user is not privileged!\n"));
}

void remove_folder(const char *path)
{
        char buf[MAX_PATHLEN];
        struct stat st;
        struct dirent *dirt;
        DIR *dir;

        if (!(dir = opendir(path))) {
                warnx(_("Opendir() directory \"%s\" failed, %s\n"), path,
                                                         strerror(errno));
                return;
        }

        while ( (dirt = readdir(dir))) {
                if ((strcmp(dirt->d_name, ".") == 0)
                           || (strcmp(dirt->d_name, "..") == 0))
                        continue;
                snprintf(buf, MAX_PATHLEN, "%s/%s", path, dirt->d_name);
                if (stat(buf, &st) == -1) {
                        warnx(_("Stat() file \"%s\" failed, %s\n"), buf, strerror(errno));
                        continue;
                }

                if (S_ISLNK(st.st_mode) || S_ISREG(st.st_mode)) {
                        if (unlink(buf) == -1)
                                warnx(_("Unlink() file \"%s\" failed, %s\n"), buf,
                                                                 strerror(errno));
                }
                else if (S_ISDIR(st.st_mode)) {
                        remove_folder(buf);
                }
        }
        closedir(dir);

        if (rmdir(path) == -1)
                warnx(_("Rmdir() directory \"%s\" failed, %s\n"), buf, strerror(errno));
}

void remove_file(const char *path)
{
        if (unlink(path) == -1)
                warnx(_("Unlink() file \"%s\" failed, %s\n"), path, strerror(errno));
}
