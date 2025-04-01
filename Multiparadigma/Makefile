all: game

game: main.o character.o player.o enemy.o utils.o
	g++ -o game main.o character.o player.o enemy.o utils.o

main.o: main.cpp
	g++ -c main.cpp

character.o: character.cpp
	g++ -c character.cpp

player.o: player.cpp
	g++ -c player.cpp

enemy.o: enemy.cpp
	g++ -c enemy.cpp

utils.o: utils.cpp
	g++ -c utils.cpp

clean:
	rm -f *.o game
