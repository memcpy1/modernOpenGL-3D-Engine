#pragma once
#include <GL/glew.h>

glm::vec3 LightPositions[] = 
{
	glm::vec3(0.7f,  20.2f,  2.0f),
	glm::vec3(2.3f, -3.3f, -4.0f),
	glm::vec3(-4.0f,  2.0f, -12.0f),
	glm::vec3(0.0f,  0.0f, -3.0f)
};

void SetLightPositions(unsigned int program)
{
		
		float Linear = 0.022f;
		float Quadratic = 0.0019f;

	glUniform1f(glGetUniformLocation(program, "point[0].Constant"), 1.0f);
	glUniform1f(glGetUniformLocation(program, "point[1].Constant"), 1.0f);
	glUniform1f(glGetUniformLocation(program, "point[2].Constant"), 1.0f);
	glUniform1f(glGetUniformLocation(program, "point[3].Constant"), 1.0f);
	
	glUniform1f(glGetUniformLocation(program, "point[0].Linear"), Linear);
	glUniform1f(glGetUniformLocation(program, "point[1].Linear"), Linear);
	glUniform1f(glGetUniformLocation(program, "point[2].Linear"), Linear);
	glUniform1f(glGetUniformLocation(program, "point[3].Linear"), Linear);
	
	glUniform1f(glGetUniformLocation(program, "point[0].Quadratic"), Quadratic);
	glUniform1f(glGetUniformLocation(program, "point[1].Quadratic"), Quadratic);
	glUniform1f(glGetUniformLocation(program, "point[2].Quadratic"), Quadratic);
	glUniform1f(glGetUniformLocation(program, "point[3].Quadratic"), Quadratic);

	glUniform3f(glGetUniformLocation(program, "point[0].position"), LightPositions[0].x, LightPositions[0].y, LightPositions[0].z);
	glUniform3f(glGetUniformLocation(program, "point[1].position"), LightPositions[1].x, LightPositions[1].y, LightPositions[1].z);
	glUniform3f(glGetUniformLocation(program, "point[2].position"), LightPositions[2].x, LightPositions[2].y, LightPositions[2].z);
	glUniform3f(glGetUniformLocation(program, "point[3].position"), LightPositions[3].x, LightPositions[3].y, LightPositions[3].z);
}

void SetPointLightTextures(unsigned int program)
{
	glUniform1i(glGetUniformLocation(program, "point[0].Ambience"), 0);
	glUniform1i(glGetUniformLocation(program, "point[1].Ambience"), 0);
	glUniform1i(glGetUniformLocation(program, "point[2].Ambience"), 0);
	glUniform1i(glGetUniformLocation(program, "point[3].Ambience"), 0);

	glUniform1i(glGetUniformLocation(program, "point[0].Diffuse"), 1);
	glUniform1i(glGetUniformLocation(program, "point[1].Diffuse"), 1);
	glUniform1i(glGetUniformLocation(program, "point[2].Diffuse"), 1);
	glUniform1i(glGetUniformLocation(program, "point[3].Diffuse"), 1);

	glUniform1i(glGetUniformLocation(program, "point[0].Specular"), 2);
	glUniform1i(glGetUniformLocation(program, "point[1].Specular"), 2);
	glUniform1i(glGetUniformLocation(program, "point[2].Specular"), 2);
	glUniform1i(glGetUniformLocation(program, "point[3].Specular"), 2);

}