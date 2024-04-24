#version 330 core

layout (location = 0) in vec3 vertex_pos;
layout (location = 1) in vec3 vertex_colour;
layout (location = 2) in vec2 vertex_tex_coords;



out vec3 out_position;
out vec3 out_Colour;
out vec2 out_textureCoordinate;



uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main()
{
	out_position = vertex_pos;
	out_Colour = vertex_colour;
	out_textureCoordinate = vec2(vertex_tex_coords.x, vertex_tex_coords.y);
	
	
	
	
	
	
	
	
	
	gl_Position = proj * view * model * vec4(vertex_pos, 1.f);
	//gl_Position = vec4(vertex_pos, 1.f);
}


