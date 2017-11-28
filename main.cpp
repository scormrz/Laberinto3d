#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#define M_PI 3.14159265358979323846
using namespace std;

GLfloat xi = -8.5;
GLfloat yi = -8;
//GLint numLados = 3;
GLint escala = 1;

GLdouble anguloY = 0;
GLdouble anguloX = 0;
GLdouble anguloZ = 0;

void muro(int x,int y);


//Matriz
int mapa[17][22] = {
	{1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,1,1},
	{1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1},
	{1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
	{1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1},
	{1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1},
	{1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1},
	{1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1},
	{1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1},
	{1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1}};


void init(void){
	glClearColor(0.0, 0.0, 0.0, 0.0);
}


void ArrowKey(int key, int x, int y){
	switch (key)
	{
	case GLUT_KEY_RIGHT:
		cout << "Xi= "<< xi << endl;
		cout << "Yi= "<< yi << endl;
		if (xi < 10)
			xi += 0.5;
		break;
		
	case GLUT_KEY_LEFT:
		cout << "Xi= "<< xi << endl;
		cout << "Yi= "<< yi << endl;
		if (xi > -10)
			xi -= 0.5;
		break;
		
	case GLUT_KEY_UP:
		cout << "Xi= "<< xi << endl;
		cout << "Yi= "<< yi << endl;
		if (yi < 10)
			yi += 0.5;
		break;
		
	case GLUT_KEY_DOWN:
		cout << "Xi= "<< xi << endl;
		cout << "Yi= "<< yi << endl;
		if (yi > -10)
			yi -= 0.5;
		break;
	case GLUT_KEY_HOME:
		if (escala > 5)
			escala = 5;
		escala = escala + 1;
		break;
	case GLUT_KEY_PAGE_UP:
		if (escala <= 2)
			escala = 2;
		escala = escala - 1;
		break;
		
	case GLUT_KEY_PAGE_DOWN:
		anguloY += 5;
		
		
		break;
		
	case GLUT_KEY_END:
		anguloY -= 5;
		break;
	case GLUT_KEY_F2:
		anguloZ += 5;
		
	case GLUT_KEY_F3:
		anguloX -= 5;
		
		
		
	default:
		break;
	}
	
	glutPostRedisplay();
}



void display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glTranslatef(xi, yi, -3);
	glScaled(escala, escala, 1.0);
	//gluPerspective(40.0, 1.0, 1.0, 30.0);
	
	glRotated(anguloX, 1.0, 0.0, 0.0);
	glRotated(anguloY,0.0,1.0,0.0);
	glRotated(anguloZ, 0.0, 0.0, 1.0);
	
	
	//Suelo
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	glVertex3f(0, 0, 0); 
	glVertex3f(0,17,0);      
	glVertex3f(17, 17, 0);     
	glVertex3f(17, 0, 0);  
	glEnd();
	
	for (int i=0;i<17;i++)
	{
		for (int j=0;j<22;j++)
		{
			if(mapa[i][j]==1)
			{
				muro(i,j);
			}
		}
	}
	
	
	
	
	/////////////////////////////////////////////

	
	glPopMatrix(); // Cierra la matriz
	glFlush();
	glutSwapBuffers();
}

void muro(int x,int y)
{
	//Frontal Y
	glBegin(GL_POLYGON);
	glColor3f(0,0,1);
	glVertex3f(x,y,1);
	glVertex3f(x + 1,y,1);
	glVertex3f(x + 1,y + 1,1);
	glVertex3f(x,y + 1,1);
	glEnd();
	
	//lateral izquierdo
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,0.0);
	glVertex3f(x,y,0.0);
	glVertex3f(x,y,1.0);
	glVertex3f(x,y + 1,1.0);
	glVertex3f(x,y + 1,0.0);
	glEnd();
	
	//Lateral derecha
	glBegin(GL_POLYGON);
	glColor3f(0.5,1,1);
	glVertex3f(x+1,y,0.0);
	glVertex3f(x+1,y,1.0);
	glVertex3f(x+1,y + 1,1.0);
	glVertex3f(x+1,y + 1,0.0);
	glEnd();
	
	//Lateral abajo y
	glBegin(GL_POLYGON);
	glColor3f(0.8,0.4,0);
	glVertex3f(x+1,y,0.0);
	glVertex3f(x+1,y,1.0);
	glVertex3f(x,y,1.0);
	glVertex3f(x,y,0.0);
	glEnd();
	
	//Lateral Arriba y
	glBegin(GL_POLYGON);
	glColor3f(1,1,0.2);
	glVertex3f(x+1,y+1,0.0);
	glVertex3f(x+1,y+1,1.0);
	glVertex3f(x,y + 1,1.0);
	glVertex3f(x,y + 1,0.0);
	glEnd();
	
	
}

void reshape(int w, int h){
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();//Inicializa la matriz de proyeccion
	glOrtho(-10.0, 10.0, -10.00, 10.0, 0.1, 20.0); // WorkSpace
	glMatrixMode(GL_MODELVIEW); // cambiamos la matrix :D
	
}
void keyboard(unsigned char key, int x, int y){
	switch (key)
	{
	case 27:
		exit(0);
		break;
	}
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(650, 650);
	
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Laberinto");
	glEnable(GL_DEPTH_TEST);
	init();
	
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(ArrowKey);
	glutMainLoop();
	return 0;
}

