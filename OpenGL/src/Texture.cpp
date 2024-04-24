#include "Texture.h"

void ActivateTextureUnit(unsigned int unit = 0)
{
    glActiveTexture(GL_TEXTURE0 + unit);
}


unsigned int CreateTexture(const std::string& filepath, const int& unit, const bool& flip)
{

    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);

    stbi_set_flip_vertically_on_load(true);

    int width;
    int height;
    unsigned char* image = stbi_load(filepath.c_str(), &width, &height, 0, STBI_rgb_alpha);

    if(!image)
    {
        std::cout << "[STBI] [" << filepath << "] : File not found!" << '\n';
    } 

    if (image)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    
    ActivateTextureUnit(unit);
    glBindTexture(GL_TEXTURE_2D, texture); 
    
    return texture;
};