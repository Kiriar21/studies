#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

static int slices = 16;
static int stacks = 16;

/* GLUT callback Handlers */

static void resize(int width, int height)  	// kod odpowiedzialny za skalowanie zawartości
{                                            // okna w przypadku zmiany jego rozmiaru
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION); //Pozwala określić, który stos macierzy będzie stosowany w czasie manipulacji na macierzach, GL_PROJECTION – stos macierzy rzutowania (do definiowania przestrzeni ograniczającej)
    glLoadIdentity();   //Nadaje aktualnej macierzy wartości macierzy jednostkowej. W ten sposób aktualny układ współrzędnych staje się zgodny z układem współrzędnych okna.
//    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);  //Tworzy macierz perspektywy, dzięki której mo¿na uzyskaæ rzutowanie perspektywiczne
    glOrtho(-7 * ar , 7 * ar , -7 , 7 , -10 , 10 );
    glMatrixMode(GL_MODELVIEW);  // GL_MODELVIEW – stos macierzy model-widok (do przemieszczania obiektów na scenie)
    glLoadIdentity() ;
}

static void display(void)   // funkcja generująca scenę 3D, tworzenie zawartoœci okna
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // czyszczenie bufora dotyczącego koloru
    glColor3d(1,0,0); // ustalenie koloru rysowania obiektu (czerwony, zielony, niebieski)

    glPointSize(10);
    glLineWidth(5);
    glShadeModel(GL_FLAT);

    glBegin(GL_POINTS);
    glColor3d(1,1,0);
    glVertex2d(-4,4);
    glColor3d(1,1,1);
    glVertex2d(-5,3);
    glColor3d(0,1,1);
    glVertex2d(-3,3);
    glEnd();


    glBegin(GL_LINES);
    glColor3d(0.6,0,0.5);
    glVertex2d(-2,4);
    glColor3d(0.6,0,0.5);
    glVertex2d(-2,3);
    glColor3d(0.6,0.1,0.8);
    glVertex2d(-1,4);
    glColor3d(0.6,0.1,0.8);
    glVertex2d(-1,3);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3d(0.6,0,0.5);
    glVertex2d(1,4);
    glColor3d(0.6,0,0.5);
    glVertex2d(1,3);
    glColor3d(0.6,0.1,0.8);
    glVertex2d(2,3);
    glColor3d(0.6,0.1,0.8);
    glVertex2d(2,4);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3d(0.6,0,0.5);
    glVertex2d(3,4);
    glColor3d(0.6,0,0.5);
    glVertex2d(3,2);
    glColor3d(0.6,0.1,0.8);
    glVertex2d(4,2);
    glColor3d(0.6,0.1,0.8);
    glVertex2d(4,4);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3d(1,0.5,1);
    glVertex2d(-4,1);
    glColor3d(1,0.5,1);
    glVertex2d(-5,0);
    glColor3d(1,0.5,1);
    glVertex2d(-3,0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);

    glColor3d(1,0.6,0);
    glVertex2d(0,0);
    glColor3d(1,0.6,0);
    glVertex2d(2,0);
    glColor3d(1,0.6,0);
    glVertex2d(1,1);

    glColor3d(1,1,0.7);
    glVertex2d(0,0);
    glColor3d(1,1,0.7);
    glVertex2d(1,1);
    glColor3d(1,1,0.7);
    glVertex2d(-1,1);

    glColor3d(1,0.8,1);
    glVertex2d(0,0);
    glColor3d(1,0.8,1);
    glVertex2d(-1,1);
    glColor3d(1,0.8,1);
    glVertex2d(-2,0);

    glColor3d(0.8,0.9,1);
    glVertex2d(0,0);
    glColor3d(0.8,0.9,1);
    glVertex2d(-2,0);
    glColor3d(0.8,0.9,1);
    glVertex2d(-1,-1);

    glColor3d(0.8,0.9,0.1);
    glVertex2d(0,0);
    glColor3d(0.8,0.9,0.1);
    glVertex2d(-1,-1);
    glColor3d(0.8,0.9,0.1);
    glVertex2d(1,-1);

    glColor3d(1,0.3,0.1);
    glVertex2d(0,0);
    glColor3d(1,0.3,0.1);
    glVertex2d(1,-1);
    glColor3d(1,0.3,0.1);
    glVertex2d(2,0);

    glEnd();


    glBegin(GL_TRIANGLE_STRIP);

    glColor3d(1,0.3,0.1);
    glVertex2d(2,1);
    glColor3d(1,0.3,0.1);
    glVertex2d(3,0);
    glColor3d(1,0.3,0.1);
    glVertex2d(4,1);

    glColor3d(0.1,0.5,0.9);
    glVertex2d(3,0);
    glColor3d(0.1,0.5,0.9);
    glVertex2d(4,1);
    glColor3d(0.1,0.5,0.9);
    glVertex2d(5,0);

    glColor3d(0.5,0.5,0.5);
    glVertex2d(4,1);
    glColor3d(0.5,0.5,0.5);
    glVertex2d(5,0);
    glColor3d(0.5,0.5,0.5);
    glVertex2d(6,1);

    glColor3d(0.9,0.9,0.2);
    glVertex2d(5,0);
    glColor3d(0.9,0.9,0.2);
    glVertex2d(6,1);
    glColor3d(0.9,0.9,0.2);
    glVertex2d(7,0);

    glEnd();


    glBegin(GL_QUADS);
    glColor3d(0.9,0.3,0.9);
    glVertex2d(-5,-1);
    glColor3d(0.9,0.3,0.9);
    glVertex2d(-5,-2);
    glColor3d(0.9,0.3,0.9);
    glVertex2d(-4,-2);
    glColor3d(0.9,0.3,0.9);
    glVertex2d(-4,-1);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3d(0.8,0.7,1);
    glVertex2d(-3,-4);
    glColor3d(0.8,0.7,1);
    glVertex2d(-3,-5);
    glColor3d(0.8,0.7,1);
    glVertex2d(-2,-4);
    glColor3d(0.8,0.7,1);
    glVertex2d(-2,-5);

    glColor3d(0.8,0.6,0);
    glVertex2d(-2,-4);
    glColor3d(0.8,0.6,0);
    glVertex2d(-2,-5);
    glColor3d(0.8,0.6,0);
    glVertex2d(-1,-4);
    glColor3d(0.8,0.6,0);
    glVertex2d(-1,-5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(0.7,1,0);
    glVertex2d(3,-4);
    glColor3d(0.7,1,0);
    glVertex2d(4,-5);
    glColor3d(0.7,1,0);
    glVertex2d(6,-5);
    glColor3d(0.7,1,0);
    glVertex2d(7,-4);
    glColor3d(0.7,1,0);
    glVertex2d(6,-3);
    glColor3d(0.7,1,0);
    glVertex2d(4,-3);
    glEnd();

    glutSwapBuffers();  // podmiana buforów
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
    glutInit(&argc, argv);  // inicjacja biblioteki GLUT
    glutInitWindowSize(640,480);    // ustalenie rozmiaru okna programu

    glutInitWindowPosition(10,10);  // początkowe położenie okna
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);   // inicjalizacja bufora ramki z podwójnym buforowaniem

    glutCreateWindow("Matuszczyk");    // utworzenie głównego okna programu o podanej nazwie

    //rejestracja obsługi zdarzeń
    glutReshapeFunc(resize);    // przyłączenie funkcji wywoływanej przy zmianie rozmiaru okna
    glutDisplayFunc(display);   // przyłączenie funkcji opisującej scenę 3D
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);  // ustalenie koloru tła
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

    glutMainLoop(); // wprowadzenie programu do obsługi pętli komunikatów

    return EXIT_SUCCESS;
}
