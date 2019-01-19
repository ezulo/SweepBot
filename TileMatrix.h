#ifndef TILEMATRIX_H
#define TILEMATRIX_H

class TileMatrix {
	public:
		TileMatrix(int x, int y, int num_mines);
		~TileMatrix();
		Tile* getTile(int x, int y);
		void assignMines(int num_mines);
		void resetGrid();
		int x_bound;
		int y_bound;
		Tile** grid;
};

#endif
