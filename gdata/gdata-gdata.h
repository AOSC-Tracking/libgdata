/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */
/*
 * GData Client
 * Copyright (C) Philip Withnall 2009 <philip@tecnocode.co.uk>
 * 
 * GData Client is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GData Client is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GData Client.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <glib.h>

#ifndef GDATA_GDATA_H
#define GDATA_GDATA_H

G_BEGIN_DECLS

typedef struct {
	guint min;
	guint max;
	guint num_raters;
	gdouble average;
} GDataGDRating;

GDataGDRating *gdata_gd_rating_new (guint min, guint max, guint num_raters, gdouble average);
void gdata_gd_rating_free (GDataGDRating *self);

typedef struct {
	gchar *rel;
	gchar *href;
	guint count_hint;
} GDataGDFeedLink;

GDataGDFeedLink *gdata_gd_feed_link_new (const gchar *href, const gchar *rel, guint count_hint);
void gdata_gd_feed_link_free (GDataGDFeedLink *self);

G_END_DECLS

#endif /* !GDATA_GDATA_H */
