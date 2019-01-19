#ifndef DISPLAYMODULE_H
#define DISPLAYMODULE_H

#include <SFML/Graphics.hpp>
#include "TileMatrix.h"

class DisplayModule {
	public:
		DisplayModule(int x_res, int y_res);
		~DisplayModule();
		void draw();
		int res_x;
		int res_y;
	private:
		sf::RenderWindow* window;
		TileMatrix* tile_matrix;
		sf::Sprite cleared_tile_sprites[9];
		sf::Sprite uncleared_tile_sprite;
		sf::Sprite mine_sprite;
		sf::Sprite flag_sprite;
};

#endif
