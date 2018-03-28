#pragma once

class Car
{
	float xPosition;
	float yPosition;
	float radius;
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
	void RotateRight();
	~Car();
};

