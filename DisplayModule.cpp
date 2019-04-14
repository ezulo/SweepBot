#include "DisplayModule.h"

DisplayModule::DisplayModule(int x_res, int y_res):
	window(sf::VideoMode(x_res,y_res), "SFML Window") {
	this->window.setFramerateLimit(60);
	this->x_res = x_res;
	this->y_res = y_res;
}

DisplayModule::~DisplayModule() {
	window.close();
}

void DisplayModule::draw(TileMatrix* t_m) {
	//get every tile and add it to game window
	window.clear();
	for (int x = 0; x < t_m->x_bound; x++) {
	   for (int y = 0; y < t_m->y_bound; y++) {
			Tile cur_tile = t_m->getTile(x,y);
			sf::Sprite t_sprite;
			if (cur_tile.isCleared()) {
				if (cur_tile.mine) {
					t_sprite = sf::Sprite(this->img_module.getImage("resource/mt.png"));
				}
				else {
					const std::string adj_mines_filename = "resource/ct" + std::to_string(cur_tile.adjacent_mines) + ".png";
					t_sprite = sf::Sprite(this->img_module.getImage(adj_mines_filename));
				}
			}
			else if (cur_tile.isFlagged()) {
				t_sprite = sf::Sprite(this->img_module.getImage("resource/ft.png"));
			}
			else if (!cur_tile.isCleared()){
				//CHANGE ME TO UNCLEARED_TILE_SPRITE
				t_sprite = sf::Sprite(this->img_module.getImage("resource/ut.png"));
			}
			t_sprite.setPosition(x*(t_m->tile_size), y*(t_m->tile_size));
			window.draw(t_sprite);
	   }
	}
	window.display();
}
