#pragma once
#define DEBUG
#include "Shader.h"


Shader::Shader(std::string& filepath1, std::string& filepath2)
{

    const char* opengl[2]{};
    std::ifstream stream(filepath1);
    std::string line;
    std::stringstream ss[2];

    while (getline(stream, line))
    {       
        ss[0] << line << std::endl;

#ifdef xDEBUG
        std::cout << line << std::endl;
#endif
    }

    std::string vertexSrc = ss[0].str();
    opengl[0] = vertexSrc.c_str();

    stream.close();
    line = "";

    std::ifstream stream1(filepath2);

    while (getline(stream1, line))
    {
        ss[1] << line << std::endl;
        
#ifdef xDEBUG
        std::cout << line << std::endl;
#endif
    }

    std::string FragmentSrc = ss[1].str();
    opengl[1] = FragmentSrc.c_str();
    stream1.close();


    unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(vs, 1, &opengl[0], nullptr);
    glShaderSource(fs, 1, &opengl[1], nullptr);
    glCompileShader(vs);
    glCompileShader(fs);

    //Error Handling
    int vssuccess;
    glGetShaderiv(vs, GL_COMPILE_STATUS, &vssuccess);
    int fssuccess;
    glGetShaderiv(fs, GL_COMPILE_STATUS, &fssuccess);

    if (!vssuccess)              //error logging for vertex shader
    {
        int lenght;
        glGetShaderiv(vs, GL_INFO_LOG_LENGTH, &lenght);
        char* message = (char*)_malloca(vssuccess * sizeof(char));
        glGetShaderInfoLog(vs, lenght, &lenght, message);
        std::cout << "[OpenGL] Vertex shader failed to compile!" << '\n';
        std::cout << message << '\n';
    }

    if (!fssuccess)             //error logging for fragment shader
    {
        int lenght;
        glGetShaderiv(fs, GL_INFO_LOG_LENGTH, &lenght);
        char* message = (char*)_malloca(fssuccess * sizeof(char));
        glGetShaderInfoLog(fs, lenght, &lenght, message);
        std::cout << "[OpenGL] Vertex shader failed to compile!" << '\n';
        std::cout << message << '\n';
    }

    ID = glCreateProgram();
    glAttachShader(ID, vs);
    glAttachShader(ID, fs);
    glLinkProgram(ID);

    int linksuccess;
    glGetProgramiv(ID, GL_LINK_STATUS, &linksuccess);

    if (!linksuccess)             //error logging for fragment shader
    {
        int lenght;
        glGetProgramiv(ID, GL_INFO_LOG_LENGTH, &lenght);
        char* message = (char*)_malloca(linksuccess * sizeof(char));
        glGetProgramInfoLog(ID, lenght, &lenght, message);
        std::cout << "[OpenGL] Program failed to link!" << '\n';
        std::cout << message << '\n';
    }

    glValidateProgram(ID);

    glUseProgram(ID);

    glDetachShader(ID, vs);
    glDetachShader(ID, fs);
    glDeleteShader(vs);
    glDeleteShader(fs);
}

void Shader::Bind()
{
    glUseProgram(ID);
}

void Shader::UnBind()
{
    glUseProgram(0);
}




void Shader::setIntUniform(const char* location, int _int)
{
    glUniform1i(glGetUniformLocation(ID, location), _int);
}
void Shader::setBoolUniform(const char* location, bool _bool)
{
    glUniform1i(glGetUniformLocation(ID, location), (int)_bool);
}
void Shader::setMat4Uniform(const char* location, glm::mat4 mat)
{
    glUniformMatrix4fv(glGetUniformLocation(ID, location), 1, 0, glm::value_ptr(mat));
}
void Shader::setVec3Uniform(const char* location, glm::vec3 vector)
{
    glUniform3f(glGetUniformLocation(ID, location), vector.x, vector.y, vector.z);
}
void Shader::setFloatUniform(const char* location, float _float)
{
    glUniform1f(glGetUniformLocation(ID, location), _float);
};