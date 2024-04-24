#version 330 core

layout (location = 6) in vec3 aPos;




uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;





void main()
{
    gl_Position = proj * view * model * vec4(aPos, 1.0);
    //gl_Position = vec4(aPos, 1.0);
} 