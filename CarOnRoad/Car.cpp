#include "Car.h"
#include "glut.h"

#include <cmath>


Car::Car()
{
	xPosition = 120;
	yPosition = 20;
	radius = 5;
	angle = 2;
	message = "";
	isRightLane = true;
}

void Car::Draw()
{
	//message = "gtrrr";
	glRasterPos2f(100, 90);
	for (int i = 0; i<message.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);


	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 1.0, 1.0); //цвет

	int amountSegments = 30;
	for (int i = 0; i < amountSegments; i++)
	{
		float angle = 2.0 * 3.1415926 * float(i) / float(amountSegments);

		float dx = radius * cosf(angle);
		float dy = radius * sinf(angle);

		glVertex2f(xPosition + dx, yPosition + dy);
	}
	glEnd();
	glBegin(GL_LINES);//начало рисования линий
	glColor3f(1.0, 1.0, 1.0); //цвет
	glVertex2f(xPosition, yPosition);
	glVertex2f(xPosition+radius*cos(angle), yPosition + radius * sin(angle));
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

void Car::MoveForward(Road tRoad)
{
	float tXPosition;
	float tYPosition;
	tXPosition = xPosition + cos(angle);
	tYPosition = yPosition + sin(angle);
	if (tXPosition + radius <= tRoad.GetXRightSolidLine() && tXPosition - radius >= tRoad.GetXLeftSolidLine())
	{
		xPosition = tXPosition;
		yPosition = tYPosition;
		message = "";
	}
	else
	{
		message = "intersection";
	}
}

void Car::RotateLeft()
{
	angle += 0.3;
}

void Car::RotateRight()
{
	angle -= 0.3;
}

Car::~Car()
{
}
