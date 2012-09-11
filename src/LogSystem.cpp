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

#include "LogSystem.h"
#include "ProgramData.h"
#include "utils.h"
extern ProgramData progdt;

#define LOG_START_HEADER "====================================="
#define LOG_END_HEADER   "-------------------------------------"

LogSystem::LogSystem():fdc(-1), fds(-1)
{
}

LogSystem::~LogSystem()
{
	close(fdc);
	close(fds);
}

void LogSystem::InitSublayer()
{
	const gchar *env;
	char path[MAX_PATHLEN];

	env = g_get_user_config_dir();
	snprintf(path, MAX_PATHLEN, "%s" LOG_PATH "/communicate.log", env);
	fdc = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	snprintf(path, MAX_PATHLEN, "%s" LOG_PATH "/system.log", env);
	fds = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
}

void LogSystem::CommunicateLog(MsgPara * msgpara, const char *fmt, ...)
{
	gchar *log, *msg, *ptr;
	va_list ap;

	if (!FLAG_ISSET(progdt.flags, 2))
		return;

	PalInfo *pal = msgpara->pal;

	if (msgpara->stype == MESSAGE_SOURCE_TYPE_PAL)
		ptr = getformattime(TRUE, _("Recevied-From: Nickname:%s User:%s Host:%s"),
				    pal->name, pal->user, pal->host);
	else if (msgpara->stype == MESSAGE_SOURCE_TYPE_SELF) {
		if (msgpara->pal)
			ptr =
			    getformattime(TRUE, _("Send-To: Nickname:%s User:%s Host:%s"),
					  pal->name, pal->user, pal->host);
		else
			ptr = getformattime(TRUE, _("Send-Broadcast"));
	} else
		return;

	va_start(ap, fmt);
	msg = g_strdup_vprintf(fmt, ap);
	va_end(ap);
	log = g_strdup_printf("%s\n%s\n%s\n%s\n\n", LOG_START_HEADER,
			      ptr, msg, LOG_END_HEADER);
	write(fdc, log, strlen(log));
	g_free(log);
	g_free(ptr);
	g_free(msg);
}

void LogSystem::SystemLog(const char *fmt, ...)
{
	gchar *log, *msg, *ptr;
	va_list ap;

	if (!FLAG_ISSET(progdt.flags, 2))
		return;

	ptr =
	    getformattime(TRUE, _("User:%s Host:%s"), g_get_user_name(),
			  g_get_host_name());
	va_start(ap, fmt);
	msg = g_strdup_vprintf(fmt, ap);
	va_end(ap);
	log = g_strdup_printf("%s\n%s\n%s\n%s\n\n", LOG_START_HEADER,
			      ptr, msg, LOG_END_HEADER);
	g_free(ptr);
	g_free(msg);

	write(fds, log, strlen(log));
	g_free(log);
}
