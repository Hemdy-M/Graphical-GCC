#include "window.hpp"

#include <iostream>

// Private constructor
Window::Window(): mWidth(480), mHeight(720) {
    // Init GLFW and setting up all of the 'glfwWindowHint()' calls we need
    InitGlfw();
    
    // Create the window by using GLFW and check if mGlfwWin is not equal to nullptr
    mGlfwWin = glfwCreateWindow(mWidth, mHeight, "DearImGCC", nullptr, nullptr);
    assert(mGlfwWin != nullptr);
    glfwMakeContextCurrent(mGlfwWin);
}

// Destructor
Window::~Window() {
    glfwDestroyWindow(mGlfwWin);
    glfwTerminate();
}

void Window::Clean() {
    this->~Window();
}

// Getters
uint16_t Window::GetWidth() { return mWidth; }
uint16_t Window::GetHeight() { return mHeight; }
GLFWwindow* Window::GetGlfwWindow() { return mGlfwWin; }

// Static functions
// Get the singleton
Window& Window::GetInstance() {
    static Window sInstance;
    return sInstance;
}

void Window::InitGlfw() {
    assert(glfwInit() == GLFW_TRUE);

    // Specifie which OpenGL version we're gonna use, 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, false);
}

// Implement the app's UI
void Window::ImplUI(const ImGuiIO& io) {
    // Set the next window in fullscreen
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(io.DisplaySize);

    ImGui::Begin("Hello", nullptr,
        ImGuiWindowFlags_NoDecoration |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoBringToFrontOnFocus
    );
    ImGui::Text("io adress : %p", &io);
    ImGui::End();
}