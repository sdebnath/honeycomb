TOPDIR = .
.include "build.mk"

all: $(APP)

$(APP):
	make -C src

deps:
	@USERID=`id -u`; \
	if [ `id -u` -ne 0 ]; then \
		echo "make deps needs to be ran with root privileges"; \
	else \
		if pkg info libucl > /dev/null 2>&1; then \
			echo "libucl installed"; \
		else \
			echo "installing libucl..."; \
			pkg install libucl; \
		fi \
	fi		
clean:
	make -C src clean

install: bin
	make -C src install

uninstall:
	make -C src uninstall
