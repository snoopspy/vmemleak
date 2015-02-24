all:
	make build

update:
	git pull

build:
	make app_

app_:
	cd app && \
	qmake CONFIG+=debug && \
	make&& \
	make clean && \
	cd ..

clean:
	find -name "Makefile*" -type f -delete

