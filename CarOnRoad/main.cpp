#pragma comment(lib, "opengl32.lib")

#pragma comment(lib, "glut32.lib")
#include "glut.h"
#include "Car.h"
#include "Road.h"

Car myCar;
Road myRoad;

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	myRoad.Draw();
	myCar.Draw();
	glutSwapBuffers();
}

void processSpecialKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
	{
		myCar.MoveForward(myRoad);
	}
	break;
	case GLUT_KEY_DOWN:
	{
		
	}
	break;
	case GLUT_KEY_LEFT:
	{
		myCar.RotateLeft();
	}
	break;
	case GLUT_KEY_RIGHT:
	{
		myCar.RotateRight();
	}
	break;
	}
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(100, 140);
	glutCreateWindow("CarOnRoad");
	glClearColor(0.0, 0.5, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 200, 0, 200);
	glutDisplayFunc(Display);
	glutIdleFunc(Display);
	glutSpecialFunc(processSpecialKeys);
	glutMainLoop();
}