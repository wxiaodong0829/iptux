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

#ifndef SOUNDSYSTEM_H
#define SOUNDSYSTEM_H

#include "mess.h"

class SoundSystem {
public:
	SoundSystem();
	~SoundSystem();

	void InitSublayer();
	void AdjustVolume(double value);
	void Playing(const char *file);
	void Stop();
#ifdef HAVE_GST
private:
	 GData * eltset;	//元素集
	struct timeval timestamp;	//时间戳
	bool persist;		//声音系统占用标记
private:
	static void LinkElement(GData ** eltset, GstPad * pad);
	static void ErrorMessageOccur(SoundSystem * sndsys, GstMessage * message);
	static void EosMessageOccur(SoundSystem * sndsys);
#endif
};

#endif
