CC=g++
CFLAGS=

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

sfml-app: main.o
	$(CC) main.o -o sfml-app -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

