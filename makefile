all:
	make build

update:
	git pull

build:
	make debug
	make release
	make app_

debug:
	qmake libvmemleak.pro CONFIG+=debug -o _makefile
	make -f _makefile
	make clean -f _makefile

release:
	qmake libvmemleak.pro CONFIG+=release -o _makefile
	make -f _makefile
	make clean -f _makefile

app_:
	cd app && \
	qmake vmemleak_app.pro CONFIG+=debug -o _makefile && \
	make -f _makefile && \
	make clean -f _makefile && \
	cd ..

clean:
	make clean -f _makefile
	find -name "Makefile*" -type f -delete

