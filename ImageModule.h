#ifndef IMAGEMODULE_H
#define IMAGEMODULE_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class ImageModule {
	public:
		ImageModule();
		~ImageModule();
		sf::Texture getImage(const std::string name);
	private:
		std::map<std::string,sf::Texture> texture_cache;
};

#endif
