#pragma once

#include <glc2d.h>
#include <string>

using std::string;

class GraphicEngine
{
public:
	struct GAME_WINDOW
	{
		int	   x, y;
		int	   scnW, scnH;
		string name;
		bool   bWindowed { true };
		float  scnScale  { 1.0f };
	};

public:
	int Init(const GraphicEngine::GAME_WINDOW& gameWindow);
	int Destroy();
	int Run();

	static int Update();
	static int Render();

public:
	void SetColor(unsigned long color);
};