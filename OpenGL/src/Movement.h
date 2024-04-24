#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, 1.0f);
glm::vec3 cameraBack = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

float DeltaTime = 0.0f;
float LastFrame = 0.0f;

glm::vec3 cameraDir = glm::vec3(0.0f, 0.3f, 0.7f);


float Xposition = 720;
float Yposition = 450;

float Yaw = -90.0f;
float Pitch = -90.0f;
bool firstMouse = 1;


float _speed;

void processMovementInput(GLFWwindow* window, float speed = 5.0f, float sensitivity = 0.09f)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    float cameraSpeed = (float)(speed * DeltaTime);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPos += cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPos -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS)
        cameraPos -= cameraSpeed * cameraUp;
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        cameraPos += cameraSpeed * cameraUp; 

    _speed = sensitivity;
}

void GetMousePosition(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse) // initially set to true
    {
        Xposition = xpos;
        Yposition = ypos;
        firstMouse = false; 
    }




    float xPosOffset = xpos - Xposition;
    float yPosOffset = Yposition - ypos;

    Xposition = xpos;
    Yposition = ypos;


    float MouseSensitivity = _speed;
    xPosOffset *= MouseSensitivity;
    yPosOffset *= MouseSensitivity;

    Yaw += xPosOffset;
    Pitch += yPosOffset;

    if (Pitch > 89.9f)
        Pitch = 89.9f;
    if (Pitch < -89.9f)
        Pitch = -89.9f;

    glm::vec3 direction;
    direction.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    direction.y = sin(glm::radians(Pitch));
    direction.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    cameraFront = glm::normalize(direction);
}
