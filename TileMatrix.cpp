#include "TileMatrix.h"

TileMatrix::TileMatrix(int x, int y, int num_mines) {
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
}

	
