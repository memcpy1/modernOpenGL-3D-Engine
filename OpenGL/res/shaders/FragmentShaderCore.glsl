#version 330 core

in vec3 out_position;
in vec3 out_Colour;
in vec2 out_textureCoordinate;


##output
out vec4 color;

uniform sampler2D outTexture;


void main()
{
	color = texture(outTexture, out_textureCoordinate);
}
