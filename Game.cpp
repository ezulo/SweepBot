#include "Game.h"
#include <stdlib.h>

Game::Game(Difficulty diff) {
	//allocate mem
	game_matrix = new int*[diff.x];
	reveal_matrix = new bool*[diff.x];
	for (int i = 0; i < diff.y; i++) {
		game_matrix[i] = new int[diff.y];
		reveal_matrix[i] = new bool[diff.y];
	}
	//initialize matrices
	for (int i = 0; i < diff.x; i++) {
		for (int j = 0; j < diff.y; j++) {
			game_matrix[i][j] = 0;
			reveal_matrix[i][j] = false;
		}
	}
	//distribute mines
	//"distance" from mines will be -1
	for (int i = 0; i < diff.mines; i++) {
		do {
			rand_x = rand() % 100;
			rand_y = rand() % 100;
		} while (game_matrix[rand_x][rand_y] == -1);
		game_matrix[rand_x][rand_y] = -1;
	}
	//generate number of adjacent mines for each cell
	for (int i = 0; i < diff.x; i++) {
		for (int j = 0; j < diff.y; j++) {
			int tile = game_matrix[i][j];
			if (tile != -1) {
				mine_count = 0;
				if (

}
