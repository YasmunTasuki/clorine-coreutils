CFLAGS = -O3

all: basename cat echo yes true false whoami printf hostname

%: %.c
	mkdir -p bin
	gcc $< -o bin/$@ $(CFLAGS)

install: all
	cp bin/* /usr/bin
