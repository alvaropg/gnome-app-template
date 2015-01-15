/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 8; tab-width: 8 -*- */
/*
 * App
 * Copyright © 2015 Your name <yourname@yoursite.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#ifndef __APP_APPLICATION_H__
#define __APP_APPLICATION_H__

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define APP_TYPE_APPLICATION             (app_application_get_type())
#define APP_APPLICATION(obj)             (G_TYPE_CHECK_INSTANCE_CAST((obj),APP_TYPE_APPLICATION,AppApplication))
#define APP_APPLICATION_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST((klass),APP_TYPE_APPLICATION,AppApplicationClass))
#define APP_IS_APPLICATION(obj)          (G_TYPE_CHECK_INSTANCE_TYPE((obj),APP_TYPE_APPLICATION))
#define APP_IS_APPLICATION_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE((klass),APP_TYPE_APPLICATION))
#define APP_APPLICATION_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS((obj),APP_TYPE_APPLICATION,AppApplicationClass))

typedef struct _AppApplication        AppApplication;
typedef struct _AppApplicationClass   AppApplicationClass;
typedef struct _AppApplicationPrivate AppApplicationPrivate;

struct _AppApplication {
        GtkApplication parent;

        AppApplicationPrivate *priv;
};

struct _AppApplicationClass {
        GtkApplicationClass parent_class;
};

GType app_application_get_type (void) G_GNUC_CONST;

GtkApplication* app_application_new (void);

G_END_DECLS

#endif /* __APP_APPLICATION_H__ */
