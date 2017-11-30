// Texturas.cpp: define el punto de entrada de la aplicación de consola.
//
#include <iostream>
#include <GL\glut.h>
#include "ImageLoader.h"
#include <math.h>


#define M_PI 3.14159265358979323846

using namespace std;
double vel =  0.5;
double rotate_y=0; 
double rotate_x=0;
double rotate_z=0;
 
GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;

GLfloat lax = 0.0f;
GLfloat lay = 0.0f;
GLfloat laz = 4.5f;
float scale = 1.0f;

bool bx=false;
bool by=false;
bool bz=false;

GLuint _text1;
GLuint _text2;
GLuint _text3;
GLuint _text4;
GLuint _text5;
GLuint _text6;



GLuint loadTexture(Image* image) {
	GLuint idtextura;
	glGenTextures(1, &idtextura);
	glBindTexture(GL_TEXTURE_2D, idtextura);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	return idtextura;
}


void initRendering() {
	Image* lado1 = loadBMP("1.bmp");
	_text1 = loadTexture(lado1);
	delete lado1;

	Image* lado2 = loadBMP("2.bmp");
	_text2 = loadTexture(lado2);
	delete lado2;

	Image* lado3 = loadBMP("3.bmp");
	_text3 = loadTexture(lado3);
	delete lado3;

	Image* lado4 = loadBMP("4.bmp");
	_text4 = loadTexture(lado4);
	delete lado4;

	Image* lado5 = loadBMP("5.bmp");
	_text5 = loadTexture(lado5);
	delete lado5;

	Image* lado6 = loadBMP("6.bmp");
	_text6 = loadTexture(lado6);
	delete lado6;
}

void cargarTextura(GLuint _textura) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textura);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}


void ArrowKey(int key, int x, int y) {
	//Código	
	switch(key){
	            case GLUT_KEY_RIGHT:
                     X+=1.0;
					break;
                case GLUT_KEY_LEFT:
                     X-= 1.0;
                     break;
                case GLUT_KEY_UP:
                     Y+= 1.0;
                     break;
                case GLUT_KEY_DOWN:
                     Y-= 1.0;
                     break;
                case GLUT_KEY_HOME:
                     scale+=0.5;
                     break;
                case GLUT_KEY_END:
                     scale+=-0.5;
                break;
                }
                
	glutPostRedisplay();
}

void dibujaCubo(){
  
  //LADO FRONTAL: lado multicolor
cargarTextura(_text1);
  glBegin(GL_POLYGON); 	  
	  glTexCoord2f(0.0f, 0.0f);  glVertex3f(  0.5, -0.5, -0.5 );      // P1 es rojo
	  glTexCoord2f(1.0f, 0.0f);  glVertex3f(  0.5,  0.5, -0.5 );      // P2 es verde
	  glTexCoord2f(1.0f, 1.0f);  glVertex3f( -0.5,  0.5, -0.5 );      // P3 es azul
	  glTexCoord2f(0.0f, 1.0f);  glVertex3f( -0.5, -0.5, -0.5 );      // P4 es morado 
  glEnd();
 
  // LADO TRASERO: lado blanco
  cargarTextura(_text2);
  glBegin(GL_POLYGON);	
	  glTexCoord2f(0.0f, 0.0f);  glVertex3f(  0.5, -0.5, 0.5 );
	  glTexCoord2f(1.0f, 0.0f);  glVertex3f(  0.5,  0.5, 0.5 );
	  glTexCoord2f(1.0f, 1.0f);  glVertex3f( -0.5,  0.5, 0.5 );
	  glTexCoord2f(0.0f, 1.0f);  glVertex3f( -0.5, -0.5, 0.5 );
  glEnd();
 
  // LADO DERECHO: lado morado
  cargarTextura(_text3);
  glBegin(GL_POLYGON);
	  glTexCoord2f(0.0f, 0.0f);  glVertex3f( 0.5, -0.5, -0.5 );
	  glTexCoord2f(1.0f, 0.0f);  glVertex3f( 0.5,  0.5, -0.5 );
	  glTexCoord2f(1.0f, 1.0f);  glVertex3f( 0.5,  0.5,  0.5 );
	  glTexCoord2f(0.0f, 1.0f);  glVertex3f( 0.5, -0.5,  0.5 );
  glEnd();
 
  // LADO IZQUIERDO: lado verde
  cargarTextura(_text4);
  glBegin(GL_POLYGON);
	  glTexCoord2f(0.0f, 0.0f);  glVertex3f( -0.5, -0.5,  0.5 );
	  glTexCoord2f(1.0f, 0.0f);  glVertex3f( -0.5,  0.5,  0.5 );
	  glTexCoord2f(1.0f, 1.0f);  glVertex3f( -0.5,  0.5, -0.5 );
	  glTexCoord2f(0.0f, 1.0f);	 glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();
 
  // LADO SUPERIOR: lado azul
  cargarTextura(_text5);
  glBegin(GL_POLYGON);
	  glTexCoord2f(0.0f, 0.0f);  glVertex3f(  0.5,  0.5,  0.5 );
	  glTexCoord2f(1.0f, 0.0f);  glVertex3f(  0.5,  0.5, -0.5 );
	  glTexCoord2f(1.0f, 1.0f);  glVertex3f( -0.5,  0.5, -0.5 );
	  glTexCoord2f(0.0f, 1.0f);  glVertex3f( -0.5,  0.5,  0.5 );
  glEnd();
 
  // LADO INFERIOR: lado rojo
  cargarTextura(_text6);
  glBegin(GL_POLYGON);
	  glTexCoord2f(0.0f, 0.0f);  glVertex3f(  0.5, -0.5, -0.5 );
	  glTexCoord2f(1.0f, 0.0f);  glVertex3f(  0.5, -0.5,  0.5 );
	  glTexCoord2f(1.0f, 1.0f);  glVertex3f( -0.5, -0.5,  0.5 );
	  glTexCoord2f(0.0f, 1.0f);  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();
     }

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.5, 0.5, -5.0, 0.0 + lax, 0.0 + lay, 0.0 +laz, 0.0, 1.0, 0.0);

	glPushMatrix();
	if(bx==true){
         rotate_x += vel;
     }
    if(by==true){
                 rotate_y += vel;
                 }
    if(bz==true){
                 rotate_z += vel;
                 }
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 1.0 );
    glTranslatef(X, Y, Z); 	
    glScalef(scale, scale, scale);
	dibujaCubo();
    //********************funcion cubo;	
	glPopMatrix(); 
	glFlush();
	glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();//Inicializa la matriz de proyeccion
	gluPerspective(45.0f,(GLfloat)w/(GLfloat)h,0.1f,100.0f);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	case 97://a
		lax--;
		break;
	case 115://s
		laz--;
		break;
	case 100://d
		lax++;
		break;
	case 119://w
		laz++;
		break;
    case 43:
         Z+=1.0;
         break;
    case 45:
         Z-=1.0;
         break;
    case 120:
         if(by==false){
            by=true;
         }
         else{
            by=false;
         }
         break;
    case 121:
         if(bx==false){
            bx=true;
         }
         else{
            bx=false;
         }
         break;
    case 122:
         if(bz==false){
            bz=true;
         }
         else{
            bz=false;
         }
         break;       
	case 27:
		exit(0);
		break;
	}
}


int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutCreateWindow("Texturas En 3D");
	glutSetCursor(GLUT_CURSOR_NONE);
	glutFullScreen();
	initRendering();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape); 
	glutIdleFunc(display);
	glutSpecialFunc(ArrowKey);
	glEnable(GL_DEPTH_TEST);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
