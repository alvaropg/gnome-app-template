SUBDIRS = icons

desktopdir = $(datadir)/applications
desktop_in_in_files = app.desktop.in.in
desktop_in_files = app.desktop.in
desktop_DATA = $(desktop_in_files:.desktop.in=.desktop)
@INTLTOOL_DESKTOP_RULE@

@INTLTOOL_XML_RULE@

EXTRA_DIST = \
	$(desktop_in_in_files) \
	$(NULL)

CLEANFILES = \
	$(desktop_DATA) \
	$(NULL)

DISTCLEANFILES = \
	$(desktop_in_files) \
	$(NULL)

desktop-file-validate: $(desktop_DATA)
	for f in $^; do \
		$(DESKTOP_FILE_VALIDATE) $$f; \
	done

check-local: desktop-file-validate

.PHONY: desktop-file-validate

-include $(top_srcdir)/git.mk
