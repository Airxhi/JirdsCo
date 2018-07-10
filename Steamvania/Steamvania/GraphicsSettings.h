#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

class GraphicsSettings
{
public:
	int width;
	int height;
	int style;
	GraphicsSettings();
	~GraphicsSettings();
private:
	bool file_exists(const std::string& name);
	void load();
	void createDefault();
	bool save();
};

