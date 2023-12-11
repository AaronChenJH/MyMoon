# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

# 两个变量与子目录中的 CMakeLists.txt 文件无关
message("CMAKE_BINARY_DIR ${CMAKE_BINARY_DIR}") # 顶级 CMakeLists.txt 文件所在路径
message("CMAKE_SOURCE_DIR ${CMAKE_SOURCE_DIR}") # 构建输出所在路径

# CMAKE_VERSION 为 CMake 的版本，由 MAJOR.MINOR.PATCH.TWEAK 组成
message("CMAKE_VERSION ${CMAKE_VERSION}")
message("CMAKE_MAJOR_VERSION ${CMAKE_MAJOR_VERSION}") # 主要版本
message("CMAKE_MINOR_VERSION ${CMAKE_MINOR_VERSION}") # 次要版本
message("CMAKE_PATCH_VERSION ${CMAKE_PATCH_VERSION}") # 补丁版本
message("CMAKE_TWEAK_VERSION ${CMAKE_TWEAK_VERSION}") # 微调版本

message("CMAKE_CURRENT_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}") # 当前 CMakeLists.txt 文件所在目录
message("CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}") # 当前 CMakeLists.txt 构建输出所在的目录
message("CMAKE_CURRENT_LIST_DIR ${CMAKE_CURRENT_LIST_DIR}")	     # 当前执行 CMakeLists.txt 文件所在目录
message("CMAKE_CURRENT_LIST_FILE ${CMAKE_CURRENT_LIST_FILE}")   # 当前执行 CMakeLists.txt 文件所在路径
message("CMAKE_CURRENT_LIST_LINE ${CMAKE_CURRENT_LIST_LINE}")   # 当前执行 CMakeLists.txt 文件所在行号


# project ("MyMoon")
project("MyMoon" VERSION 1.0.0.0 DESCRIPTION "主项目" HOMEPAGE_URL https://www.example.com )

# 要求编译器必须支持 c++ 17
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# OFF表示不启用 GCC 特有的一些扩展功能
set(CMAKE_CXX_EXTENSIONS OFF)

# 对 C++ 版本的进行定义
set(CMAKE_CXX_STANDARD 17)

# 设置默认构建类型为 Debug 模式
IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
ENDIF(NOT CMAKE_BUILD_TYPE)

if(WIN32)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
endif(WIN32)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

link_directories(${CMAKE_SOURCE_DIR}/lib)

# find the required packages
find_package(GLM REQUIRED)
message(STATUS "GLM included at ${GLM_INCLUDE_DIR}")
find_package(GLFW3 REQUIRED)
message(STATUS "Found GLFW3 in ${GLFW3_INCLUDE_DIR}")
find_package(ASSIMP REQUIRED)
message(STATUS "Found ASSIMP in ${ASSIMP_INCLUDE_DIR}")

if(WIN32)
  set(LIBS glfw3 opengl32 assimp freetype irrKlang)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS) # 关闭安全检查
else()
  set(LIBS )
endif(WIN32)

# 读取输入文件中的内容，将 CMakeLists.txt 文件中的变量转变为 C/C++ 中可识别的宏定义
configure_file(configuration/root_directory.h.in configuration/root_directory.h)
include_directories(${CMAKE_BINARY_DIR}/configuration)

# first create relevant static libraries required for other projects
# 添加静态库
add_library(STB_IMAGE "src/stb_image.cpp")
set(LIBS ${LIBS} STB_IMAGE)

add_library(GLAD "src/glad.c")
set(LIBS ${LIBS} GLAD)

add_executable(MyMoon main.cpp)

# 将指定目录添加到编译器的头文件搜索路径之下，指定的目录被解释成当前源码路径的相对路径
include_directories(${CMAKE_SOURCE_DIR}/includes)

if(WIN32)
	message("WIN32 6666666666666666666666666666666")
endif(WIN32)

if(MSVC)
    message("MSVC 777777777777777777777777777777777")
endif(MSVC)

message("CMAKE_PROJECT_DESCRIPTION ${CMAKE_PROJECT_DESCRIPTION}")
message("CMAKE_PROJECT_HOMEPAGE_URL ${CMAKE_PROJECT_HOMEPAGE_URL}")
message("CMAKE_PROJECT_NAME ${CMAKE_PROJECT_NAME}")

# 包含子项目。
#add_subdirectory ("MyMoon")
#add_subdirectory("VulkanModule") # 隔离vulkan的模块
add_subdirectory("VulkanTest") # vulkan测试主窗口
#include("VulkanTest")
add_subdirectory("OpenGLTest") # vulkan测试主窗口
