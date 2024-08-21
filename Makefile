CC=gcc
CFLAGS=-Isrc/ -g
LIBS=

all: build/main

.PHONY: objects
objects: $(patsubst src/%.c, build/%.o, $(wildcard src/*.c))

build/%.o: src/%.c
	mkdir -p build
	$(CC) -c $(CFLAGS) $< -o $@

build/main: objects
	${CC} build/*.o ${LIBS} -o $@

.PHONY: run
run: build/main
	./build/main

.PHONY: debug
debug: clean build/main
	gdb ./build/main

.PHONY: watch
watch:
	ls src/*.c | entr make run

.PHONY: clean
clean:
	rm -rf build
