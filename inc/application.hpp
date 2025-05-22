#pragma once
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

namespace App {

void RenderUI() noexcept;
void InitializedGLFWAndOtherStuff(GLFWerrorfun callback) noexcept;
void SetupImGUI(GLFWwindow* win) noexcept;
void Update(GLFWwindow* win) noexcept;
void TerminateProg(GLFWwindow* win) noexcept;

} // namespace App
