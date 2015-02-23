all:
	make build

update:
	git pull

build:
	make debug
	make release
	make app_

debug:
	qmake libvmemleak.pro CONFIG+=debug -o qmakefile
	make -f qmakefile
	make clean -f qmakefile

release:
	qmake libvmemleak.pro CONFIG+=release -o qmakefile
	make -f qmakefile
	make clean -f qmakefile

app_:
	cd app && \
	qmake vmemleak_app.pro CONFIG+=debug -o qmakefile && \
	make -f qmakefile && \
	make clean -f qmakefile && \
	cd ..

clean:
	make clean -f qmakefile
	find -name "Makefile*" -type f -delete

