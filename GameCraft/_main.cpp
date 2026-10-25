#include <iostream>
#include "App.h"
using namespace std;

int main()
{
	App app;

	if (0 > app.Init())
		return 0;

	auto r = app.Run();
	{

	}

	return 0;
}

