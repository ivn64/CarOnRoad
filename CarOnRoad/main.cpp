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

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT); /*Функция очищения экрана*/

	myRoad.Draw();
	myCar.Draw();
	glutSwapBuffers();
	//glFlush(); /*Отрисовывает всё, что мы описали*/
}

void processSpecialKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
	{
		myCar.MoveForward();
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

	}
	break;
	}
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv); //Передаём параметры функции main
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //Иницилизируем дисплей с двумя буферами(GLUT_DOUBLE) в фрмате RGB 24 битный цвет
	glutInitWindowSize(700, 700); //Устанавливаем размер окна
	glutInitWindowPosition(100, 140); //Расположение окна (x,y)
	glutCreateWindow("CarOnRoad"); //Команда для создания окна
	glClearColor(0.0, 0.0, 0.0, 0.0);//Заполним экран фоном
	glMatrixMode(GL_PROJECTION); //Настроим 2-х мерный вид
	glLoadIdentity();
	//glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0); /*Задаём в каких пределах изменяеются координаты x,y,z*/

	gluOrtho2D(0, 200, 0, 200);

	glutDisplayFunc(Display); //Объявляем функции рисования, которую мы создадим позже

	glutIdleFunc(Display);//

	glutSpecialFunc(processSpecialKeys); //считывание специальных символов
	glutMainLoop(); //Буквально это - функция, завершающая описание окна,переводящая нас в основной цикл
}