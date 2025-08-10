#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

class Engine
{
public:
	Engine(int width, int height, const std::string title);
	~Engine();

	bool init();
	void run(float delta);

	GLFWwindow* getWindow() const { return window; }

private:
	GLFWwindow* window;
	int width, height;
	std::string title;

	void events();
	void update(float delta);
	void render();
	void cleanup();
};
