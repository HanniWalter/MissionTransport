#include "GameObject.h"



GameObject::GameObject()
{
}

GameObject::GameObject(int X, int Y, std::string pic)
{
	this->X = X;
	this->Y = Y;
	this->pic = pic;
}

GameObject::GameObject(int X, int Y)
{
	GameObject(X, Y, std::string("None"));
}


GameObject::~GameObject()
{
}

std::string GameObject::getpicture()
{
	return this->pic;
}

int GameObject::getX()
{
	return this->X;
}

int GameObject::getY()
{
	return this->Y;
}

void GameObject::setX(int X)
{
	this->X = X;
}

void GameObject::setPic(std::string pic)
{
	this->pic = pic;
}

void GameObject::setY(int Y)
{
	this->Y = Y;
}

