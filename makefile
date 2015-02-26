all:
	make debug
	make release
	make app_

update:
	git pull

debug: libvmemleak_d

release: libvmemleak

libvmemleak_d:
	cd lib && \
	qmake libvmemleak.pro CONFIG+=debug && \
	make && \
	make clean && \
	cd ..

libvmemleak:
	cd lib && \
	qmake libvmemleak.pro && \
	make && \
	make clean && \
	cd ..

app_:
	cd app && qmake CONFIG+=debug && make && make clean && cd ..

clean:
	find -type d -name 'build-*'    -exec rm -r {} \;
	find -type f -name '*.o'        -delete
	find -type f -name '*.pro.user' -delete
	find -type f -name 'Makefile*'  -delete
