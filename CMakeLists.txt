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
project("MyMoon" VERSION 1.0.0.0 DESCRIPTION "主项目" HOMEPAGE_URL https://www.example.com LANGUAGES CXX)

message("CMAKE_PROJECT_DESCRIPTION ${CMAKE_PROJECT_DESCRIPTION}")
message("CMAKE_PROJECT_HOMEPAGE_URL ${CMAKE_PROJECT_HOMEPAGE_URL}")
message("CMAKE_PROJECT_NAME ${CMAKE_PROJECT_NAME}")

message("CMAKE_PROJECT_VERSION ${CMAKE_PROJECT_VERSION}")
message("CMAKE_PROJECT_VERSION_MAJOR ${CMAKE_PROJECT_VERSION_MAJOR}")
message("CMAKE_PROJECT_VERSION_MINOR ${CMAKE_PROJECT_VERSION_MINOR}")
message("CMAKE_PROJECT_VERSION_PATCH ${CMAKE_PROJECT_VERSION_PATCH}")
message("CMAKE_PROJECT_VERSION_TWEAK ${CMAKE_PROJECT_VERSION_TWEAK}")


# 包含子项目。
add_subdirectory ("MyMoon")
add_subdirectory("VulkanModule") # 隔离vulkan的模块
add_subdirectory("VulkanTest") # vulkan测试主窗口
#include("VulkanTest")
# add_subdirectory("OpenGLTest") # vulkan测试主窗口
