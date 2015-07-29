TOPDIR = .
.include "build.mk"

all: $(APP)

$(APP):
	make -C src

clean:
	make -C src clean

install: bin
	make -C src install

uninstall:
	make -C src uninstall
