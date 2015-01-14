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

#include "config.h"

#include <glib/gi18n.h>

#include "application-window.h"

static void app_application_window_class_init (AppApplicationWindowClass *klass);
static void app_application_window_init       (AppApplicationWindow *self);
static void app_application_window_dispose    (GObject *gobject);

struct _AppApplicationWindowPrivate {
        GtkWidget *header_bar;
        GtkWidget *stack;
};

G_DEFINE_TYPE_WITH_PRIVATE (AppApplicationWindow, app_application_window, GTK_TYPE_APPLICATION_WINDOW);

static void
app_application_window_class_init (__attribute__ ((unused)) AppApplicationWindowClass *klass)
{
        GObjectClass *gobject_class = G_OBJECT_CLASS (klass);

        gobject_class->dispose = app_application_window_dispose;
}

static void
app_application_window_init (AppApplicationWindow *self)
{
        GtkWidget *task_entry;

        self->priv = app_application_window_get_instance_private (self);

        self->priv->header_bar = gtk_header_bar_new ();
        gtk_header_bar_set_title (GTK_HEADER_BAR (self->priv->header_bar), _("App"));
        gtk_header_bar_set_show_close_button (GTK_HEADER_BAR (self->priv->header_bar), TRUE);
        gtk_window_set_titlebar (GTK_WINDOW (self), self->priv->header_bar);
        gtk_widget_show (self->priv->header_bar);

        self->priv->stack = gtk_stack_new ();
        gtk_container_add (GTK_CONTAINER (self), self->priv->stack);
        gtk_widget_show (self->priv->stack);
}

static void
app_application_window_dispose (GObject *gobject)
{
        AppApplicationWindow *self = APP_APPLICATION_WINDOW (gobject);

        G_OBJECT_CLASS (app_application_window_parent_class)->dispose (gobject);
}

GtkWidget*
app_application_window_new (GtkApplication *application)
{
        return GTK_WIDGET (g_object_new (APP_TYPE_APPLICATION_WINDOW,
                                         "application", application,
                                         "title", _("App"),
                                         "window-position", GTK_WIN_POS_CENTER,
                                         NULL));
}
