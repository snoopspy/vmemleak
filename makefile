TEMP_MAKEFILE=_makefile

all:
	make build

update:
	git pull

build:
	make debug
	make release
	make app_

debug:
	qmake libvmemleak.pro CONFIG+=debug -o $(TEMP_MAKEFILE)
	make -f $(TEMP_MAKEFILE)
	make clean -f $(TEMP_MAKEFILE)

release:
	qmake libvmemleak.pro CONFIG+=release -o $(TEMP_MAKEFILE)
	make -f $(TEMP_MAKEFILE)
	make clean -f $(TEMP_MAKEFILE)

app_:
	cd app && \
	qmake vmemleak_app.pro CONFIG+=debug -o $(TEMP_MAKEFILE) && \
	make -f $(TEMP_MAKEFILE) && \
	make clean -f $(TEMP_MAKEFILE) && \
	cd ..

clean:
	make clean -f $(TEMP_MAKEFILE)
	find -name "Makefile*" -type f -delete

