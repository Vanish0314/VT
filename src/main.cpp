#include <iostream>
#include <exception>
#include <memory>

#define GLFW_INCLUDE_VULKAN

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class HelloTriangleApplication
{
public:
    void Run()
    {
        Init();
        RenderLoop();
        Close();
    }
private:
    void Init()
    {
        InitWindow();
        InitVulkan();
    }
    void RenderLoop()
    {
        while(!glfwWindowShouldClose(m_window))
        {
            glfwPollEvents();
        }
    }
    void Close()
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }
private:
    void InitWindow()
    {
        glfwInit();

        glfwWindowHint(GLFW_CLIENT_API,GLFW_NO_API); // 显式阻止创建opengl上下文
        
        m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);
    }
    void InitVulkan()
    {

    }
private:
    unsigned short m_width{1920};
    unsigned short m_height{1080};
    const char *m_title{"VulkanTriangle"};
    GLFWwindow* m_window; // 裸指针注意
};


int main(int argc, char** argv) {

    std::cout << "hello world!" << std::endl;

    HelloTriangleApplication app;
    try
    {
        app.Run();
    }
    catch(const std::exception &err)
    {
        std::cerr<<err.what()<<std::endl;
    }

    return 0;
}