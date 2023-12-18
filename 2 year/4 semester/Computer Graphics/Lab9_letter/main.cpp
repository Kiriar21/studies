/*
* GLUT Shapes Demo
*
* Written by Nigel Stewart November 2003
*
* This program is test harness for the sphere, cone
* and torus shapes in GLUT.
*
* Spinning wireframe and smooth shaded shapes are
* displayed until the ESC or q key is pressed. The
* number of geometry stacks and slices can be adjusted
* using the + and - keys.
*/
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
#include<fstream>
#include <stdlib.h>

using namespace std;

static int slices = 16;
static int stacks = 16;

int lWez, lEle, **Ele;
double **Wez, **kolor,gx=0,gy=0;


void wczytajPlik(char *nazwaPliku)
{
ifstream plik(nazwaPliku);
int pom1, pom2;
plik>>lWez;
Wez = new double* [lWez];
for(int i=0; i<lWez; i++)
Wez[i]=new double[3];
for(int i=0;i<lWez;i++)
plik>>pom1>>Wez[i][0]>>Wez[i][1]>>Wez[i][2];
plik>>lEle;
Ele = new int* [lEle];
for(int i=0; i<lEle; i++)
Ele[i]=new int[3];
for(int i=0; i<lEle;i++)
{
plik>>pom1>>pom1>>pom1>>pom1>>pom1>>Ele[i][0]>>Ele[i][1]>>Ele[i][2];
Ele[i][0]--;
Ele[i][1]--;
Ele[i][2]--;
}
kolor = new double* [lEle]; // pozwoli nam na wy wietlenie ka dego tr jk tnego
//element w innym kolorze
for(int i=0; i<lEle; i++)
{
kolor[i]=new double[3];
kolor[i][0]=rand()%255/255.;
kolor[i][1]=rand()%255/255.;
kolor[i][2]=rand()%255/255.;
}
cout<<"Liczba wezlow: "<<lWez<<"\t"<<"Liczba elementow: "<<lEle<<endl;
plik.close();
}

/* GLUT callback Handlers */

static void resize(int width, int height)
{
const float ar = (float) width / (float) height;

glViewport(0, 0, width, height);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

glMatrixMode(GL_MODELVIEW);
glLoadIdentity() ;
}

static void display(void)
{
const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
const double a = t*90.0;

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glColor3d(1,0,0);


glPushMatrix();

glTranslated(gx,gy,-20);
//glRotated(60,1,0,0);
//glRotated(a,0.4,0.4,1);
glScaled(0.5,0.5,0.5);

glBegin(GL_TRIANGLES);
for(int nrEl=0;nrEl<lEle;nrEl++)
{
//ka dy tr jk t w innym kolorze
glColor3f(kolor[nrEl][0],kolor[nrEl][1],kolor[nrEl][2]);
// definiowanie 1 wierzcho ka
glVertex3f(Wez[Ele[nrEl][0]][0],Wez[Ele[nrEl][0]][1], Wez[Ele[nrEl][0]][2]);
// nale y zdefiniowa  wsp rz dne dla pozosta ych 2 wierzcho k w
glVertex3f(Wez[Ele[nrEl][1]][0],Wez[Ele[nrEl][1]][1], Wez[Ele[nrEl][1]][2]);
glVertex3f(Wez[Ele[nrEl][2]][0],Wez[Ele[nrEl][2]][1], Wez[Ele[nrEl][2]][2]);
}
glEnd();

glPopMatrix();



glutSwapBuffers();
}

static void mouseMove(int x, int y)
{

gx=x/640.0;//*22-11.;
gy=-y/480.0;//*14-7.;
display();
}


static void key(unsigned char key, int x, int y)
{
switch (key)
{
case 27 :
case 'q':
exit(0);
break;

case '+':
slices++;
stacks++;
break;

case '-':
if (slices>3 && stacks>3)
{
slices--;
stacks--;
}
break;
}

glutPostRedisplay();
}

static void idle(void)
{
glutPostRedisplay();
}

const GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

int main(int argc, char *argv[])
{
wczytajPlik("D:\\Studia\\Semestr 4\\Grafika Komputerowa\\Laboratoria\\lab9dzialajacy\\lab9\\a.msh");

glutInit(&argc, argv);
glutInitWindowSize(640,480);
glutInitWindowPosition(10,10);
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

glutCreateWindow("GLUT Shapes");

glutReshapeFunc(resize);
glutDisplayFunc(display);
glutKeyboardFunc(key);
glutIdleFunc(idle);
glutMotionFunc(mouseMove);

glClearColor(1,1,1,1);
glEnable(GL_CULL_FACE);
glCullFace(GL_BACK);

glEnable(GL_DEPTH_TEST);
glDepthFunc(GL_LESS);

glEnable(GL_LIGHT0);
glEnable(GL_NORMALIZE);
glEnable(GL_COLOR_MATERIAL);
glEnable(GL_LIGHTING);

glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
glLightfv(GL_LIGHT0, GL_POSITION, light_position);

glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

glutMainLoop();

return EXIT_SUCCESS;
}
