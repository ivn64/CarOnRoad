#pragma once

class Car
{
	int xPosition;
	int yPosition;
	int radius;
public:
	Car();
	void Draw();
	int GetRadius();
	void SetRadius(int); 
	int GetXPosition();
	void SetXPosition(int);
	int GetYPosition();
	void SetYPosition(int);
	~Car();
};

