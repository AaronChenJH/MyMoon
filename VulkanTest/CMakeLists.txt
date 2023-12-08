# CMakeList.txt: VulkanTest 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#

# 将源代码添加到此项目的可执行文件。
add_executable (VulkanTest "Vulkanmain.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET VulkanTest PROPERTY CXX_STANDARD 20)
endif()

# 设置cmake工具链为vcpkg
if(NOT DEFINED ENV{VCPKG_ROOT})
    message(FATAL_ERROR "VCPKG_ROOT_PATH not defined! 666666666666666666")
endif()
set(VCPKG_PATH $ENV{VCPKG_ROOT_PATH})
set(VCPKG_ROOT ${VCPKG_PATH}/scripts/buildsystems/vcpkg.cmake CACHE PATH "")
set(CMAKE_TOOLCHAIN_FILE ${VCPKG_ROOT})

#arget_link_libraries(VulkanTest PUBLIC VulkanModule)

# Vulkan SDK设置
if(NOT DEFINED ENV{VK_SDK_PATH})
    message(FATAL_ERROR "VK_SDK_PATH not defined!")
endif()
find_package(Vulkan REQUIRED)
include_directories(${Vulkan_INCLUDE_DIR})
include_directories(${Vulkan_INCLUDE_DIR}/../Third-Party/Include)
include_directories(${PROJECT_SOURCE_DIR})
# 也可以把该路径下的GLFW文件夹直接拷贝到Vulkan  include里，这样这句话就不用写了
include_directories("D:\\glfw-3.3.8.bin.WIN64\\include")  

set(VK_SDK_PATH $ENV{VK_SDK_PATH})
set(VK_SDK_INCLUDE ${VK_SDK_PATH}/Include)
set(VK_SDK_LIB ${VK_SDK_PATH}/Lib/vulkan-1.lib)
# vulkan 链接到库文件
#target_link_libraries(VulkanTest PUBLIC ${VK_SDK_LIB})
target_link_libraries(
    VulkanTest 
#    "D:/glfw-3.3.8.bin.WIN64/lib-mingw-w64/libglfw3.a" 
#    "D:/glfw-3.3.8.bin.WIN64/lib-mingw-w64/libglfw3dll.a" 
    ${Vulkan_LIBRARY}
)

# 设置glfw3.cmake的搜索路径
set(glfw3_DIR "D:/glfw/")
set(CMAKE_PREFIX_PATH ${glfw3_DIR} ${CMAKE_PREFIX_PATH})
list(APPEND CMAKE_MODULE_PATH "D:/glfw/")
#find_package(glfw3 REQUIRED)
#find_package(glfw3 CONFIG REQUIRED)
#  target_link_libraries(main PRIVATE glfw)

# 添加包含目录
target_include_directories(VulkanTest PUBLIC ${VK_SDK_INCLUDE} ${GLFW_SDK_LIB})

##  GLFW
#set(GLFW_INCLUDE_DIR ../ThirdParty/glfw/include)
#find_package(glfw3 CONFIG REQUIRED)
#添加依赖的头文件
#include_directories(${GLFW_INCLUDE_DIR})

# TODO: 如有需要，请添加测试并安装目标。
