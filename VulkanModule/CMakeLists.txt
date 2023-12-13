# CMakeList.txt: CMaketest 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#

# 将源代码添加到此项目的可执行文件。
# add_executable (VulkanModule "src/CMaketest.cpp" "include/VulkanModule/CMaketest.h")

#if (CMAKE_VERSION VERSION_GREATER 3.12)
 # set_property(TARGET VulkanModule PROPERTY CXX_STANDARD 20)
#endif()

# GLOB_RECURSE 能查到嵌套的目录,CONFIGURE_DEPENDS 动检测目录是否更新
#file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h) 
#add_library(VulkanModule STATIC ${srcs})
# 链接到库文件
#target_include_directories(VulkanModule PUBLIC include)


# TODO: 如有需要，请添加测试并安装目标。
