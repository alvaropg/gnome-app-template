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

#include <gio/gio.h>
#include <glib/gi18n.h>

#include <config.h>

#include "application.h"
#include "application-window.h"
#include "utils.h"

static void app_application_constructed (GObject *object);
static void app_application_dispose     (GObject *object);
static void app_application_finalize    (GObject *object);
static void app_application_activate    (GApplication *application);
static void app_application_startup     (GApplication *application);

static void app_application_about_activated (GSimpleAction *action,
                                             GVariant      *parameter,
                                             gpointer       user_data);
static void app_application_quit_activated (GSimpleAction *action,
                                            GVariant      *parameter,
                                            gpointer       user_data);

struct _AppApplicationPrivate {
        GtkWidget *window;
        guint32 activation_timestamp;
};

G_DEFINE_TYPE_WITH_CODE (AppApplication, app_application, GTK_TYPE_APPLICATION, G_ADD_PRIVATE (AppApplication));

static GActionEntry app_entries[] =
{
        { "about", app_application_about_activated, NULL, NULL, NULL },
        { "quit", app_application_quit_activated, NULL, NULL, NULL }
};

static void
app_application_class_init (AppApplicationClass *klass)
{
        GObjectClass *object_class = G_OBJECT_CLASS (klass);
        GApplicationClass *application_class = G_APPLICATION_CLASS (klass);

        object_class->constructed = app_application_constructed;
        object_class->dispose = app_application_dispose;
        object_class->finalize = app_application_finalize;

        application_class->activate = app_application_activate;
        application_class->startup = app_application_startup;
}

static void
app_application_init (AppApplication *self)
{
        self->priv = app_application_get_instance_private(self);

        self->priv->window = NULL;
        self->priv->activation_timestamp = GDK_CURRENT_TIME;
}

static void
app_application_constructed (GObject *object)
{
        g_application_set_application_id (G_APPLICATION (object), "org.gnome." PACKAGE_NAME);

        G_OBJECT_CLASS (app_application_parent_class)->constructed (object);
}

static void
app_application_dispose (GObject *object)
{
        AppApplication *self = APP_APPLICATION (object);

        G_OBJECT_CLASS (app_application_parent_class)->dispose (object);
}

static void
app_application_finalize (GObject *object)
{
        AppApplication *self = APP_APPLICATION (object);

        G_OBJECT_CLASS (app_application_parent_class)->finalize (object);
}

static void
app_application_activate (GApplication *application)
{
        AppApplication *self = APP_APPLICATION (application);

        if (self->priv->window == NULL)
                self->priv->window = app_application_window_new (GTK_APPLICATION (self));

        gtk_window_present_with_time (GTK_WINDOW (self->priv->window), self->priv->activation_timestamp);
        self->priv->activation_timestamp = GDK_CURRENT_TIME;
}

static void
app_application_startup (GApplication *application)
{
        G_APPLICATION_CLASS (app_application_parent_class)->startup (application);

        g_action_map_add_action_entries (G_ACTION_MAP (application),
                                         app_entries, G_N_ELEMENTS (app_entries),
                                         application);
}

static void
app_application_about_activated (__attribute__ ((unused)) GSimpleAction *action,
                                 __attribute__ ((unused)) GVariant      *parameter,
                                 gpointer       user_data)
{
        GApplication *app;

        app = g_application_get_default ();
        gtk_show_about_dialog (GTK_WINDOW (APP_APPLICATION (app)->priv->window),
                               "program-name", "App",
                               "title", _("App"),
                               "logo-icon-name", PACKAGE_NAME,
                               NULL);
}

static void
app_application_quit_activated (__attribute__ ((unused)) GSimpleAction *action,
                                __attribute__ ((unused)) GVariant      *parameter,
                                gpointer       user_data)
{
        gtk_widget_destroy (APP_APPLICATION (user_data)->priv->window);
}

GtkApplication*
app_application_new (void)
{
        return GTK_APPLICATION (g_object_new (APP_TYPE_APPLICATION, NULL));
}
