#include "Road.h"
#include "glut.h"

Road::Road()
{
	xLeftSolidLine = 50;
	xRightSolidLine = 150;
	xCenterDottedLine = 100;
	y1Gap1 = 30;
	y2Gap1 = 60;
	y1Gap2 = 140;
	y2Gap2 = 170;
}

Road::~Road()
{

}

void Road::Draw()
{
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);

	glVertex2f(xLeftSolidLine, 0);
	glVertex2f(xLeftSolidLine, 200);

	glVertex2f(xRightSolidLine, 0);
	glVertex2f(xRightSolidLine, 200);

	glVertex2f(xCenterDottedLine, 0);
	glVertex2f(xCenterDottedLine, 30);

	glVertex2f(xCenterDottedLine, 60);
	glVertex2f(xCenterDottedLine, 140);

	glVertex2f(xCenterDottedLine, 170);
	glVertex2f(xCenterDottedLine, 200);

	glEnd();
}

int Road::GetXLeftSolidLine()
{
	return xLeftSolidLine;
}

int Road::GetXRightSolidLine()
{
	return xRightSolidLine;
}

int Road::GetXCenterDottedLine()
{
	return xCenterDottedLine;
}

int Road::GetY1Gap1()
{
	return y1Gap1;
}

int Road::GetY2Gap1()
{
	return y2Gap1;
}

int Road::GetY1Gap2()
{
	return y1Gap2;
}

int Road::GetY2Gap2()
{
	return y2Gap2;
}
