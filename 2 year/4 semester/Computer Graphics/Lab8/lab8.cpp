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
#include <cmath>
#define GL_PI 3.1415f









static int slices = 16;
static int stacks = 16;

/* GLUT callback Handlers */
static void display(void);

int rzut, skala;
int kat=90;
GLdouble ColorR=0, ColorG=0, ColorB=0;
int xx,yy,xz,yz,zx,obrot_x,obrot_y,yx,xy,zy;
GLfloat x,y,angle,x1,z1; // Przechowują wartości współrzędnych i kąta
int iPivot = 1; // Do oznaczania zamiennych kolorów

// sta³e do obs³ugi menu podrêcznego
enum { ORTO, // rzutowanie ortogonalne
 SKALA_1_1, // gdy zachowujemy proporcje przy skalowaniu
 PERSP, // rzutowanie perspektywiczne
 FRUST, // rzutowanie perspektywiczne
 FULL_WINDOW, // gdy nie zachowujemy proporcji przy skalowaniu
 EXIT, // wyjœcie
 Color_R, // zmiana koloru obiektów na czerwony
 Color_G, // zmiana koloru obiektów na zielony
 Color_B, // zmiana koloru obiektów na niebieski
 };

GLint iCull=0;
GLint iDepth=0;
GLint iOutline=0;
GLint iFill=0;
GLint iClock=0;




static void resize(int width, int height)
{
 glViewport (0,0,width,height); // obszar renderingu - cale okno
 glMatrixMode (GL_PROJECTION); // wybór macierzy rzutowania
 glLoadIdentity (); // macierz rzutowania = macierz jednostkowa

 // ustawienie parametrów zakresu rzutni
 GLdouble aspect = 1;
 GLfloat zakres = 150.0f;
 GLfloat blisko = 1.0f;
 GLfloat daleko = 150.0f;
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
    // Włączenie lub wyłączenie mechanizmu eliminowania ukrytych powierzchni
if(iCull)
glEnable(GL_CULL_FACE);
else
glDisable(GL_CULL_FACE);

// Włączenie lub wyłączenie mechanizmu sprawdzania głębi
if(iDepth)
glEnable(GL_DEPTH_TEST);
else
glDisable(GL_DEPTH_TEST);



// Jeżeli ten znacznik będzie ustawiony, to wielokąty zwrócone tyłem do widza
//będą rysowane tylko w postaci szkieletu
if(iOutline)
glPolygonMode(GL_BACK,GL_LINE);
else
glPolygonMode(GL_BACK,GL_FILL);

// Jeżeli ten znacznik będzie ustawiony, to wielokąty będą wypełniane jednolitym
// kolorem w przeciwnym razie nastąpi płynne przejście kolorów pomiędzy
// wierzchołkami
if(iFill)
glShadeModel(GL_FLAT);
else
glShadeModel(GL_SMOOTH);




    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(ColorR,ColorG,ColorB);

    glPushMatrix();
        glTranslatef(0.0f,0.0f,-100.0f);
        glRotatef(obrot_x,xx,yx,zx);
        glRotatef(obrot_y,xy,yy,zy);

glBegin(GL_TRIANGLE_STRIP); // Rysowanie ściany bocznej stożka
glVertex3f(0.0f, 0.0f, 75.0f); // Czubek stożka jest wspólnym
//wierzchołkiem wszystkich trójkątów z wachlarza.
for(angle = 0.0f; angle < (2.0f*GL_PI); angle += (GL_PI/8.0f))
{
x = 30.0f*sin(angle); // Wyliczenie współrzędnych x i y kolejnego
//wierzchołka
y = 30.0f*cos(angle);
x1=50.0f*sin(angle);
z1 = 50.0f*cos(angle);
if((iPivot %2) == 0) // Wybieranie koloru - zielony lub czerwony
glColor3f(0.0f, 1.0f, 0.0f);
else
glColor3f(1.0f, 0.0f, 0.0f);
iPivot++; // Inkrementacja zmiennej określającej rodzaj koloru
// Definiowanie kolejnego wierzchołka w wachlarzu trójkątów
glVertex3f(x, y,0);
glVertex3f(x1,z1,75);
}
glEnd(); // Zakończenie rysowania trójkątów stożka

glBegin(GL_TRIANGLE_FAN); // Rozpoczęcie rysowania kolejnego wachlarza trójkątów
 //zakrywającego podstawę stożka
glVertex2f(0.0f, 0.0f); // Środek wachlarza znajduje się na początku
//układu współrzędnych
for(angle = 0.0f; angle < (2.0f*GL_PI); angle += (GL_PI/8.0f))
{
x = 30.0f*sin(angle); // Wyliczenie współrzędnych x i y kolejnego
 //wierzchołka
y = 30.0f*cos(angle);
if((iPivot %2) == 0) // Wybieranie koloru - zielony lub czerwony
glColor3f(0.0f, 1.0f, 0.0f);
else
glColor3f(1.0f, 0.0f, 0.0f);
iPivot++; // Inkrementacja zmiennej określającej rodzaj koloru
glVertex2f(x, y); // Definiowanie kolejnego wierzchołka w wachlarzu
//trójkątów
}
glEnd(); // Zakończenie rysowania trójkątów podstawy stożka
glPopMatrix();

    glutSwapBuffers();
}
void MainMenu(int value)
{
 switch (value)
 {
 case EXIT:
 exit (0);

 case 10:
    iDepth=!iDepth;
    break;
 case 20:
    iCull=!iCull;
    break;
 case 30:
    iOutline=!iOutline;
//    default;
    break;
 case 40:
    iFill=!iFill;
    break;

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
        case 27 :
        case 'e':
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

        case'a':
            xx=0;
            yx=1;
            zx=0;
            obrot_x=obrot_x+5;
            break;

        case'd':
            xx=0;
            yx=1;
            zx=0;
            obrot_x=obrot_x-5;
            break;

        case'w':
            xy=1;
            yy=0;
            zy=0;
            obrot_y=obrot_y+5;
            break;
        case's':
            xy=1;
            yy=0;
            zy=0;
            obrot_y=obrot_y-5;
            break;

            case'A':
            xx=0;
            yx=1;
            zx=0;
            obrot_x=obrot_x+5;
            break;

        case'D':
            xx=0;
            yx=1;
            zx=0;
            obrot_x=obrot_x-5;
            break;

        case'W':
            xy=1;
            yy=0;
            zy=0;
            obrot_y=obrot_y+5;
            break;
        case'S':
            xy=1;
            yy=0;
            zy=0;
            obrot_y=obrot_y-5;
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
int rzutowanie = glutCreateMenu (MenuR);
glutAddMenuEntry ("Rzutowanie - Ortogonalne",ORTO);
glutAddMenuEntry ("Rzutowanie - Frustum",FRUST);
glutAddMenuEntry ("Rzutowanie - Perspective",PERSP);
int kolor = glutCreateMenu (MenuC);
glutAddMenuEntry ("Kolor - Czerwony",Color_R);
glutAddMenuEntry ("Kolor - Zielony",Color_G);
glutAddMenuEntry ("Kolor - Niebieski",Color_B);
// . . . oznaczaj¹ brakuj¹ce fragmenty kodu, nale¿y dodaæ do menu
// obs³uge rzutowania i zmiany koloru.
int mainMenu = glutCreateMenu(MainMenu);// utworzenie menu podrecznego
glutAddSubMenu("Skalowanie", skalowanie);
glutAddSubMenu("Rzutowanie", rzutowanie);
glutAddSubMenu("Kolor", kolor);
glutAddMenuEntry ("Testowanie glebi",10);
glutAddMenuEntry ("Ukrywanie powierzchni niewidocznych",20);
glutAddMenuEntry ("Rysowanie szkieletu",30);
glutAddMenuEntry ("Wypelnianie powierzchni",40);
glutAddMenuEntry ("Wyjscie",EXIT);
glutAttachMenu (GLUT_RIGHT_BUTTON); // okreœlenie przycisku myszki obs³uguj¹cej menu podrêczne
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

    glFrontFace(GL_CW);

    glutMainLoop();

    return EXIT_SUCCESS;
}
