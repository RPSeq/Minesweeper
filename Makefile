CC = g++ -g
CFLAGS = -Wall -c
LFLAGS = -Wall
OBJS = test.o game.o grid.o panel.o
main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o testing

test.o: panel.h grid.h game.h
	$(CC) $(CFLAGS) test.cpp

panel.o: panel.h
	$(CC) $(CFLAGS) panel.cpp

grid.o: grid.h
	$(CC) $(CFLAGS) grid.cpp

game.o: game.h
	$(CC) $(CFLAGS) game.cpp

clean:
	rm *.o testing
