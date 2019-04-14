#include "ImageModule.h"

ImageModule::ImageModule(){}

ImageModule::~ImageModule(){}

sf::Texture ImageModule::getImage(const std::string name) {
	std::map<std::string,sf::Texture>::iterator it;
	it = this->texture_cache.find(name);
	if (it == this->texture_cache.end()) {
		//image is not cached
		sf::Texture new_texture;
		if (!new_texture.loadFromFile(name)) {
			throw "Texture file not found: " + name;
		}
		this->texture_cache.insert(std::pair<std::string,sf::Texture>(name, new_texture));
		return new_texture;
	} else {
		return this->texture_cache.at(name);
	}
}
