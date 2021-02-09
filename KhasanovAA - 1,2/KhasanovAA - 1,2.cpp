
#include <iostream>
#include <glut.h>

void init(void);
void khasanov(void);
// KhasanovAinur|4103|2021 year
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1440, 900); // окно винды
	glutInitWindowPosition(250, 100); // положение окна
	glutCreateWindow("Khsanov AA - project lab 1-2");
	init();
	glutDisplayFunc(khasanov);
	glutMainLoop();
}

void init(void)
{
	glClearColor(1.0, 0.5, 0.2, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10.0, 10.0, -10.0, 10.0); //x-x; y-y
}
void khasanov(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(10, 10, 1000, 850); //положение и размеры порта просмотра

#pragma region Квадраты сверху
	// красная
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(10);
	glBegin(GL_POINTS);
	glVertex2f(-9.0, 9.0);
	glEnd();
	//2ая зелень
	glColor3f(0.0, 1.0, 0.0);
	glPointSize(10);
	glBegin(GL_POINTS);
	glVertex2f(-8, 9);
	glEnd();
	// синий правый
	glColor3f(0.1, 0.3, 1.0);
	glPointSize(15);
	glBegin(GL_POINTS);
	glVertex2f(-7, 9);
	glEnd();
#pragma endregion Квадраты сверху

#pragma region Линии
	// линия тонкая сверху
	glLineWidth(5);
	glColor3f(1, 1, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-10, 10);
	glVertex2f(10, 10);
	glEnd();

	// линия тонкая пониже
	glLineWidth(10);
	glColor3f(1, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-10, 8.5);
	glVertex2f(10, 8.5);
	glEnd();

	// линия снизу
	glLineWidth(10);
	glColor3f(0.1, 0.1, 0.1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(10, -10);
	glVertex2f(-10, -10);
	glEnd();

	// линия  справа
	glLineWidth(20);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 1, 0);
	glVertex2f(10, 10); // x,y - начало 1 точка
	glColor3f(1, 0, 0);
	glVertex2f(10, -10);  // x,y - конец 2 точка
	glEnd();

	// линия слева
	glLineWidth(20);
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 0, 0);
	glVertex2f(-10, -10);
	glColor3f(0, 1, 0);
	glVertex2f(-10, 10);
	glEnd();

	// cредняя линия
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(4, 200); // шаг,
	glLineWidth(4);
	glColor3f(1, 0.5, 0);
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-10, 0);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(10, 0);
	glEnd();
	glDisable(GL_LINE_STIPPLE);
#pragma endregion Линии

#pragma region Фигуры по линиям
	// треугольник по линиям
	glLineWidth(5);
	glColor3f(1, 1, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-8, 1);
	glVertex2f(-9, 1);
	glVertex2f(-9, 3);
	glEnd();

	//2ой сверху
	glLineWidth(5);
	glColor3f(1, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-7.5, 3);
	glVertex2f(-7.5, 1);
	glVertex2f(-8.5, 3);
	glEnd();

	// ломаный треуг
	glLineWidth(2);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(1, 1, 0);
	glVertex2f(-6.5, 3);
	glVertex2f(-6.5, 1);
	glVertex2f(-6, 3);
	glColor3f(1, 0.4, 0.2);
	glVertex2f(-5.7, 1);
	glVertex2f(-5.4, 2.5);
	glVertex2f(-5, 1.5);
	glEnd();
	// перевернутый треуг
	glLineWidth(2);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 0, 0);
	glVertex2f(-4.5, 3);
	glVertex2f(-4, 1);
	glVertex2f(-3.8, 2);
	glColor3f(1, 0, 1);
	glVertex2f(-3.4, 4);
	glVertex2f(-3.0, 1);
	glEnd();
	// 2 прямоуг
	glLineWidth(2);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_QUADS);
	glColor3f(0.7, 0, 1);
	glVertex2f(-2.3, 1.5);
	glVertex2f(-1.7, 1);
	glVertex2f(-1.7, 2.9);
	glVertex2f(-2.3, 3.2);
	glVertex2f(-1.6, 1.5);
	glVertex2f(-1, 1);
	glVertex2f(-1, 2.9);
	glVertex2f(-1.6, 2.9);
	glEnd();

	// 2,4,6,8 
	// 1,3,5,7
	glLineWidth(2);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_QUAD_STRIP);
	glColor3f(0.2, 0, 0.4);
	glVertex2f(-0.8, 1);
	glVertex2f(-0.8, 3);
	glVertex2f(-0.3, 1.2);
	glVertex2f(-0.3, 2.8); 
	glVertex2f(0.3, 0.9);
	glColor3f(0, 0.6, 1);
	glVertex2f(0.3, 2.3);
	glVertex2f(0.9, 1.1);
	glVertex2f(0.9, 3);
	glEnd();

	// 8 ломаная
	glLineWidth(2);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
	glVertex2f(2, 0.9);
	glVertex2f(2.3, 1.2);
	glVertex2f(3, 1.7);
	glVertex2f(4.7, 1);
	glVertex2f(4.6, 3);
	glVertex2f(2.5, 2.6);
	glVertex2f(2.2, 1.9);
	glVertex2f(1.7, 4);
	glEnd();


#pragma endregion Фигуры по линиям

#pragma region Фигуры по линиям FILL
	//треугольник перевернутый	
	glLineWidth(5);
	glColor3f(1, 1, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-8, -1);
	glVertex2f(-9, -1);
	glVertex2f(-9, -3);
	glEnd();

	//2ой сверху перевернутый
	glLineWidth(5);
	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-7.5, -3);
	glVertex2f(-7.5, -1);
	glVertex2f(-8.5, -3);
	glEnd();

	// ломаный треуг
	glLineWidth(2);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(1, 1, 0);
	glVertex2f(-6.5, -3);
	glVertex2f(-6.5, -1);
	glVertex2f(-6, -3);
	glColor3f(1, 0.4, 0.2);
	glVertex2f(-5.7, -1);
	glVertex2f(-5.4, -2.5);
	glVertex2f(-5, -1.5);
	glEnd();

	// перевернутый треуг
	glLineWidth(2);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.4, 1, 0);
	glVertex2f(-4.5, -3);
	glVertex2f(-4, -1);
	glVertex2f(-3.8, -2);
	glColor3f(1, 0.5, 0.1);
	glVertex2f(-3.4, -4);
	glVertex2f(-3.0, -1);
	glEnd();
	// 2 прямоуг
	glLineWidth(2);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_QUADS);
	glColor3f(0.7, 0, 1);
	glVertex2f(-2.3, -1.5);
	glVertex2f(-1.7, -1);
	glVertex2f(-1.7, -2.9);
	glVertex2f(-2.3, -3.2);
	glVertex2f(-1.6, -1.5);
	glVertex2f(-1, -1);
	glVertex2f(-1, -2.9);
	glVertex2f(-1.6, -2.9);
	glEnd();

	// 2,4,6,8 
	// 1,3,5,7
	glLineWidth(2);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_QUAD_STRIP);
	glColor3f(0.2, 0, 0.4);
	glVertex2f(-0.8, -1);
	glVertex2f(-0.8, -3);
	glVertex2f(-0.3, -1.2);
	glVertex2f(-0.3, -2.8);
	glVertex2f(0.3, -0.9);
	glColor3f(0, 0.6, 1);
	glVertex2f(0.3, -2.3);
	glVertex2f(0.9, -1.1);
	glVertex2f(0.9, -3);
	glEnd();

	// 8 ломаная
	glLineWidth(2);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
	glVertex2f(2, -0.9);
	glVertex2f(2.3, -1.2);
	glVertex2f(3, -1.7);
	glVertex2f(4.7, -1);
	glVertex2f(4.6, -3);
	glVertex2f(2.5, -2.6);
	glVertex2f(2.2, -1.9);
	glVertex2f(1.7, -4);
	glEnd();

#pragma endregion Фигуры по линиям FILL

	glFlush(); // конец
}
