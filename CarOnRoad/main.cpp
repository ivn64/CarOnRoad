// WinAPI
#include <Windows.h>
#include <tchar.h>
#include <cmath>

// OpenGL
#pragma comment(lib, "opengl32.lib")

// GLUT
#pragma comment(lib, "glut32.lib")
#include "glut.h"
#include "Car.h"
#include "Road.h"

Car myCar;
Road myRoad;

void draw_string_bitmap(void *font, const char* string)
{
	while (*string)
		glutBitmapCharacter(font, *string++);
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT); /*������� �������� ������*/
	myRoad.Draw();
	myCar.Draw();


	/*char str[] = "EEEEEEEEEEEE";
	glRasterPos2f(100, 90);
	for (int i = 0; str[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);*/

	glutSwapBuffers();
	//glFlush(); /*������������ ��, ��� �� �������*/
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
	glutInit(&argc, argv); //������� ��������� ������� main
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //������������� ������� � ����� ��������(GLUT_DOUBLE) � ������ RGB 24 ������ ����
	glutInitWindowSize(700, 700); //������������� ������ ����
	glutInitWindowPosition(100, 140); //������������ ���� (x,y)
	glutCreateWindow("CarOnRoad"); //������� ��� �������� ����
	glClearColor(0.0, 0.5, 0.0, 0.0);//�������� ����� �����
	glMatrixMode(GL_PROJECTION); //�������� 2-� ������ ���
	glLoadIdentity();
	//glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0); /*����� � ����� �������� ����������� ���������� x,y,z*/

	gluOrtho2D(0, 200, 0, 200);

	glutDisplayFunc(Display); //��������� ������� ���������, ������� �� �������� �����

	glutIdleFunc(Display);//

	glutSpecialFunc(processSpecialKeys); //���������� ����������� ��������
	glutMainLoop(); //��������� ��� - �������, ����������� �������� ����,����������� ��� � �������� ����
}