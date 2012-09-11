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

#include "ProgramData.h"
#include "CoreThread.h"
#include "StatusIcon.h"
#include "MainWindow.h"
#include "LogSystem.h"
#include "SoundSystem.h"
#include "support.h"
ProgramData progdt;
CoreThread cthrd;
StatusIcon sicon;
MainWindow mwin;
LogSystem lgsys;
SoundSystem sndsys;

int main(int argc, char *argv[])
{
        setlocale(LC_ALL, "");
        bindtextdomain(GETTEXT_PACKAGE, __LOCALE_PATH);
        bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF-8");
        textdomain(GETTEXT_PACKAGE);

        if (!g_thread_supported())
                g_thread_init(NULL);
        gdk_threads_init();
        gdk_threads_enter();
        gtk_init(&argc, &argv);

        analysis_parameter(argc, argv);
        iptux_init();
        sicon.CreateStatusIcon();
        mwin.CreateWindow();
        cthrd.CoreThreadEntry();

        gtk_main();
        gdk_threads_leave();
        return 0;
}
