#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Movement.h"

#include "BufferObject.h"
#include "Texture.h"
#include "Shader.h"
#include "LightPositions.h"
#include "Model.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <imGui/imgui.h>
#include <imGui/imgui_impl_opengl3.h>
#include <imGui/imgui_impl_glfw.h>

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

#include <assimp/light.h>
                                                    //BasedMemset
#include <iostream>


#define DISPLAY_HEIGHT 900
#define DISPLAY_WIDTH 1440


bool renderlightsource = 1;

glm::vec3 Coral(1.0f, 0.5f, 0.31f);
glm::vec3 LightPos(0.7f, 0.2f, 2.0f);
glm::vec3 LightDir(-0.2f, -1.0f, -0.3f);

int main(void)
{
           
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
#endif
    
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);


    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(DISPLAY_WIDTH, DISPLAY_HEIGHT, "OpenGL", 0, NULL);

    glfwSetCursorPosCallback(window, GetMousePosition);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    

    glfwSwapInterval(0); //vsync
    
    
    glfwMakeContextCurrent(window);
    
    if (glewInit() != GLEW_OK)
        std::cout << "[GLEW] Initialization Error" << std::endl;
    else
        std::cout << "[GLEW] glewInit() Successful" << std::endl;

   

  

    glEnable(GL_DEPTH_TEST);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    
   
    


    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
  
   
    ImGui::StyleColorsDark();
    
 
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    

 



    std::string ModelVertex("res/shaders/ModelVertex.glsl");
    std::string ModelFragment("res/shaders/FragmentLighting.glsl");
    std::string ModelFragment2("res/shaders/ModelFragment.glsl");
    std::string RModelFragment("res/shaders/ModelFragment.glsl");
   
    std::string LSVertex("res/shaders/VertexLightSource.glsl");
    std::string LSFragment("res/shaders/FragmentLightSource.glsl");


    Shader LightSourceProgram = Shader(LSVertex, LSFragment);
    Shader ModelProgram = Shader(ModelVertex, ModelFragment);
    //ModelProgram = Shader(ModelVertex, ModelFragment);
   
    Model m ("res/models/Backpack/backpack.obj");
    Model plane ("res/models/plane.obj");
 




    LightSourceProgram.Bind();

    VertexArray lsVAO;
    lsVAO.Bind();
    VertexBuffer lsVBO(Cube, sizeof(Cube), GL_STATIC_DRAW);
    lsVBO.Bind();

    glVertexAttribPointer(6, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex_basic), (const void*)offsetof(Vertex_basic, pos));
    glEnableVertexAttribArray(6);
   
    LightSourceProgram.UnBind();

    ModelProgram.Bind();

    SetLightPositions(ModelProgram.ID);

    ModelProgram.setFloatUniform("material.ShineRadius", 32.0f);
    ModelProgram.setVec3Uniform("light.AmbientIntensity", glm::vec3(0.2f));
    ModelProgram.setVec3Uniform("light.DiffuseIntensity", glm::vec3(0.5f));
    ModelProgram.setVec3Uniform("light.SpecularIntensity", glm::vec3(1));
    ModelProgram.setVec3Uniform("material.AmbienceColor", glm::vec3(1));
    ModelProgram.setVec3Uniform("material.DiffuseColor", glm::vec3(1));
    ModelProgram.setVec3Uniform("material.SpecularColor", glm::vec3(1));

    ModelProgram.setFloatUniform("spotlight.CutOff", glm::cos(glm::radians(12.5f)));
    ModelProgram.setFloatUniform("spotlight.OuterCutOff", glm::cos(glm::radians(17.5f)));
    
    ModelProgram.setFloatUniform("spotlight.Constant", 1.0f);
    ModelProgram.setFloatUniform("spotlight.Linear", 0.045f);
    ModelProgram.setFloatUniform("spotlight.Quadratic", 0.0075f);

    ModelProgram.UnBind();




    




    stbi_set_flip_vertically_on_load(true);
    
    //main_loop
    double previousTime = glfwGetTime();
    int frameCount = 0;


    

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

       

        float currentFrame = (float)glfwGetTime();
        DeltaTime = currentFrame - LastFrame;
        LastFrame = currentFrame;

       
        processMovementInput(window);
      
         
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        
        ModelProgram.Bind();

        ModelProgram.setVec3Uniform("spotlight.direction", cameraFront);
        ModelProgram.setVec3Uniform("spotlight.position", cameraPos);

        ModelProgram.setVec3Uniform("ViewPosition", cameraPos);
       
        
  
        glm::mat4 model = glm::mat4(1.0f);
        glm::mat4 proj = glm::perspective(glm::radians(45.0f), (float)1440 / (float)900, 0.1f, 100.0f);
        glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
        ModelProgram.setMat4Uniform("projection", proj);
        ModelProgram.setMat4Uniform("view", view);
      
       
        LightSourceProgram.Bind();
        LightSourceProgram.setMat4Uniform("view", view);
        LightSourceProgram.setMat4Uniform("proj", proj);
      
       
            model = glm::mat4(1);
            
            model = glm::translate(model, glm::vec3(0.7f, 20.2f, 2.0f));
            
            LightSourceProgram.setMat4Uniform("model", model);
            lsVAO.Bind();
            glDrawArrays(GL_TRIANGLES, 0, 36);
            lsVAO.UnBind();
  
        

   
        
        model = glm::mat4(1);
        
        ModelProgram.Bind();
        model = glm::translate(model, glm::vec3(0.0f, 10.0f, 6.0f));
        ModelProgram.setMat4Uniform("model", model);
       
        
        m.Render(ModelProgram);
        
        
        
        model = glm::mat4(1);
        ModelProgram.setMat4Uniform("model", model);
        plane.Render(ModelProgram);
        
      
        ImGui::Render();
        
        glfwSwapBuffers(window);        
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
    
    

    /// Shutdown/Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
   
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

