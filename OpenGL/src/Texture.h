#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL2/SOIL2.h>
#include <stbImage/stb_image.h>
#include <string>
#include <iostream>

unsigned int CreateTexture(const std::string& filepath, const int& unit, const bool& flip);
void ActivateTextureUnit(unsigned int unit);

