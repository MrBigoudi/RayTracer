#include <cstdio>
#include <cstdlib>
#include <cmath>

#include "opengl.hpp"
#include "utils.hpp"
#include "maths.hpp"
#include "scene.hpp"

// camera
scene::Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

// light
glm::vec3 lightPos(1.2f, 0.5f, -0.5f);

void processInput(GLFWwindow *window){
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv){

    opengl::initGLFW();
    GLFWwindow* window = opengl::createWindow(SCR_WIDTH, SCR_HEIGHT, "test", GLFW_TRUE);
    opengl::initGLAD();

    opengl::Shader shader = opengl::Shader("src/shaders/vert.glsl", "src/shaders/frag.glsl");

    glEnable(GL_DEPTH_TEST);

    float vertices[] = {
        -0.5f, -0.5f, 0.5f, // bottom left front 0
         0.5f, -0.5f, 0.5f, // bottom right front 1
         0.5f,  0.5f, 0.5f, // top right front 2
        -0.5f,  0.5f,0.5f, // top left front 3
        -0.25f, -0.5f,  -0.5f, // bottom left back 4
         0.75f, -0.5f,  -0.5f, // bottom right back 5
         0.75f,  0.5f,  -0.5f, // top right back 6
        -0.25f,  0.5f,  -0.5f, // top left back 7
    };

    int indices[] = {
        // front face
        0,1,2,
        0,2,3,
        // back face
        4,5,6,
        4,6,7,
        // top face
        3,2,6,
        3,6,7,
        // bottom face
        0,1,5,
        0,5,4,
        // left face
        0,4,7,
        0,7,3,
        // right face
        1,5,6,
        1,6,2
    };

    glClearColor(0.21f, 0.3f, 0.3f, 1.0f);

    GLuint vboId, eboId, vaoId;
    glGenVertexArrays(1, &vaoId);
    glGenBuffers(1, &vboId);
    glGenBuffers(1, &eboId);
    // bind vao
    glBindVertexArray(vaoId);
    // copy vertices in vbo
    glBindBuffer(GL_ARRAY_BUFFER, vboId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // copy indices in ebo
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    // set the vertex attrib pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // MVP
    glm::mat4 projection = camera.getProjectionMatrix();  
    glm::mat4 view = camera.getViewMatrix(); 
    glm::mat4 model = glm::mat4(1.0f);

    // shader uniforms
    shader.use();
    shader.setMat4fv("model", model);
    shader.setMat4fv("view", view);
    shader.setMat4fv("projection", projection);   
    shader.setVec3f("lightColor",  1.0f, 1.0f, 1.0f);
    shader.setVec3f("cubeColor", 1.0f, 0.5f, 0.31f);
    shader.setVec3f("viewPos", camera.mPosition);
    shader.setVec3f("lightPos", lightPos);

    while(!glfwWindowShouldClose(window)){
        processInput(window);
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        shader.use();
        glBindVertexArray(vaoId);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        // unbind vao
        glBindVertexArray(0);

        glfwSwapBuffers(window);
    }

    glDeleteVertexArrays(1, &vaoId);
    glDeleteBuffers(1, &vboId);
    glDeleteBuffers(1, &eboId);
    glfwTerminate();

    exit(EXIT_SUCCESS);
}







// OLD MAIN
/*


#include <iostream>
#include <cstdlib>

#include <vector>

#include "CameraOld.hpp"
#include "Image.hpp"
#include "Scene.hpp"
#include "maths.hpp"
#include "Object.hpp"
#include "Sphere.hpp"
#include "rayTracer.hpp"
#include "opengl.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv){

    // utils::Image* image = new utils::Image(640, 480);
    // image->write("media/producedImages/test.ppm");

    // std::vector<std::vector<utils::Pixel*>> pixels;
    // for (int i=0; i<640; i++){
    //     std::vector<utils::Pixel*> pixelsTmp;
    //     float r = i/640.f;
    //     float g = r;
    //     float b = 1-i/640.f;
    //     for (int j=0; j<480; j++){
    //         pixelsTmp.push_back(new utils::Pixel(r, g, b, i, j));
    //     }
    //     pixels.push_back(pixelsTmp);
    // }

    // utils::Image* image = new utils::Image(pixels);
    // image->write("media/producedImages/test.ppm");

    scene::Object* sphere = (scene::Object*) new scene::Sphere(nullptr, new maths::Vector3(), 10.0f);
    std::vector<scene::Object*> objects;
    objects.push_back(sphere);

    scene::Camera* camera = new scene::Camera(0.0f, 1.7f, 1.7f, 100.0f, 
                                new maths::Vector3(0.0f, 0.0f, -10.0f), 
                                new maths::Vector3(1.0f, 1.0f, 1.0f),
                                new maths::Vector3(0.0f, 1.0f));

    scene::Scene* scene = new scene::Scene(objects, camera);
    
    utils::Image* results = render(*scene);
    results->write("media/producedImages/test1Sphere.ppm");

    exit(EXIT_SUCCESS);
}


*/