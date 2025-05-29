#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <iostream>
#include <string>
#include <window.hpp>

int main(int, char**) {
    // Init GLFW and window hint
    if (!glfwInit()) {
        std::cerr << "GLFW cannot init itself" << std::endl;
        exit(EXIT_FAILURE);
    }

    
}