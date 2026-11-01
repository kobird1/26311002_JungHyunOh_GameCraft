#include "GameObject.h"

GameObject::~GameObject()
{

}

int GameObject::Init()
{
	return 0;
}

int GameObject::Destroy()
{
	return 0;
}

int GameObject::Update()
{
	return 0;
}

int GameObject::Render()
{
	return 0;
}

VEC2 Transform::GetDrawPosition(int width, int height) const
{
    VEC2 center { position.x - width  * scale.x * 0.5f
                , position.y - height * scale.y * 0.5f };

    return center;
}