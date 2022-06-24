CFLAGS = -O3

all: basename cat echo yes

basename: basename.c
	gcc -o bin/$@ $^ $(CFLAGS)

cat: cat.c
	gcc -o bin/$@ $^ $(CFLAGS)

echo: echo.c
	gcc -o bin/$@ $^ $(CFLAGS)

yes: yes.c
	gcc -o bin/$@ $^ $(CFLAGS)

install: all
	cp bin/{basename,cat,echo,yes} /usr/bin