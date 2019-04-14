#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cstdio>

#include "DisplayModule.h"
#include "TileMatrix.h"

int main()
{
	DisplayModule* dis_mod = new DisplayModule(800, 800);
	TileMatrix* tile_mat = new TileMatrix(1, 1, 0);
    while (true)
    {
		dis_mod->draw(tile_mat);
    }
    return EXIT_SUCCESS;
}
