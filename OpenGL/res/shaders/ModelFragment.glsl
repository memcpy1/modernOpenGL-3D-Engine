#version 330 core
out vec4 color;

in vec2 TexCoords;

uniform sampler2D texture_diffuse1;

void main()
{    
    color = texture(texture_diffuse1, TexCoords);
    //color = vec4(0.0f, 1.0f, 0.0f, 1.0f);
}