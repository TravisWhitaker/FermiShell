#	ChemTerm Copyright (C) 2012 Travis Michael Whitaker

CC=clang
CFLAGS=
SOURCE= $(wildcard src/*.c)
INCLUDE=-I./include
EXECUTABLE=-o chemterm

all:
	$(CC) $(CFLAGS) $(INCLUDE) $(EXECUTABLE) $(SOURCE)
