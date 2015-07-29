TOPDIR = ..
.include "../build.mk"

INCLUDES = -I/usr/include -I/usr/local/include
LDFLAGS = -L/usr/lib -L/usr/local/lib
CFLAGS = -g -O0 -Wall $(INCLUDES)
LIBS = -lucl

SRCS =         		\
	build.c		\
	config.c	\
	destroy.c	\
	help.c		\
	honeycomb.c	\
	list.c		\
	restart.c	\
	restartall.c	\
	start.c		\
	startall.c	\
	stop.c		\
	stopall.c

OBJS=$(SRCS:.c=.o)

all: $(SRCS) $(APP)

$(APP): $(OBJS)
	mkdir -p $(BINDIR)
	$(CC) $(LDFLAGS) $(LIBS) -o $(BINDIR)/$(APP) $(OBJS)

clean:
	-rm -f $(BINDIR)/$(APP)
	-rm -f *.o

install: $(APP)
	$(INSTALL) -m0755 $(BINDIR)/$(APP) $(DESTDIR)/bin/$(APP)

uninstall:
	rm -f $(DESTDIR)/bin/$(APP)
