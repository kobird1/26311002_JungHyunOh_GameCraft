#include <iostream>
#include "App.h"
using namespace std;

App* g_pApp;

int main()
{
	App app;
	g_pApp = &app;

	if (0 > g_pApp->Init())
		return 0;

	auto r = g_pApp->Run();
	{

	}

	return 0;
}

