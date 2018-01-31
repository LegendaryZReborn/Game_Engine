#include<iostream>
#include<GL/glew.h>
#include <GLFW/glfw3.h>
#include "Loader.h"
#include "SimpleModel.h"
#include "TexturedModel.h"
#include "Renderer.h"
#include "Shader.h"

using namespace std;

//Prints a description of a glfw related error
void glfwError(int error, const char* description);
//Sets the width and height of the glViewPort if window is reszied
void reshape(GLFWwindow* window, int width, int height);
//Handles key input events
void handleKeyInput(GLFWwindow* window, int key, int scancode, int action, int mods);
//Initializes all the settings, etc for the rest of the program
void initEngine();

int main(void){

    GLFWwindow* window;

    glfwSetErrorCallback(glfwError);
    /*Initialize the library*/
    if(!glfwInit()){
        /*Initialization failed*/
        return -1;
    }

    window = glfwCreateWindow(1280, 720, "I'm Back Bitches", NULL, NULL);

    if(!window){
        /*Window creation failed*/
        glfwTerminate();
        return -1;
    }
    /*Make the window's context current*/
    glfwMakeContextCurrent(window);

    glewInit();
     /*Sets the call back function for when window is resized*/
    glfwSetFramebufferSizeCallback(window, reshape);
    /*Sets the callback function for key input events*/
    glfwSetKeyCallback(window, handleKeyInput);

    vector<float> rectVerts = {
        //Left-bottom triangle
        -0.5, 0.5, 0,
        -0.5, -0.5, 0,
        0.5, -0.5, 0,
        //Right-top triangle
        0.5, -0.5, 0,
        0.5, 0.5, 0,
        -0.5, 0.5, 0
    };

    vector<float> textureUVs = {
        //Left-bottom triangle
        0.0, 0.0,
        0.0, 1.0,
        1.0, 1.0,
        //Right-top triangle
        1.0, 1.0,
        1.0, 0.0,
        0.0, 0.0
    };

    Loader loader;
    GLuint sqTex = loader.loadTexture("goku", 0);

    TexturedModel rect = loader.loadToVao(rectVerts, textureUVs, sqTex);
    SimpleModel rect2 = loader.loadToVao(rectVerts);

    Shader shader("shaders/v_shader.glsl", "shaders/f_shader.glsl");
    Renderer renderer;

    /*Loop while the window hasn't been close*/
    while(!glfwWindowShouldClose(window)){
        renderer.prepare();
        shader.startShader();
        //Send uniform data to shader
        glUniform1f(1, (GLfloat)glfwGetTime());
        glUniform1i(2, 1);
        renderer.render(rect);
        shader.stopShader();

        /*Swap front and back buffers after rendering to back for seamless image*/
        glfwSwapBuffers(window);
        /*Poll for and process events */
        glfwPollEvents();
    }

    loader.cleanUp();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

void glfwError(int error, const char* description){
    fprintf(stderr, "Error: %s\n", description);
}

void reshape(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

void handleKeyInput(GLFWwindow* window, int key, int scancode, int action, int mods){
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void initEngine(){

}

