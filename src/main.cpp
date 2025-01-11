/*
 * @Author: Vanish
 * @Date: 2024-12-19 17:01:06
 * @LastEditTime: 2025-01-11 22:35:34
 * Also View: http://vanishing.cc
 * Contract Me: http://qunchengxiao.me
 * Copyright@ http://www.wtfpl.net/
 */
#include <exception>
#define GLFW_INCLUDE_VULKAN

#include <iostream>
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

    }
    void RenderLoop()
    {

    }
    void Close()
    {

    }
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