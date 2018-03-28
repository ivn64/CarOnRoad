#include "Car.h"
#include "glut.h"

#include <cmath>


Car::Car()
{
	xPosition = 20;
	yPosition = 20;
	radius = 5;
}

void Car::Draw()
{
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 1.0, 1.0); //цвет красный

	int amountSegments = 30;
	for (int i = 0; i < amountSegments; i++)
	{
		float angle = 2.0 * 3.1415926 * float(i) / float(amountSegments);

		float dx = radius * cosf(angle);
		float dy = radius * sinf(angle);

		glVertex2f(xPosition + dx, yPosition + dy);
	}
	glEnd();
}

int Car::GetRadius()
{
	return radius;
}

void Car::SetRadius(int r)
{
	radius = r;
}

int Car::GetXPosition()
{
	return xPosition;
}

void Car::SetXPosition(int x)
{
	xPosition = x;
}

int Car::GetYPosition()
{
	return yPosition;
}

void Car::SetYPosition(int y)
{
	yPosition = y;
}

Car::~Car()
{
}
