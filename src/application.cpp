#include <application.hpp>

void App::RenderUI() noexcept {
    const int num = 64;
    ImGui::Begin("My UI");
    ImGui::TextColored(ImVec4(.0, 255.0, 255.0, 1.0), "Just a variable %d", num);
    ImGui::Text("%s", "Hello, World!");
    ImGui::End();
}

void App::InitializedGLFWAndOtherStuff(GLFWerrorfun callback) noexcept {
    // Call GLFW and setting up the window
    glfwSetErrorCallback(callback);
    if (!glfwInit())
        exit(-1);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Only for MacUser
}

GLFWwindow* App::CreateWindow() noexcept {
    GLFWwindow* win = glfwCreateWindow(480, 720, "ImGCC", nullptr, nullptr);
    if (!win) {
        std::cerr << "The window is not initialized" << std::endl;
        glfwTerminate();
        exit(-1);
    }
    glfwMakeContextCurrent(win);
    glfwSwapInterval(1);

    return win;
}

void App::SetupImGUI(GLFWwindow* win) noexcept {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    auto& io = ImGui::GetIO(); (void)io;

    const char* glsl_version = "#version 130";
    ImGui::StyleColorsLight();
    ImGui_ImplGlfw_InitForOpenGL(win, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
}

void App::Update(GLFWwindow* win) noexcept {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        App::RenderUI(); // Our whole UI

        ImGui::Render();
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(win);
}

void App::TerminateProg(GLFWwindow* win) noexcept {
    // Clear the program and exit it
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(win);
    glfwTerminate();
}