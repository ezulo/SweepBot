#include "DisplayModule.h"

DisplayModule:DisplayModule(int TileMatrix* t_m, int res_x, int res_y) {
	this->tile_matrix = t_m;
	this->res_x = res_x;
	this->res_y = res_y;
	this_>window = new sf::RenderWindow(
		sf::VideoMode(this->res_x,this->res_y),
		"SFML Window"
	);
	//initialize textures
	sf::Texture ct[9];
	sf::Texture ut;
	sf::Texture mt;
	sf::Texture ft;
	if (
		!ct[0].loadFromFile("resource/ct0.png")
		||
		!ct[1].loadFromFile("resource/ct1.png")
		||
		!ct[2].loadFromFile("resource/ct2.png")
		||
		!ct[3].loadFromFile("resource/ct3.png")
		||
		!ct[4].loadFromFile("resource/ct4.png")
		||
		!ct[5].loadFromFile("resource/ct5.png")
		||
		!ct[6].loadFromFile("resource/ct6.png")
		||
		!ct[7].loadFromFile("resource/ct7.png")
		||
		!ct[8].loadFromFile("resource/ct8.png")
		||
		!ct[9].loadFromFile("resource/ct9.png")
		||
		!ut.loadFromFile("resource/ut.png")
		||
		!mt.loadFromFile("resource/mt.png")
		||
		!ft.loadFromFile("resource/ft.png")
	) {
		return -1;
	}
	for (int i = 0; i < 9; i++) {
		cleared_tile_sprites[i] = sf::Sprite(ct[0]);
	}
	uncleared_tile_sprite = sf::Sprite(ut);
	mine_sprite = sf:Sprite(mt);
	flag_sprite = sf::Sprite(ft);
}

DisplayModule::~DisplayModule() {
	this->window.close();
	delete this->window;
	delete this->tile_matrix;
}

void draw() {
	//get every tile and add it to game window
	for (int x = 0; x < this->t_m->x_bound; x++) {
	   for (int y = 0; y < this->t_m->y_bound; y++) {
			Tile* cur_tile = t_m->getTile(x,y);
			sf::Sprite t_sprite;
			if (cur_tile->isCleared()) {
				if (cur_tile->mine) {
					t_sprite = mine_sprite;
				}
				else {
					t_sprite = cleared_tile_sprites(cur_tile->adjacent_mines);
				}
			}
			else if (cur_tile->isFlagged()) {
				t_sprite = flag_sprite;
			}
			else if (!cur_tile->isCleared()){
				t_sprite = uncleared_tile_sprite;
			}
			t_sprite.setPosition(x*40, y*40);
			window->draw(t_sprite);
	   }
	}
	window->clear();
	window->display();
}
