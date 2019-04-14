#include <SFML/Graphics.hpp>
#include "Tile.h"

Tile::Tile() {
	this->adjacent_mines = 0;
	this->cleared = false;
	this->flagged = false;
	this->mine = false;
}

Tile::~Tile() {
}

bool Tile::isFlagged() {
	return this->flagged;
}

bool Tile::isCleared() {
	return this->cleared;
}

bool Tile::toggleFlag() {
	if (this->flagged || this->cleared) {
		this->flagged = false;
	} else {
		this->flagged = true;
	}
	return this->flagged;
}

bool Tile::clear() {
	if (this->mine) 
		return false;
	this->cleared = true;
	return true;
}

bool Tile::assignMine() {
	if (this->mine == true) 
		return false;
	this->mine = true;
	return true;
}

bool Tile::assignAdjacentMines(int n) {
	this->adjacent_mines = n;
}
