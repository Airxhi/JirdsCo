#include "GraphicsSettings.h"
GraphicsSettings::GraphicsSettings()
{
	width = 600;
	height = 400;
	style = 7;
	//if (file_exists("config/graphics.cfg")) {
	//	load();
	//}
	//else {
	//	createDefault();
	//}
}


GraphicsSettings::~GraphicsSettings()
{
}

bool GraphicsSettings::file_exists(const std::string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

void GraphicsSettings::load() {
	std::string line;
	std::fstream settings_file("config/graphics.cfg");
	if (settings_file.is_open()) {
	}
}

void GraphicsSettings::createDefault() {

}

bool GraphicsSettings::save() {
	return false;
}