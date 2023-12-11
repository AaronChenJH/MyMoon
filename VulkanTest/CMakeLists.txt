# CMakeList.txt: VulkanTest 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#

# 将源代码添加到此项目的可执行文件。
add_executable (VulkanTest "Vulkanmain.cpp")

#arget_link_libraries(VulkanTest PUBLIC VulkanModule)

# Vulkan SDK设置
if(NOT DEFINED ENV{VK_SDK_PATH})
    message(FATAL_ERROR "VK_SDK_PATH not defined!")
endif()
find_package(Vulkan REQUIRED)

set(VK_SDK_PATH $ENV{VK_SDK_PATH})
set(VK_SDK_INCLUDE ${VK_SDK_PATH}/Include)
set(VK_SDK_LIB ${VK_SDK_PATH}/Lib/vulkan-1.lib)

include_directories(${Vulkan_INCLUDE_DIR})
include_directories(${Vulkan_INCLUDE_DIR}/Include)
include_directories(${Vulkan_INCLUDE_DIR}/../Third-Party/Include)
include_directories(${PROJECT_SOURCE_DIR})

message( "PROJECT_SOURCE_DIR" ${PROJECT_SOURCE_DIR})
message( "VK_SDK_INCLUDE" ${Vulkan_INCLUDE_DIR})
#  链接到vulkan库文件
target_link_libraries(VulkanTest PUBLIC ${VK_SDK_LIB} ${LIBS})
# 添加包含目录,为指定目标（target）添加搜索路径
target_include_directories(VulkanTest PUBLIC ${VK_SDK_INCLUDE})


# TODO: 如有需要，请添加测试并安装目标。
