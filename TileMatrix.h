#ifndef TILEMATRIX_H
#define TILEMATRIX_H

#include "Tile.h"
#include <vector>

class TileMatrix {
	public:
		TileMatrix(int x, int y, int tile_size);
		~TileMatrix();
		Tile getTile(int x, int y);
		void assignMines(int num_mines);
		void assignNumbers();
		void initializeMineCount();
		void resetGrid();
		int x_bound;
		int y_bound;
		int tile_size;
		std::vector<std::vector<Tile>> grid;
};

#endif
