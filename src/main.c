#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GL/glew.h>

#include "linmath.h"

#include <stdio.h>

void error_callback(int error, const char *description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow *window, 
        int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main()
{
    GLFWwindow *window;
    printf("[+] Pruebas GLFW\n");

    if (!glfwInit()) {
        fprintf(stderr, "[-] La inicialización de GLFW falló.\n");
        return -1;
    }
    else {
        printf("[+] Se ha inicializado bien GLFW.\n");
        glfwTerminate();
        printf("[+] GLFW terminado.\n");
    }

    /* Error callback */
    glfwSetErrorCallback(error_callback);

    /* Crea una ventana */
    window = glfwCreateWindow(640, 480, "Título", NULL, NULL);
    if (!window) {
        fprintf(stderr, "[-] La creación de una ventana falló.\n");
        glfwTerminate();
        return -1;
    }
    
    /* Crea contexto OpenGL */
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    /* Contexto OpenGL y ajustes */
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "[-] La inicialización de GLEW falló.\n");
        return -1;
    }

    while (!glfwWindowShouldClose(window)) {
        
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    printf("[+] Ventana destruida y GLFW terminado.\n");

    return 0;
}

