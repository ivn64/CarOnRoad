#pragma once

class Car
{
	int xPosition;
	int yPosition;
	int radius;
	float angle;
public:
	Car();
	void Draw();
	int GetRadius();
	void SetRadius(int); 
	int GetXPosition();
	void SetXPosition(int);
	int GetYPosition();
	void SetYPosition(int);
	void MoveForward();
	void RotateLeft();
	~Car();
};

