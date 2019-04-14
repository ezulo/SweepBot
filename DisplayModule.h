#ifndef DISPLAYMODULE_H
#define DISPLAYMODULE_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "TileMatrix.h"
#include "ImageModule.h"

class DisplayModule {
	public:
		DisplayModule(int x_res, int y_res);
		~DisplayModule();
		void draw(TileMatrix* t_m);
		int x_res;
		int y_res;
	private:
		ImageModule img_module;
		sf::RenderWindow window;
};

#endif
