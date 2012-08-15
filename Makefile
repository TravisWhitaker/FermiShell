##	ChemTerm Copyright (C) 2012 Travis Whitaker

CC=clang
CFLAGS=
SOURCE= $(wildcard src/*.c)
INCLUDE=-I./include
OUT=-o
EXECUTABLE=chemterm

all:
	$(CC) $(CFLAGS) $(INCLUDE) $(OUT) $(EXECUTABLE) $(SOURCE)

clean:
	rm $(EXECUTABLE)
