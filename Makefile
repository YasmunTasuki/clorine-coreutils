CFLAGS = -O3

all: basename cat echo yes true false whoami printf

basename: basename.c
	mkdir -p bin
	gcc -o bin/$@ $^ $(CFLAGS)

cat: cat.c
	gcc -o bin/$@ $^ $(CFLAGS)

echo: echo.c
	gcc -o bin/$@ $^ $(CFLAGS)

yes: yes.c
	gcc -o bin/$@ $^ $(CFLAGS)

true: true.c
	gcc -o bin/$@ $^ $(CFLAGS)

false: false.c
	gcc -o bin/$@ $^ $(CFLAGS)

whoami: whoami.c
	gcc -o bin/$@ $^ $(CFLAGS)

printf: printf.c
	gcc -o bin/$@ $^ $(CFLAGS)

install: all
	cp bin/* /usr/bin
