#pragma once

#include "Road.h"
#include <string>

using namespace std;

class Car
{
	float xPosition;
	float yPosition;
	float radius;
	float angle;
	string message;
	bool isRightLane;
	bool isTurn;
	float yTurnPosition;
public:
	Car();
	void Draw();
	int GetRadius();
	void SetRadius(int); 
	int GetXPosition();
	void SetXPosition(int);
	int GetYPosition();
	void SetYPosition(int);
	void MoveForward(Road);
	void RotateLeft();
	void RotateRight();
	~Car();
};

