/*
 * Copyright 2003-2022 The Music Player Daemon Project
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

#include "Tags.hxx"
#include "tag/Table.hxx"

const struct tag_table upnp_tags[] = {
	{ "upnp:artist", TAG_ARTIST },
	{ "upnp:album", TAG_ALBUM },
	{ "upnp:originalTrackNumber", TAG_TRACK },
	{ "upnp:genre", TAG_GENRE },
	{ "dc:title", TAG_TITLE },

	/* sentinel */
	{ nullptr, TAG_NUM_OF_ITEM_TYPES }
};
