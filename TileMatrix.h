#ifndef TILEMATRIX_H
#define TILEMATRIX_H

class TileMatrix {
	public:
		TileMatrix(int x, int y);
		~TileMatrix();
		Tile* getTile(int x, int y);
		void assignMines(int num_mines);
		void initializeMineCount();
		void resetGrid();
		int x_bound;
		int y_bound;
		Tile** grid;
};

#endif
