#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <iostream>
#include <string>
#include <window.hpp>

int main() {
    // Get the window (which is a singleton) as reference
    auto& win = Window::GetInstance();

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    
    const char glslVersion[18] = "#version 330 core";
    ImGui_ImplGlfw_InitForOpenGL(win.GetGlfwWindow(), true);
    ImGui_ImplOpenGL3_Init(glslVersion);

    while (!glfwWindowShouldClose(win.GetGlfwWindow())) {
        glfwPollEvents();

        ImGui_ImplGlfw_NewFrame();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        static ImGuiIO& io = ImGui::GetIO();
        
        Window::ImplUI(io);

        glClear(GL_COLOR_BUFFER_BIT);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(win.GetGlfwWindow());
    }

    // Free ImGui
    ImGui_ImplGlfw_Shutdown();
    ImGui_ImplOpenGL3_Shutdown();
    ImGui::DestroyContext();

    // Free GLFW window and terminate the app
    win.Clean(); // It calls its destructor, I did it for more clarity
}