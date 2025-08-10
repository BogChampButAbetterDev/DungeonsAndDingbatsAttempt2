#include <iostream>
#include "Core/Engine.h"

int main()
{
	Engine e(1280, 720, "D&D");

	if (!e.init())
		return 1;

	float lastTime = (float)glfwGetTime();
	while (!glfwWindowShouldClose(e.getWindow()))
	{
		float now = (float)glfwGetTime();
		float delta = now - lastTime;
		lastTime = now;

		e.run(delta);
	}
}
