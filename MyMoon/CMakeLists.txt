# CMakeList.txt: MyMoon 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#

# 将源代码添加到此项目的可执行文件。
add_executable (MyMoon "MyMoon.cpp" "MyMoon.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET MyMoon PROPERTY CXX_STANDARD 20)
endif()

##  GLFW
set(GLFW_INCLUDE_DIRS D:/glfw-3.3.8.bin.WIN64/include/)
set(GLFW_LIBRARIES D:/glfw-3.3.8.bin.WIN64/lib-mingw-w64/libglfw3.a)
include_directories(${GLFW_INCLUDE_DIRS})
target_link_libraries(MyMoon ${GLFW_LIBRARIES})

# VULKAN
set(VK_SDK_PATH $ENV{VK_SDK_PATH})
set(VK_SDK_INCLUDE ${VK_SDK_PATH}/Include)
set(VK_SDK_LIB ${VK_SDK_PATH}/Lib/vulkan-1.lib)

##  Vulkan
find_package(Vulkan REQUIRED FATAL_ERROR)
include_directories(${Vulkan_INCLUDE_DIRS})
target_link_libraries(MyMoon ${Vulkan_LIBRARIES})
# TODO: 如有需要，请添加测试并安装目标。
