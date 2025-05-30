#pragma once

#include <GLFW/glfw3.h>
#include <stdexcept>
#include <cassert>
#include <cstdint>
#include <ui/fileExplorer.hpp>

class Window {
private:
    uint16_t mWidth;
    uint16_t mHeight;
    GLFWwindow* mGlfwWin;
    
    // Private constructor
    Window();

public:
    // Destructor
    ~Window();
    void Clean(); // It calls the destructor

    // Getters
    uint16_t GetWidth();
    uint16_t GetHeight();
    GLFWwindow* GetGlfwWindow();

    // Static functions
    // Get The singleton
    static Window& GetInstance(); // Static getter
    static void InitGlfw();
    static void ImplUI(const ImGuiIO& io);

    // Disable copying
    Window(Window& win) = delete;
    Window& operator=(Window& win) = delete;
};