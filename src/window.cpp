#include "window.hpp"
#include <iostream>

// Private constructor
Window::Window(): mWidth(480), mHeight(720) {
    mGlfwWin = glfwCreateWindow(mWidth, mHeight, "DearImGCC", nullptr, nullptr);
    assert(mGlfwWin != nullptr);
    glfwMakeContextCurrent(mGlfwWin);
}

// Destructor
Window::~Window() {
    glfwDestroyWindow(mGlfwWin);
}

void Window::Clean() {
    this->~Window();
}

// Getters
uint16_t Window::GetWidth() { return mWidth; }
uint16_t Window::GetHeight() { return mHeight; }
GLFWwindow* Window::GetGlfwWindow() { return mGlfwWin; }

// Get the singleton
Window& Window::GetInstance() {
    static Window sInstance;
    return sInstance;
}
