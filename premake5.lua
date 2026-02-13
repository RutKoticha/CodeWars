-- Get the filename from an environment variable, or default to main.cpp
local active_file = os.getenv("ACTIVE_CPP_FILE") or "main.cpp"

workspace "ProblemSolving"
    configurations { "Debug", "Release" }

project "Solution"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    targetdir "bin/%{cfg.buildcfg}"

    -- Dynamically use the file passed from VS Code
    files { active_file }

    filter "configurations:Debug"
        defines { "LOCAL_RUN" }
        symbols "On"
