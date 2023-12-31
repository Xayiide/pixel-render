#include "pixel.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdio.h>  /* printf */
#include <stdlib.h> /* exit   */


static void error_callback(int err, const char *desc);
static void tecla_callback(GLFWwindow *ventana, int tecla, int scancode,
                           int accion, int mods);
static void get_version(void);


void px_init(int ancho, int alto, const char *titulo)
{
    GLFWwindow *ventana;
    GLuint      vertex_shader, fragment_shader, program;

    printf("[px] Inicializando...\n");

    get_version();
    glfwSetErrorCallback(error_callback);

    if (glfwInit() == GL_FALSE) {
        fprintf(stderr, "[px] Error inicializando GLFW.\n");
        exit(EXIT_FAILURE);
    }

    ventana = glfwCreateWindow(ancho, alto, titulo, NULL, NULL);
    if (ventana == NULL) {
        fprintf(stderr, "[px] Error creando la ventana %s.\n", titulo);
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(ventana, tecla_callback);
    glfwMakeContextCurrent(ventana);
    glfwSwapInterval(1);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "[px] Error al inicializar GLEW.\n");
        exit(EXIT_FAILURE);
    }

    program = glCreateProgram();

}

static void get_version(void)
{
    int        vMajor, vMinor, vRev;
    const char *vString;

    glfwGetVersion(&vMajor, &vMinor, &vRev);

    printf("[px] Versión: %d.%d.%d.\n", vMajor, vMinor, vRev);
}

static void error_callback(int err, const char *desc)
{
    fprintf(stderr, "[px] Error %d: %s\n", err, desc);
}


static void tecla_callback(GLFWwindow *ventana, int tecla, int scancode,
                           int accion, int mods)
{
    if (tecla == GLFW_KEY_ESCAPE && accion == GLFW_PRESS)
        glfwSetWindowShouldClose(ventana, GLFW_TRUE);
}
