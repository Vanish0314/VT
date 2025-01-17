#include "vulkan/vulkan_core.h"
#include <cstdint>
#include <iostream>
#include <exception>
#include <memory>
#include <vector>

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
        CreateInstance();
        SetValidationLayer();
        CreateWindowSurface();
        SetPhysicalDevice();
        CreateLogicalDevice();
        CreateSwapChain();
        CreateImageViews();
        CreateRenderPass();
        CreateGraphicsPipeline();
        CreateFrameBuffers();
        CreateCommandPool();
        CreateCommanBuffers();
    }
private:
    void CreateInstance()
    {
        SetVkAppInfo();
        SetVkInstanceCreateInfo();
        SetVkInstance();
    }
    void SetVkAppInfo()
    {
        m_vkAppInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        m_vkAppInfo.pApplicationName = "Hello Triangle";
        m_vkAppInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        m_vkAppInfo.pEngineName = "No Engine";
        m_vkAppInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        m_vkAppInfo.apiVersion = VK_API_VERSION_1_0;
    }
    void SetVkInstanceCreateInfo()
    {
        m_vkCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        m_vkCreateInfo.pApplicationInfo = &m_vkAppInfo;

        uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions;
        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

        m_vkCreateInfo.enabledExtensionCount = glfwExtensionCount;
        m_vkCreateInfo.ppEnabledExtensionNames = glfwExtensions;

        m_vkCreateInfo.enabledLayerCount = 0;
    }
    void SetVkInstance()
    {
        if (vkCreateInstance(&m_vkCreateInfo, nullptr, &m_vkInstance) != VK_SUCCESS) 
        {
            throw std::runtime_error("[HelloTriangleApplication.class]failed to create instance!");
        }
    }
private: // Validation Layer
    void SetValidationLayer() //TODO
    {

    }
    bool CheckValidationLayerSupport()
    {
        uint32_t layerCount;
        vkEnumerateInstanceLayerProperties(&layerCount, nullptr);//获取可用校验层数量
        std::vector<VkLayerProperties> availableLayers(layerCount);
        vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());// 存入校验层

        return false;
    }
private:
    void CreateWindowSurface() //TODO
    {

    }
private:
    void SetPhysicalDevice() //TODO
    {

    }
private:
    void CreateLogicalDevice() //TODO
    {

    }
private:
    void CreateSwapChain() //TODO
    {

    }
private:
    void CreateImageViews() //TODO
    {

    }
private:
    void CreateRenderPass() //TODO
    {

    }
private:
    void CreateGraphicsPipeline() //TODO
    {

    }
private:
    void CreateFrameBuffers() //TODO
    {

    }
private:
    void CreateCommanBuffers() //TODO
    {

    }
private:
    void CreateCommandPool() //TODO
    {

    }
private:
#ifdef ENABLE_VULKAN_VALIDATION_LAYER
    const bool m_EnableVulkanValidatioinLayer = true;
#else
    const bool m_EnableVulkanValidatioinLayer = false;
#endif
private: //Window
    unsigned short m_width{1920};
    unsigned short m_height{1080};
    const char *m_title{"VulkanTriangle"};
    GLFWwindow* m_window; // WARN 裸指针注意
private:
    VkInstance m_vkInstance;
    VkApplicationInfo m_vkAppInfo;
    VkInstanceCreateInfo m_vkCreateInfo;

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