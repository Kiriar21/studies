/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

static int slices = 16;
static int stacks = 16;

/* GLUT callback Handlers */

static void display(void);
int rzut,skala;
int kat=90;
GLdouble ColorR=0, ColorG=0, ColorB=0;
int xx,yy,xz,yz,zx,obrot_x,obrot_y,yx,xy,zy;



// sta�e do obs�ugi menu podr�cznego
enum { ORTO, // rzutowanie ortogonalne
 SKALA_1_1, // gdy zachowujemy proporcje przy skalowaniu
 PERSP, // rzutowanie perspektywiczne
 FRUST, // rzutowanie perspektywiczne
 FULL_WINDOW, // gdy nie zachowujemy proporcji przy skalowaniu
 EXIT, // wyj�cie
 Color_R, // zmiana koloru obiekt�w na czerwony
 Color_G, // zmiana koloru obiekt�w na zielony
 Color_B, // zmiana koloru obiekt�w na niebieski
 };


static void resize(int width, int height)
{
 glViewport (0,0,width,height); // obszar renderingu - cale okno
 glMatrixMode (GL_PROJECTION); // wyb�r macierzy rzutowania
 glLoadIdentity (); // macierz rzutowania = macierz jednostkowa

 // ustawienie parametr�w zakresu rzutni
 GLdouble aspect = 1;
 GLfloat zakres = 4.0f;
 GLfloat blisko = 1.0f;
 GLfloat daleko = 25.0f;
 if (rzut==ORTO) // rzutowanie ortogonalne
 {
 if (skala==SKALA_1_1)
 {
 if (width < height && width > 0)
 glOrtho (-zakres,zakres,-zakres*height/width,
 zakres*height/width,-4*zakres,4*zakres);
 else if (width >= height && height > 0)
 glOrtho (-zakres*width/height,zakres*width/height,
-zakres,zakres,-4*zakres,4*zakres);
 }
 else
 glOrtho (-zakres,zakres,-zakres,zakres,-4*zakres,4*zakres);
 }
 if (rzut==FRUST) // rzutowanie perspektywiczne glFrustrum
 {
 if (skala==SKALA_1_1)
 {
 if (width < height && width > 0)
 glFrustum (-zakres,zakres,zakres*height/width,
 zakres*height/width,blisko,daleko);
 else if (width >= height && height > 0)
 glFrustum (-zakres*width/height,zakres*width/height,
 -zakres,zakres,blisko,daleko);
 }
 else
 glFrustum (-zakres,zakres,-zakres,zakres,blisko,daleko);
 }
 if (rzut==PERSP) //rzutowanie perspektywiczne gluPerspective
 {
 if (height > 0)
 aspect = width/(GLdouble)height;
 gluPerspective (kat,aspect,blisko,daleko);
 }
 display ();
}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(ColorR,ColorG,ColorB);


    glPushMatrix();
    glTranslatef(-2.0f,2.0f,-3.0f);
    glRotated(-150,0,1,0);
    glutSolidTeapot(1);
    glPopMatrix();


    glPushMatrix();
    glTranslated(0,0,-6);
    glRotatef(obrot_x,0.0f,yx,0.0f);
    glRotatef(obrot_y,xy,yy,zy);
    glScaled(1.5,1.5,1.5);



     glBegin(GL_LINES);
    glVertex3d(-1,-1,-1);
    glVertex3d(1,-1,-1);

    glVertex3d(1,-1,-1);
    glVertex3d(1,1,-1);

    glVertex3d(1,1,-1);
    glVertex3d(-1,1,-1);

    glVertex3d(-1,1,-1);
    glVertex3d(-1,-1,-1);

    glVertex3d(-1,-1,-1);
    glVertex3d(-1,-1,1);

    glVertex3d(1,-1,-1);
    glVertex3d(1,-1,1);

    glVertex3d(1,1,-1);
    glVertex3d(1,1,1);

    glVertex3d(-1,1,-1);
    glVertex3d(-1,1,1);

    glVertex3d(-1,-1,1);
    glVertex3d(1,-1,1);

    glVertex3d(1,-1,1);
    glVertex3d(1,1,1);

    glVertex3d(1,1,1);
    glVertex3d(-1,1,1);

    glVertex3d(-1,1,1);
    glVertex3d(-1,-1,1);


glEnd();

    glPopMatrix();
    glutSwapBuffers();
}


void MainMenu(int value)
{
 switch (value)
 {
 case EXIT:
 exit (0);
 }
}
void MenuS (int value)
{
 switch (value)
 {
 case FULL_WINDOW:
 skala=FULL_WINDOW;
 resize(glutGet(GLUT_WINDOW_WIDTH),glutGet(GLUT_WINDOW_HEIGHT));
 break;
 case SKALA_1_1:
 skala=SKALA_1_1;
 resize(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
 break;
 }
}
void MenuR(int value)
{
 switch (value)
 {
 case ORTO:
 rzut=ORTO;
 resize(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
 break;
 case FRUST:
 rzut=FRUST;
 resize(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
 break;
 case PERSP:
 rzut=PERSP;
 resize(glutGet (GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
 break;
 }
}
void MenuC(int value)
{
 switch (value)
 {
 case Color_R:
 ColorR=1.0, ColorG=0.0, ColorB=0.0; display(); break;
 case Color_G:
 ColorR=0.0, ColorG=1.0, ColorB=0.0; display(); break;
 case Color_B:
 ColorR=0.0, ColorG=0.0, ColorB=1.0; display(); break;
 }
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {


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
        case 'u':
            obrot_y-=5;
            xy=1;
            yy=0;
            zy=0;
            break;
        case 'd':
            xy=1;
            yy=0;
            zy=0;
            obrot_y+=5;
            break;
        case 'r':
            obrot_x+=5;
            yx=1;
            break;
        case 'l':
            obrot_x -=5;
            yx=1;
            break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    int skalowanie = glutCreateMenu (MenuS);
    glutAddMenuEntry ("Skalowanie - cale okno",FULL_WINDOW);
 glutAddMenuEntry ("Skalowanie - skala 1:1",SKALA_1_1);
    int rzutowanie = glutCreateMenu(MenuR);
    glutAddMenuEntry ("Rzutowanie - Ortogonalne",ORTO);
    glutAddMenuEntry ("Rzutowanie - Frustum",FRUST);
    glutAddMenuEntry ("Rzutowanie - Perspective",PERSP);
    int kolor = glutCreateMenu(MenuC);
    glutAddMenuEntry ("Kolor - Czerwony",Color_R);
    glutAddMenuEntry ("Kolor - Zielony",Color_G);
    glutAddMenuEntry ("Kolor - Niebieski",Color_B);







 int mainMenu = glutCreateMenu(MainMenu);
 glutAddSubMenu("Skalowanie", skalowanie);
 glutAddSubMenu("Rzutowanie", rzutowanie);
 glutAddSubMenu("Kolor", kolor);
 glutAddMenuEntry ("Wyjscie",EXIT);
 glutAttachMenu (GLUT_RIGHT_BUTTON);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return EXIT_SUCCESS;
}
