bin_PROGRAMS = app

app_SOURCES = \
	application.c \
	application.h \
	application-resources.c \
	application-window.c \
	application-window.h \
	main.c \
	$(NULL)

app_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""${datadir}/locale"\" \
	-DPACKAGE_DATA_DIR=\""${datadir}"\" \
	$(AM_CPPFLAGS) \
	$(NULL)

app_CFLAGS = \
	$(WARN_CFLAGS) \
	$(APP_MODULES_CFLAGS) \
	$(AM_CFLAGS) \
	$(NULL)

app_LDFLAGS =

app_LDADD = \
	$(APP_MODULES_LIBS) \
	$(NULL)

EXTRA_DIST = \
	resources/app.gresource.xml

resource_files = $(shell $(GLIB_COMPILE_RESOURCES) --sourcedir=$(srcdir) --generate-dependencies $(srcdir)/app.gresource.xml)
application-resources.c: app.gresource.xml $(resource_files)
	$(AM_V_GEN)$(GLIB_COMPILE_RESOURCES) --target=$@ --sourcedir=$(srcdir) --generate-source --c-name app $(srcdir)/app.gresource.xml

CLEANFILES = \
	application-resources.c

-include $(top_srcdir)/git.mk
