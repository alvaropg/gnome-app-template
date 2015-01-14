bin_PROGRAMS = app

app_SOURCES = \
	application.c \
	application.h \
	application-window.c \
	application-window.h \
	main.c \
	utils.c \
	utils.h \
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

-include $(top_srcdir)/git.mk
