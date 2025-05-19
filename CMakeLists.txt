cmake_minimum_required(VERSION 3.10)
project(DearImGuiProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# === ImGui sources ===
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/libs/imgui)
set(IMGUI_BACKENDS ${IMGUI_DIR}/backends)

set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_BACKENDS}/imgui_impl_glfw.cpp
    ${IMGUI_BACKENDS}/imgui_impl_opengl3.cpp
)

# === GLFW from source ===
add_subdirectory(libs/glfw)
include_directories(libs/glfw/include)

# === Includes ===
include_directories(
    inc
    ${IMGUI_DIR}
    ${IMGUI_BACKENDS}
)

# === Add executable ===
add_executable(${PROJECT_NAME}
    src/main.cpp
    ${IMGUI_SOURCES}
)

# === OpenGL ===
find_package(OpenGL REQUIRED)

# === Link libraries ===
target_link_libraries(${PROJECT_NAME}
    glfw
    OpenGL::GL
)
