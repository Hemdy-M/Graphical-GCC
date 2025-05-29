#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <GL/gl.h>
#include <iostream>
#include <string>
#include <window.hpp>

int main(int, char**) {
    // Init GLFW and window hint
    if (!glfwInit()) {
        std::cerr << "GLFW cannot init itself" << std::endl;
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, false);

    auto& win = Window::GetInstance();

    while (!glfwWindowShouldClose(win.GetGlfwWindow())) {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(win.GetGlfwWindow());
    }

    win.Clean();
    glfwTerminate();
}