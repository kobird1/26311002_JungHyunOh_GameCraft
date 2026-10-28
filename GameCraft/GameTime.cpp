#include "GameTime.h"
#include <iostream>
#include <thread>
#include <glc2d.h>
using namespace std;

int GameTime::Init()
{
	beginTime = g2_TimeGetTime();
	eplapsedTime = {};
	deltaTime = {};			// millisecond

	return 0;
}

int GameTime::Update()
{
	this_thread::sleep_for(chrono::milliseconds(10));

	auto currentTime = g2_TimeGetTime();
	auto prevTime = eplapsedTime;
	eplapsedTime = currentTime - beginTime;
	deltaTime = eplapsedTime - prevTime;

	return 0;
}