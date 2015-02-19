all:
	make build

update:
	git pull

build:
	make debug
	make release
	make app_

debug:
	qmake libvmemleak.pro CONFIG+=debug
	make -f Makefile
	make clean -f Makefile

release:
	qmake libvmemleak.pro CONFIG+=release
	make -f Makefile
	make clean -f Makefile

app_:
	cd app && \
	qmake vmemleak_app.pro CONFIG+=debug && \
	make -f Makefile && \
	make clean -f Makefile && \
	cd ..

clean:
	make clean -f Makefile
	find -name Makefile -type f -delete
