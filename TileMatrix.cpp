#include "TileMatrix.h"

TileMatrix::TileMatrix(int x, int y, int tile_size) {
	// initialize all tiles
	this->x_bound = x;
	this->y_bound = y;
	this->tile_size = tile_size;
	std::vector<std::vector<Tile>> t_vec(x, std::vector<Tile>(y));
	this->grid = t_vec;
}

TileMatrix::~TileMatrix() {
}

Tile TileMatrix::getTile(int x, int y) {
	if ((x >= this->x_bound) || (x < 0) || (y >= this->y_bound) || (y < 0)) {
		throw "Error: tile index out of bounds";	
	}
	return grid.at(x).at(y);
}

void TileMatrix::assignMines(int num_mines) {
	int x_rand, y_rand;
	int counter = 0;
	while (counter < num_mines) {
		x_rand = rand() % this->x_bound;
		y_rand = rand() % this->y_bound;
		counter += this->getTile(x_rand,y_rand).assignMine();
	}
	this->assignNumbers();
}

void TileMatrix::assignNumbers() {
	for (int x = 0; x < this->x_bound; x++) {
		for (int y = 0; y < this->y_bound; y++) {
			//set bounds based on board placement
			int offset_x, offset_y = -1;
			int offset_x_upper, offset_y_upper = 1;
			if (x == 0) offset_x = 0;
			if (x == x_bound - 1) offset_x_upper = 0;
			if (y == 0) offset_y = 0;
			if (y == y_bound - 1) offset_y_upper = 0;
			for (int x_o = x + offset_x; x_o <= x + offset_x_upper; x_o++) {
				for (int y_o = y + offset_y; y_o <= y + offset_y_upper; y_o++) {
					if (this->getTile(x_o,y_o).mine) {
						this->grid.at(x).at(y).adjacent_mines++;
					}
				}
			}
		}
	}
}

	
