CC = g++

INCLUDE_PATHS = -IC:\MinGW\mingw32\include
INCLUDE_PATHS += -I../include
LIBRARY_PATHS = -LC:\MinGW\mingw32\lib

CFLAGS = -D_SDL2 -D_WIN32
LIBS = -lmingw32
#LIBS += -mwindows
TARGET = ../bin2h

OBJS  = $(wildcard src/*.c)

all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(CFLAGS) $(LIBS) -o $(TARGET)