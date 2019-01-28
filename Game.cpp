#include "Game.h"
#include <stdlib.h>

Game::Game(Difficulty diff) {
	//initialize matrix
	this->game_matrix = new TileMatrix(diff.x_bound, diff.y_bound);
	// distribute mines
	this->game_matrix->assignMines(diff.mines);
}

Game::~Game() {
	delete this->game_matrix;
}

int Game::clickOnTile(int x_pos, int y_pos) {
	Tile* cur = this->game_matrix->getTile(x_pos, y_pos);
	if (cur->mine) {
		this->game_status = 2;
	}
	else {
		cur->clear()
	}
	return this->game_status;
}

void Game::flagTile(int x_pos, int y_pos) {
	this->game_matrix->getTile(x_pos,y_pos)->toggleFlag();
}
