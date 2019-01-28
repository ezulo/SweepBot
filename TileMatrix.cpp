#include "TileMatrix.h"

TileMatrix::TileMatrix(int x, int y) {
	// initialize all tiles
	this->x_bound = x;
	this->y_bound = y;
	for (int i = 0; i < this->x_bound; i++) {
		for (int j = 0; j < this->y_bound; j++) {
			this->grid[i][j] = new Tile();
		}
	}
}

TileMatrix::~TileMatrix() {
	// detele all tiles
	for (int i = 0; i < x; i++) {
		delete[] grid[i];
	}
}

Tile* TileMatrix::getTile(int x, int y) {
	if ((x >= this->x) || (y >= this->y)) {
		throw std::runtime_error(
			"Error: tile index out of bounds"
		);
	}
	return &grid[x][y];
}

void TileMatrix::assignMines(int num_mines) {
	int x_rand, y_rand;
	int counter = 0;
	while (counter < num_mines) {
		x_rand = rand() % this->x_bound;
		y_rand = rand() % this->y_bound;
		counter += this->getTile(x_rand,y_rand)->assignMine();
	}
	this->assignNumbers();
}

void TileMatrix::assignNumbers() {
	int adj_mines;
	for (int x = 0; x < this->x; x++) {
		for (int y = 0; y < this->y; y++) {
			adj_mines = 0;
			//set bounds based on board placement
			int offset_x, offset_y = -1;
			int offset_x_upper, offset_y_upper = 1;
			if (x == 0) offset_x = 0;
			if (x < 0) offset_x_upper = 0;
			if (y == 0) offset_y = 0;
			if (y < 0) offset_y_upper = 0;
			for (int x_o = x + offset_x; x_o <= x + offset_x_upper; x_o++) {
				for (int y_o = y + offset_y; y_o <= y + offset_y_upper; y_o++) {
					if (game_matrix->getTile(x_o,y_o).mine) {
						adj_mines++;
					}
				}
			}
			game_matrix->getTile(x_o,y_o).adjacent_mines = adj_mines;
		}
	}
}

	
