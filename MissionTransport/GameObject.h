#pragma once
#include <string>


class GameObject
{
private:
	int X;
	int Y;
	std::string pic;
public:
	bool operator== (GameObject other) {
		return(&other == this);
	}
	GameObject();
	GameObject(int X,int Y, std::string pic);
	GameObject(int X, int Y);
	~GameObject();
	void printGameObject();
	std::string getpicture();
	int getX();
	int getY();
	void setX(int);
	void setY(int);
	void setPic(std::string);
};

