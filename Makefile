CC = g++

CFLAGS = -Wall -std=c++11 -ggdb -O3 -Wno-comment

INCLUDES = -Iinclude

OBJS = 

all: src/main.cpp $(OBJS)
	$(CC) $(CFLAGS) src/main.cpp $(OBJS) -o bin/main $(INCLUDES)

clean:
	rm *.o
