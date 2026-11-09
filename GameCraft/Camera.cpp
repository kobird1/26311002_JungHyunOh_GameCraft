#include "Camera.h"

int Camera::Init()
{
	m_CameraSize.x = g2_GetScnW();
	m_CameraSize.y = g2_GetScnH();

	return 0;
}

int Camera::Draw()
{
	VEC2 offset = GetViewOffset();
	for (const auto& object : m_RenderList)
	{
		object.second->Render(offset);
	}

	return 0;
}

VEC2 Camera::GetScreenCenter() const
{
	VEC2 center { m_CameraSize.x * 0.5f
			    , m_CameraSize.y * 0.5f };

	return center;
}

VEC2 Camera::GetViewOffset() const
{
	VEC2 center = GetScreenCenter();

	VEC2 offset = { center.x - m_Transform.position.x
				  , center.y - m_Transform.position.y };
	return offset;
}

void Camera::AddObject(int layer, GameObject* gameObject)
{
	m_RenderList.emplace(layer, gameObject);
}

void Camera::ClearObjects()
{
	m_RenderList.clear();
}

void Camera::RemoveObject(int layer, GameObject* gameObject)
{
	const auto range = m_RenderList.equal_range(layer);

	for (auto it = range.first; it != range.second;)
	{
		if (it->second == gameObject)
		{
			it = m_RenderList.erase(it);
		}
		else
		{
			++it;
		}
	}

}
