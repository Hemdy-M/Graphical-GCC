#pragma once

#include <imgui.h>
#include <imgui_stdlib.h>
#include <string>
#include <vector>

/// @todo
// Implement the UI (and also the logic) of the implementation of the WinApi
// We should be able to select multiple files
// And send the file to the core/compiler.hpp (and .cpp) file(s) to comile them

namespace FileExplorer {
    // UI
    struct FileEntryField {
        std::string filePathUI;
    };

    // Logic
    struct FileElement {
        std::string filePathLOGIC;
        std::vector<std::string> files;

        FileElement();
    };
} // namespace FileExplorer

