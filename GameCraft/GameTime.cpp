#include "GameTime.h"
#include <chrono>

using namespace std;

int GameTime::Init()
{
	
	//beginTime	 = chrono::system_clock::now();
	eplapsedTime = {};
	deltaTime    = {};
	return 0;
}

int GameTime::Update()
{
	eplapsedTime = {};
	deltaTime = {};
	return 0;
}