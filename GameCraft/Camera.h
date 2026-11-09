#pragma once

#include "GameObject.h"
#include <map>

class Camera : public GameObject
{
public:
	int Init();
	int Draw();

	VEC2 GetScreenCenter() const;
	VEC2 GetViewOffset() const;

	void AddObject(int layer, GameObject* gameObject);
	void ClearObjects();
	void RemoveObject(int layer, GameObject* gameObject);

protected:
	VEC2 m_CameraSize {};

	std::multimap<int, GameObject*> m_RenderList;
};

