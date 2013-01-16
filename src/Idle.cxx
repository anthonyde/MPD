/*
 * Copyright (C) 2003-2013 The Music Player Daemon Project
 * http://www.musicpd.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/*
 * Support library for the "idle" command.
 *
 */

#include "config.h"
#include "Idle.hxx"
#include "GlobalEvents.hxx"

#include <atomic>

#include <assert.h>

static std::atomic_uint idle_flags;

static const char *const idle_names[] = {
	"database",
	"stored_playlist",
	"playlist",
	"player",
	"mixer",
	"output",
	"options",
	"sticker",
	"update",
	"subscription",
	"message",
	nullptr
};

void
idle_add(unsigned flags)
{
	assert(flags != 0);

	unsigned old_flags = idle_flags.fetch_or(flags);

	if ((old_flags & flags) != flags)
		GlobalEvents::Emit(GlobalEvents::IDLE);
}

unsigned
idle_get(void)
{
	return idle_flags.fetch_and(0);
}

const char*const*
idle_get_names(void)
{
        return idle_names;
}
