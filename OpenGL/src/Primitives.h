#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <vector>
#include <string>



struct Vertex_basic
{
    glm::vec3 pos;
    glm::vec3 normal;
    glm::vec2 tex;
};


struct Texture
{
    unsigned int TextureID;
    std::string type;
    std::string path;
};

struct Black
{
    glm::vec3 ambient = glm::vec3(0.02f, 0.02f, 0.02f); 	 		
    glm::vec3 diffuse = glm::vec3(0.01f, 0.01f, 0.01f); 	 	
    glm::vec3 specular = glm::vec3(0.4f, 0.4f, 0.4f); 	
    float shiny = 0.078125f * 128.0f;
};


Vertex_basic Square[] =
{       //vertex                             //color                              //texture 
        glm::vec3(-0.5f,  0.5f,  0.0f),      glm::vec3(1.0f,  0.0f,  0.0f),       glm::vec2(0.0f,  1.0f),    //0
        glm::vec3(-0.5f, -0.5f,  0.0f),      glm::vec3(0.0f,  1.0f,  0.0f),       glm::vec2(0.0f,  0.0f),    //1
        glm::vec3( 0.5f, -0.5f,  0.0f),      glm::vec3(0.0f,  0.0f,  1.0f),       glm::vec2(1.0f,  0.0f),    //2
        glm::vec3( 0.5f,  0.5f,  0.0f),      glm::vec3(1.0f,  1.0f,  1.0f),       glm::vec2(1.0f,  1.0f)     //3
};

int SquareIndex[] =
{
        0, 1, 2,
        2, 3, 0
};

std::vector<glm::vec3> CubePos
{
        glm::vec3( 0.0f,  0.0f,  0.0f),
        glm::vec3( 2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3( 2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3( 1.3f, -2.0f, -2.5f),
        glm::vec3( 1.5f,  2.0f, -2.5f),
        glm::vec3( 1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
};



Vertex_basic Cube[] =
{
    //verteces                        //normals                         //texture          
    glm::vec3(-0.5f, -0.5f, -0.5f),   glm::vec3( 0.0f,  0.0f, -1.0f),   glm::vec2(0.0f, 0.0f),
    glm::vec3( 0.5f, -0.5f, -0.5f),   glm::vec3( 0.0f,  0.0f, -1.0f),   glm::vec2(1.0f, 0.0f),
    glm::vec3( 0.5f,  0.5f, -0.5f),   glm::vec3( 0.0f,  0.0f, -1.0f),   glm::vec2(1.0f, 1.0f),
    glm::vec3( 0.5f,  0.5f, -0.5f),   glm::vec3( 0.0f,  0.0f, -1.0f),   glm::vec2(1.0f, 1.0f),
    glm::vec3(-0.5f,  0.5f, -0.5f),   glm::vec3( 0.0f,  0.0f, -1.0f),   glm::vec2(0.0f, 1.0f),
    glm::vec3(-0.5f, -0.5f, -0.5f),   glm::vec3( 0.0f,  0.0f, -1.0f),   glm::vec2(0.0f, 0.0f),

    glm::vec3(-0.5f, -0.5f,  0.5f),   glm::vec3( 0.0f,  0.0f,  1.0f),   glm::vec2(0.0f, 0.0f),
    glm::vec3( 0.5f, -0.5f,  0.5f),   glm::vec3( 0.0f,  0.0f,  1.0f),   glm::vec2(1.0f, 0.0f),
    glm::vec3( 0.5f,  0.5f,  0.5f),   glm::vec3( 0.0f,  0.0f,  1.0f),   glm::vec2(1.0f, 1.0f),
    glm::vec3( 0.5f,  0.5f,  0.5f),   glm::vec3( 0.0f,  0.0f,  1.0f),   glm::vec2(1.0f, 1.0f),
    glm::vec3(-0.5f,  0.5f,  0.5f),   glm::vec3( 0.0f,  0.0f,  1.0f),   glm::vec2(0.0f, 1.0f),
    glm::vec3(-0.5f, -0.5f,  0.5f),   glm::vec3( 0.0f,  0.0f,  1.0f),   glm::vec2(0.0f, 0.0f),

    glm::vec3(-0.5f,  0.5f,  0.5f),   glm::vec3(-1.0f,  0.0f,  0.0f),   glm::vec2(1.0f, 0.0f),
    glm::vec3(-0.5f,  0.5f, -0.5f),   glm::vec3(-1.0f,  0.0f,  0.0f),   glm::vec2(1.0f, 1.0f),
    glm::vec3(-0.5f, -0.5f, -0.5f),   glm::vec3(-1.0f,  0.0f,  0.0f),   glm::vec2(0.0f, 1.0f),
    glm::vec3(-0.5f, -0.5f, -0.5f),   glm::vec3(-1.0f,  0.0f,  0.0f),   glm::vec2(0.0f, 1.0f),
    glm::vec3(-0.5f, -0.5f,  0.5f),   glm::vec3(-1.0f,  0.0f,  0.0f),   glm::vec2(0.0f, 0.0f),
    glm::vec3(-0.5f,  0.5f,  0.5f),   glm::vec3(-1.0f,  0.0f,  0.0f),   glm::vec2(1.0f, 0.0f),

    glm::vec3( 0.5f,  0.5f,  0.5f),   glm::vec3( 1.0f,  0.0f,  0.0f),   glm::vec2(1.0f, 0.0f),
    glm::vec3( 0.5f,  0.5f, -0.5f),   glm::vec3( 1.0f,  0.0f,  0.0f),   glm::vec2(1.0f, 1.0f),
    glm::vec3( 0.5f, -0.5f, -0.5f),   glm::vec3( 1.0f,  0.0f,  0.0f),   glm::vec2(0.0f, 1.0f),
    glm::vec3( 0.5f, -0.5f, -0.5f),   glm::vec3( 1.0f,  0.0f,  0.0f),   glm::vec2(0.0f, 1.0f),
    glm::vec3( 0.5f, -0.5f,  0.5f),   glm::vec3( 1.0f,  0.0f,  0.0f),   glm::vec2(0.0f, 0.0f),
    glm::vec3( 0.5f,  0.5f,  0.5f),   glm::vec3( 1.0f,  0.0f,  0.0f),   glm::vec2(1.0f, 0.0f),

    glm::vec3(-0.5f, -0.5f, -0.5f),   glm::vec3( 0.0f, -1.0f,  0.0f),   glm::vec2(0.0f, 1.0f),
    glm::vec3( 0.5f, -0.5f, -0.5f),   glm::vec3( 0.0f, -1.0f,  0.0f),   glm::vec2(1.0f, 1.0f),
    glm::vec3( 0.5f, -0.5f,  0.5f),   glm::vec3( 0.0f, -1.0f,  0.0f),   glm::vec2(1.0f, 0.0f),
    glm::vec3( 0.5f, -0.5f,  0.5f),   glm::vec3( 0.0f, -1.0f,  0.0f),   glm::vec2(1.0f, 0.0f),
    glm::vec3(-0.5f, -0.5f,  0.5f),   glm::vec3( 0.0f, -1.0f,  0.0f),   glm::vec2(0.0f, 0.0f),
    glm::vec3(-0.5f, -0.5f, -0.5f),   glm::vec3( 0.0f, -1.0f,  0.0f),   glm::vec2(0.0f, 1.0f),

    glm::vec3(-0.5f,  0.5f, -0.5f),   glm::vec3( 0.0f,  1.0f,  0.0f),   glm::vec2(0.0f, 1.0f),
    glm::vec3( 0.5f,  0.5f, -0.5f),   glm::vec3( 0.0f,  1.0f,  0.0f),   glm::vec2(1.0f, 1.0f),
    glm::vec3( 0.5f,  0.5f,  0.5f),   glm::vec3( 0.0f,  1.0f,  0.0f),   glm::vec2(1.0f, 0.0f),
    glm::vec3( 0.5f,  0.5f,  0.5f),   glm::vec3( 0.0f,  1.0f,  0.0f),   glm::vec2(1.0f, 0.0f),
    glm::vec3(-0.5f,  0.5f,  0.5f),   glm::vec3( 0.0f,  1.0f,  0.0f),   glm::vec2(0.0f, 0.0f),
    glm::vec3(-0.5f,  0.5f, -0.5f),   glm::vec3( 0.0f,  1.0f,  0.0f),   glm::vec2(0.0f, 1.0f)
};


/// CUBE DATA

/*
    VertexArray CubeVAO;
    CubeVAO.Bind();

    VertexBuffer VertexB1(Cube, sizeof(Vertex[36]), GL_DYNAMIC_DRAW);
    VertexB1.Bind();

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(Vertex, position));
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(Vertex, color));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(Vertex, textureCoordinate));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    CubeVAO.UnBind();
    */

float cube_vertices[] = {
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
     0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
     0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
};