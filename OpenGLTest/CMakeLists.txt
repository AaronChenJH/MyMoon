# CMakeList.txt: VulkanTest 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#

# 将源代码添加到此项目的可执行文件。
add_executable (OpenGLTest "OpenGl_Main.cpp")

# link_libraries用来链接静态库，target_link_libraries用来链接导入库，
target_link_libraries(OpenGLTest ${LIBS})


# TODO: 如有需要，请添加测试并安装目标。
