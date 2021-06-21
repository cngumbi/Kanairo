workspace "Kanairo"
    architecture "x64"
    

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Kanairo"
    location "Kanairo"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"

    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "KN_PLATFORM_WINDOWS",
            "KN_BUILD_DLL",
            "__WINDLL"

        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Nairo")
        }

    filter "configurations:Debug"
        defines "KN_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "KN_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "KN_DIST"
        optimize "On"
    
project "Nairo"
    location "Nairo"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"

    }

    includedirs
    {
        "Kanairo/vendor/spdlog/include",
        "Kanairo/src"
    }

    links
    {
        "Kanairo"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "KN_PLATFORM_WINDOWS"

        }

    filter "configurations:Debug"
        defines "KN_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "KN_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "KN_DIST"
        optimize "On"
    