#include "Road.h"
#include "glut.h"



Road::Road()
{
}


Road::~Road()
{
}

void Road::Draw()
{
	glBegin(GL_LINES);//начало рисования линий
	glColor3f(1.0, 1.0, 1.0); //цвет красный

	glVertex2f(50, 0);
	glVertex2f(50, 200);

	glVertex2f(150, 0);
	glVertex2f(150, 200);

	glVertex2f(100, 0);
	glVertex2f(100, 30);

	glVertex2f(100, 60);
	glVertex2f(100, 140);

	glVertex2f(100, 170);
	glVertex2f(100, 200);

	glEnd();
}