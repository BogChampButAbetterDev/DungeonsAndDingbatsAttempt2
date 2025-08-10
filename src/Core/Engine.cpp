#include "Engine.h"
#define GLFW_STATIC

Engine::Engine(int w, int h, const std::string t)
	: width(w), height(h), title(t), window(nullptr)
{
}

Engine::~Engine()
{
	if (window) glfwDestroyWindow(window);
	glfwTerminate();
}

void glfwErrorCallback(int error, const char* description) {
	std::cerr << "GLFW Error (" << error << "): " << description << std::endl;
}

bool Engine::init()
{
	glfwSetErrorCallback(glfwErrorCallback); 

	if (!glfwInit())
	{
		std::cerr << "Cannot init GLFW\n";
		return false;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	if (!window)
	{
		std::cerr << "Cannot create window\n";
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(window);

	glEnable(GL_DEPTH_TEST);

	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Cannot init GLEW\n";
		return false;
	}

	glViewport(0, 0, width, height);

	return true;
}

void Engine::run(float delta)
{
	events();
	update(delta);
	render();
}

void Engine::events()
{
	glfwPollEvents();
}

void Engine::update(float delta)
{

}

void Engine::render()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glfwSwapBuffers(window);
}

void Engine::cleanup()
{
}


