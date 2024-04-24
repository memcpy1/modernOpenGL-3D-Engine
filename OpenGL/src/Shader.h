#pragma once
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>

class Shader
{
public:
	unsigned int ID;


	Shader(std::string& filepath1, std::string& filepath2);
	void Bind();
	void UnBind();





	void setBoolUniform(const char* location, bool _bool);
	void setIntUniform(const char* location, int _int);
	void setMat4Uniform(const char* location, glm::mat4 mat);
	void setVec3Uniform(const char* location, glm::vec3 vector);
	void setFloatUniform(const char* location, float _float);

};











