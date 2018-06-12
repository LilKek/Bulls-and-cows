FLAG = -g3 -O0 -Wall -Werror -std=c99

default: bin/game

test: bin/ctest
		bin/ctest

bin/game: build/main.o build/menu.o build/game.o build/func.o
		gcc $(FLAG) -o bin/game build/main.o build/menu.o build/game.o build/func.o

build/main.o: src/main.c
		gcc $(FLAG) -o build/main.o -c src/main.c

build/menu.o: src/menu.c
		gcc $(FLAG) -o build/menu.o -c src/menu.c

build/game.o: src/game.c
		gcc $(FLAG) -o build/game.o -c src/game.c

build/func.o: src/func.c
		gcc $(FLAG) -o build/func.o -c src/func.c

bin/ctest: build/test.o build/func.o
		gcc $(FLAG) -o bin/ctest build/test.o build/func.o

build/test.o: test/test.c
		gcc $(FLAG) -o build/test.o -c test/test.c -Ithirdparty -Isrc

.PHONY: clean adddir open gdb rus eng err1 err2
adddir :
		mkdir build bin
clean :
		rm -rf ./build/ ./bin/
open :
		bin/game
gdb :
		gdb bin/game
rus :
		bin/game rus
eng :
		bin/game eng
err1 :
		bin/game asf
err2 :
		bin/game asf 123
