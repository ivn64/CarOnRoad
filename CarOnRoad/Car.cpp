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
	isTurn = false;
}

void Car::Draw()
{
	glRasterPos2f(5, 90);
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
		if (isRightLane == true && tYPosition > yPosition || isRightLane == false && tYPosition < yPosition)
		{
			message = "ok";
			isTurn = false;
		}
		else
		{
			if (isTurn == true && isRightLane == false && yTurnPosition + 5 > tYPosition)
				message = "turn";
			else
			{
				if (isTurn == true && isRightLane == true && yTurnPosition - 5 < tYPosition)
					message = "turn";
				else
					message = "oncoming traffic";
			}
		}
		if (tXPosition<tRoad.GetXCenterDottedLine() && isRightLane == true || tXPosition>tRoad.GetXCenterDottedLine() && isRightLane == false)
		{
			if (tYPosition > tRoad.GetY1Gap1() && tYPosition<tRoad.GetY2Gap1() || tYPosition>tRoad.GetY1Gap2() && tYPosition < tRoad.GetY2Gap2())
			{
				message = "turn";
				isTurn = true;
				yTurnPosition = tYPosition;
			}
			else
			{
				message = "intersection";
			}
		}
		xPosition = tXPosition;
		yPosition = tYPosition;
		if (xPosition < tRoad.GetXCenterDottedLine())
			isRightLane = false;
		else
			isRightLane = true;
	}
	else
	{
		message = "out of road";
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
