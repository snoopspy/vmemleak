define makelib # $(1)filename, $(2)config
	cd lib && \
	qmake $(1) CONFIG+=$(2) && \
	make && \
	make clean && \
	cd ..
endef

all:
	make debug
	make release
	make app_

update:
	git pull

debug: libvmemleak_d

release: libvmemleak

libvmemleak_d:
	$(call makelib,libvmemleak.pro,debug)

libvmemleak:
	$(call makelib,libvmemleak.pro,release)

app_:
	cd app && qmake CONFIG+=debug && make && make clean && cd ..

clean:
	find -type d -name 'build-*'    -exec rm -r {} \;
	find -type f -name '*.o'        -delete
	find -type f -name '*.pro.user' -delete
	find -type f -name 'Makefile*'  -delete
