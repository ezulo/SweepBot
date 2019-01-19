#include <SFML/Graphics.hpp>
#include "Tile.h"

Tile::Tile() {
	if (!tile_texture->loadFromFile("resource/tile.png")) {
		throw std::runtime_error(
			"Tile sprite not found."
		);
	}
	tile_sprite = new sf::Sprite(tile_texture);
	this->cleared = false;
	this->flagged = false;
	this->mine = false;
}

Tile::~Tile() {
	delete tile_texture;
	delete tile_sprite;
}

bool Tile::isFlagged() {
	return this->flagged;
}

bool Tile::toggleFlag() {
	if (this->flagged || this->cleared) {
		this->flagged = false;
	} else {
		this->flagged = true;
	}
	return this->flagged;
}

bool clear() {
	if (this->mine) 
		return false;
	this->cleared = true;
	return true;
}

bool assignMine() {
	if (this->mine == true) 
		return false;
	this->mine = true;
	return true;
}

bool assignAdjacentMines(int n) {
	this->adjacent_mines = n;
}

sf::Sprite* getSprite() {
	return tile_sprite;
}
