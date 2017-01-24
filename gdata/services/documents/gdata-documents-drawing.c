/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */
/*
 * GData Client
 * Copyright (C) Thibault Saunier 2009 <saunierthibault@gmail.com>
 * Copyright (C) Philip Withnall 2010 <philip@tecnocode.co.uk>
 * Copyright (C) Cosimo Cecchi 2012 <cosimoc@gnome.org>
 * Copyright (C) Red Hat, Inc. 2016
 *
 * GData Client is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * GData Client is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with GData Client.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * SECTION:gdata-documents-drawing
 * @short_description: GData Documents drawing object
 * @stability: Stable
 * @include: gdata/services/documents/gdata-documents-drawing.h
 *
 * #GDataDocumentsDrawing is a subclass of #GDataDocumentsDocument to represent a drawing document from Google Documents.
 *
 * For more details of Google Documents' GData API, see the
 * <ulink type="http" url="https://developers.google.com/google-apps/documents-list/">online documentation</ulink>.
 *
 * Since: 0.13.1
 */

#include <config.h>
#include <glib.h>

#include "gdata-documents-drawing.h"
#include "gdata-documents-utils.h"
#include "gdata-parser.h"
#include "gdata-private.h"

static void gdata_documents_drawing_constructed (GObject *object);

G_DEFINE_TYPE (GDataDocumentsDrawing, gdata_documents_drawing, GDATA_TYPE_DOCUMENTS_DOCUMENT)

static void
gdata_documents_drawing_class_init (GDataDocumentsDrawingClass *klass)
{
	GObjectClass *gobject_class = G_OBJECT_CLASS (klass);
	GDataEntryClass *entry_class = GDATA_ENTRY_CLASS (klass);

	gobject_class->constructed = gdata_documents_drawing_constructed;
	entry_class->kind_term = "http://schemas.google.com/docs/2007#drawing";
}

static void
gdata_documents_drawing_init (GDataDocumentsDrawing *self)
{
	/* Why am I writing it? */
}

static void
gdata_documents_drawing_constructed (GObject *object)
{
	G_OBJECT_CLASS (gdata_documents_drawing_parent_class)->constructed (object);

	if (!_gdata_parsable_is_constructed_from_xml (GDATA_PARSABLE (object)))
		gdata_documents_utils_add_content_type (GDATA_DOCUMENTS_ENTRY (object), "application/vnd.google-apps.drawing");
}

/**
 * gdata_documents_drawing_new:
 * @id: (allow-none): the entry's ID (not the document ID of the drawing document), or %NULL
 *
 * Creates a new #GDataDocumentsDrawing with the given entry ID (#GDataEntry:id).
 *
 * Return value: (transfer full): a new #GDataDocumentsDrawing, or %NULL; unref with g_object_unref()
 *
 * Since: 0.13.1
 */
GDataDocumentsDrawing *
gdata_documents_drawing_new (const gchar *id)
{
	return GDATA_DOCUMENTS_DRAWING (g_object_new (GDATA_TYPE_DOCUMENTS_DRAWING, "id", id, NULL));
}
