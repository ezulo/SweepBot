CC = g++
CCFLAGS = -Wall -g

main.o: main.cpp DisplayModule.h TileMatrix.h
	$(CC) $(CCFLAGS) -c main.cpp -o main.o

DisplayModule.o: DisplayModule.cpp TileMatrix.h
	$(CC) $(CCFLAGS) -c DisplayModule.cpp -o DisplayModule.o

ImageModule.o: ImageModule.cpp
	$(CC) $(CCFLAGS) -c ImageModule.cpp -o ImageModule.o

TileMatrix.o: TileMatrix.cpp Tile.h
	$(CC) $(CCFLAGS) -c TileMatrix.cpp -o TileMatrix.o

Tile.o: Tile.cpp
	$(CC) $(CCFLAGS) -c Tile.cpp -o Tile.o

main: main.o DisplayModule.o ImageModule.o TileMatrix.o Tile.o
	$(CC) $(CCFLAGS) -o main main.o DisplayModule.o ImageModule.o TileMatrix.o \
	Tile.o -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

clean: 
	rm -f main *.o 

