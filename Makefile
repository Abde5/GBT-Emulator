LIBS  =
CFLAGS = -Wall

# Should be equivalent to your list of C files, if you don't build selectively
SRC=$(wildcard ./src/*.c)
SRC_GROUP=$(wildcard ./src/*/*.c)

default: gbt

gbt: $(SRC) $(SRC_GROUP)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

run: gbt
	./gbt ../roms/Tetris\ \(W\)\ \(V1.1\).gb
