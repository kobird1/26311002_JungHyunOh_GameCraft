#pragma once

struct GameTime
{
	int Init();
	int Update();

	long long beginTime   {};
	long long eplapsedTime{};
	long long deltaTime   {};
};

