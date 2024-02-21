-- premake5.lua
workspace "jlox-cpp"
configurations { "debug", "release" }
location "build"

warnings "Extra"

project "jlox-cpp"
kind "ConsoleApp"
language "C++"
targetdir "bin/%{cfg.buildcfg}"

files { "**.h", "**.cpp", "**.c" }

filter "configurations:debug"
defines { "DEBUG" }
symbols "On"

filter "configurations:release"
defines { "NDEBUG" }
optimize "On"
