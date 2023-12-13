// VulkanTest.cpp: 定义应用程序的入口点。
//

#include <iostream>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>


#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

//#include "VulkanModule/CMaketest.h"

using namespace std;
//using namespace VulkanModule;

//int main()
//{
//	cout << "Hello CMake." << endl;
//	VulkanModule::myTest tmp;
//	tmp.testCount();
//	return 0;
//}

int main() {
    cout << "Hello CMake Vulkan demo." << endl;
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, 0);
    GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);

    uint32_t extensionCount = 0;
    //vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    std::cout << extensionCount << " extensions supported" << std::endl;

    glm::mat4 matrix;
    glm::vec4 vec;
    auto test = matrix * vec;

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);

    glfwTerminate();

    return 0;
}