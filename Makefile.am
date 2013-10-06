bin_PROGRAMS = nsyncd

nsyncd_SOURCES =  \
	src/nsyncd.c  \
	src/nsyncd.h  \
	src/logger.c  \
	src/logger.h  \
	src/watcher.c \
	src/watcher.h

nsyncd_LDADD = @PACKAGE_LIBS@ @PTHREAD_LIBS@

MAINTAINERCLEANFILES =      \
	$(srcdir)/aclocal.m4    \
	$(srcdir)/compile       \
	$(srcdir)/config.guess  \
	$(srcdir)/config.h.in   \
	$(srcdir)/config.h.in~  \
	$(srcdir)/config.sub    \
	$(srcdir)/configure     \
	$(srcdir)/depcomp       \
	$(srcdir)/install-sh    \
	$(srcdir)/ltmain.sh     \
	$(srcdir)/Makefile.in   \
	$(srcdir)/missing       \
	$(srcdir)/*/Makefile.in
