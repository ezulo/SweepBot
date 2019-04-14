#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

// Tile: a tile placed on the minesweeper board
// Preserves data about number of adjacent tiles.
// Can be in states: unknown, cleared, and flagged
class Tile {
	public:
		Tile();
		~Tile();
		bool isFlagged();
		bool isCleared();
		bool toggleFlag();
		bool clear();
		bool assignMine();
		bool assignAdjacentMines(int n);
		bool mine;
		int adjacent_mines;
	private:
		bool cleared;
		bool flagged;
		sf::Texture tile_texture;

};

#endif
