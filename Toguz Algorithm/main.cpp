#include "Application.h"

int main(int argc, char* argv[])
{
	Application* app = Application::getApp();
	app->setExePath(argv[0]);
	app->run();

	return 0;
}
