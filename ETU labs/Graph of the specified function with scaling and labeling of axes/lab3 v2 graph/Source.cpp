#include <GL/glut.h >
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

POINTFLOAT* graph = NULL;
FLOAT MAXY, MINY;
int count;
GLint Width = 1024, Height = 450;
void InitGraph(float start, float finish, int counttmp)
{
	count = counttmp;
	graph = new POINTFLOAT[count];
	float dx = (finish - start) / (count - 1);
	MAXY = sin(start) * sin(start) - sqrt(start);
	MINY= sin(start) * sin(start) - sqrt(start);
	for (int i = 0; i < count; i++)
	{
		graph[i].x = start;
		graph[i].y = sin(graph[i].x / 4) * sin(graph[i].x / 4) - sqrt(graph[i].x);
		start += dx;
		if (graph[i].y > MAXY)
			MAXY = graph[i].y;
		if (graph[i].y < MINY)
			MINY = graph[i].y;
	}
}

void DrawOS(float alpha,float max, float min)
{
	static float d = 0.25;
	glPushMatrix();
	glRotatef(alpha, 0, 0, 1);
	glBegin(GL_LINES);
	glVertex2f(min, min);
	glVertex2f(max, min);
	glVertex2f(max, min);
	glVertex2f(max - d, min + d);
	glVertex2f(max, min);
	glVertex2f(max - d, min - d);
	glEnd();
	glPopMatrix();

}

void DrawGraph()
{

	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < count; i++)
	{
		glVertex2f(graph[i].x, graph[i].y);
	}

	glEnd();
}

void drawText(GLfloat x, GLfloat y, void* font, char* text)
{
	glRasterPos2f(x, y);
	for (int i = 0; text[i] != '\0'; i++)
		glutBitmapCharacter(font, text[i]);
}

void Display()
{

	glClear(GL_COLOR_BUFFER_BIT);


	glLineWidth(2);
	glColor3f(1, 0, 0);

	float d = 0.25;
	glBegin(GL_LINES); // ось ОХ, ось OY
	glVertex2f(graph[0].x-1, MINY-0.5);
	glVertex2f(graph[count-1].x+0.5, MINY-0.5);
	glVertex2f(graph[count - 1].x + 0.5, MINY - 0.5);
	glVertex2f(graph[count - 1].x + 0.5 - d, MINY - 0.5 + d);
	glVertex2f(graph[count - 1].x + 0.5, MINY - 0.5);
	glVertex2f(graph[count - 1].x - d, MINY - 0.5 - d);

	
	glVertex2f(graph[0].x - 0.5, MAXY+0.5);
	glVertex2f(graph[0].x - 0.5, MINY-0.5);
	glVertex2f(graph[0].x - 0.5, MAXY + 0.5);
	glVertex2f(graph[0].x - 0.5 - d, MAXY + 0.5 - d);
	glVertex2f(graph[0].x - 0.5, MAXY + 0.5);
	glVertex2f(graph[0].x - 0.5 + d, MAXY + 0.5 - d);
	glEnd();


	drawText(graph[0].x - 0.5, MAXY + 0.5, GLUT_BITMAP_TIMES_ROMAN_24, (char*)"Y");
	drawText(graph[count - 1].x + 0.5, MINY - 0.5, GLUT_BITMAP_TIMES_ROMAN_24, (char*)"X");
	// разметка
	char buffer[256];
	for (int i = (int)MINY; i < MAXY; i++) {
		double k = 5.0;
		glBegin(GL_LINES);
		glVertex2f(graph[0].x - 0.5 - 1.0 / k, i);
		glVertex2f(graph[0].x - 0.5 + 1.0 / k, i);
		
		glEnd();
		_itoa_s(i, buffer, 10);
		drawText(graph[0].x - 0.5 - 1.0 / k - 1, i, GLUT_BITMAP_TIMES_ROMAN_10, buffer);
	}
	for (int i = (int)graph[0].x; i < graph[count-1].x; i++) {
		double k = 5.0;
		glBegin(GL_LINES);
		glVertex2f(i, MINY-0.5-1.0/k);
		glVertex2f(i, MINY - 0.5 + 1.0 / k);

		glEnd();
		_itoa_s(i, buffer, 10);
		drawText(i, MINY - 0.5 - 1.0 / k-0.25, GLUT_BITMAP_TIMES_ROMAN_10, buffer);
	}


	DrawGraph();


	sprintf_s(buffer, "%s%g","maximum y = ", MAXY);
	drawText(graph[count-1].x-7, MAXY, GLUT_BITMAP_TIMES_ROMAN_24, (char*)buffer);
	glFinish();
}


void Reshape(GLint w, GLint h)
{
	Width = w;
	Height = h;

	
	glViewport(0, 0, w, h);

	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(graph[0].x-2, graph[count-1].x+1, MINY-1, MAXY+1, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void Keyboard(unsigned char key, int x, int y)
{
#define ESCAPE '\033'
	if (key == ESCAPE)
		exit(0);
}


void main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	InitGraph(M_PI, 11 * M_PI, 100);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(Width, Height);
	glutCreateWindow("Графики функций");
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutMainLoop();
}