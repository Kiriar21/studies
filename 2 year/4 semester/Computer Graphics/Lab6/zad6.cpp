
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <fstream>
using namespace std;

static int slices = 16;
static int stacks = 16;

const int lw = 200;
const int lk = 200;
int R[lw][lk];
int G[lw][lk];
int B[lw][lk];

int Rn[lw][lk];
int Gn[lw][lk];
int Bn[lw][lk];

int Rg[lw][lk];
int Gg[lw][lk];
int Bg[lw][lk];

static void resize(int width, int height)
{
    const float ar = (float)width / (float)height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, lk, 0, lw, -10, 10);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t * 90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1, 0, 0);
    glPointSize(10);

    glBegin(GL_POINTS);
    for (int i = 0; i < lw; ++i)
        for (int j = 0; j < lk; ++j)
        {
            glColor3f(Rn[i][j] / 255.0, Gn[i][j] / 255.0, Bn[i][j] / 255.0);
            glVertex3f(j, i, 0);
        }
    glEnd();

    glutSwapBuffers();
}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {

    case '+':
        for (int i = 0; i < lw; ++i)
            for (int j = 0; j < lk; ++j)
            {
                Rn[i][j] += 10;
                Gn[i][j] += 10;
                Bn[i][j] += 10;
            }
        for (int i = 0; i < lw; ++i)
            for (int j = 0; j < lk; ++j)
            {
                R[i][j] = Rn[i][j];
                G[i][j] = Gn[i][j];
                B[i][j] = Bn[i][j];
            }
        break;
    case '-':
        for (int i = 0; i < lw; ++i)
            for (int j = 0; j < lk; ++j)
            {
                Rn[i][j] -= 10;
                Gn[i][j] -= 10;
                Bn[i][j] -= 10;
            }
        for (int i = 0; i < lw; ++i)
            for (int j = 0; j < lk; ++j)
            {
                R[i][j] = Rn[i][j];
                G[i][j] = Gn[i][j];
                B[i][j] = Bn[i][j];
            }
        break;

    case 'z':
        for (int i = 0; i < lw; ++i)
            for (int j = 0; j < lk; ++j)
            {
                Rn[i][j] = R[i][j];
                Gn[i][j] = G[i][j];
                Bn[i][j] = B[i][j];
            }
        break;

    case 'x':
        for (int i = 0; i < lw; ++i)
            for (int j = 0; j < lk; ++j)
            {
                Rn[i][j] = Rg[i][j];
                Gn[i][j] = Gg[i][j];
                Bn[i][j] = Bg[i][j];
            }
        break;

    case 'b':
        for (int i = 0; i < lw; ++i)
            for (int j = 0; j < lk; ++j)
            {
                Rn[i][j] = 0;
                Gn[i][j] = 0;
                Bn[i][j] = B[i][j];
            }
        break;

    case 'r':
        for (int i = 0; i < lw; ++i)
            for (int j = 0; j < lk; ++j)
            {
                Rn[i][j] = R[i][j];
                Gn[i][j] = 0;
                Bn[i][j] = 0;
            }
        break;

    case 'g':
        for (int i = 0; i < lw; ++i)
            for (int j = 0; j < lk; ++j)
            {
                Rn[i][j] = 0;
                Gn[i][j] = G[i][j];
                Bn[i][j] = 0;
            }
        break;

    case 'd':
    {
        int M[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
        for (int i = 1; i < lw - 1; ++i)
            for (int j = 1; j < lk - 1; ++j)
            {
                Rn[i][j] = (R[i - 1][j - 1] * M[0][0] + R[i - 1][j] * M[0][1] + R[i - 1][j + 1] * M[0][2] +
                            R[i][j - 1] * M[1][0] + R[i][j] * M[1][1] + R[i][j + 1] * M[1][2] +
                            R[i + 1][j - 1] * M[2][0] + R[i + 1][j] * M[2][1] + R[i + 1][j + 1] * M[2][2]) /
                           (M[0][0] + M[0][1] + M[0][2] + M[1][0] + M[1][1] + M[1][2] + M[2][0] + M[2][1] + M[2][2]);

                Gn[i][j] = (G[i - 1][j - 1] * M[0][0] + G[i - 1][j] * M[0][1] + G[i - 1][j + 1] * M[0][2] +
                            G[i][j - 1] * M[1][0] + G[i][j] * M[1][1] + G[i][j + 1] * M[1][2] +
                            G[i + 1][j - 1] * M[2][0] + G[i + 1][j] * M[2][1] + G[i + 1][j + 1] * M[2][2]) /
                           (M[0][0] + M[0][1] + M[0][2] + M[1][0] + M[1][1] + M[1][2] + M[2][0] + M[2][1] + M[2][2]);

                Bn[i][j] = (B[i - 1][j - 1] * M[0][0] + B[i - 1][j] * M[0][1] + B[i - 1][j + 1] * M[0][2] +
                            B[i][j - 1] * M[1][0] + B[i][j] * M[1][1] + B[i][j + 1] * M[1][2] +
                            B[i + 1][j - 1] * M[2][0] + B[i + 1][j] * M[2][1] + B[i + 1][j + 1] * M[2][2]) /
                           (M[0][0] + M[0][1] + M[0][2] + M[1][0] + M[1][1] + M[1][2] + M[2][0] + M[2][1] + M[2][2]);
            }
    }
        for (int i = 0; i < lw; ++i)
            for (int j = 0; j < lk; ++j)
            {
                R[i][j] = Rn[i][j];
                G[i][j] = Gn[i][j];
                B[i][j] = Bn[i][j];
            }
        break;

    case 'f':
    {
        int M[3][3] = {{-1, -1, -1}, {-1, 9, -1}, {-1, -1, -1}};
        for (int i = 1; i < lw - 1; ++i)
            for (int j = 1; j < lk - 1; ++j)
            {
                Rn[i][j] = (R[i - 1][j - 1] * M[0][0] + R[i - 1][j] * M[0][1] + R[i - 1][j + 1] * M[0][2] +
                            R[i][j - 1] * M[1][0] + R[i][j] * M[1][1] + R[i][j + 1] * M[1][2] +
                            R[i + 1][j - 1] * M[2][0] + R[i + 1][j] * M[2][1] + R[i + 1][j + 1] * M[2][2]) /
                           (M[0][0] + M[0][1] + M[0][2] + M[1][0] + M[1][1] + M[1][2] + M[2][0] + M[2][1] + M[2][2]);

                Gn[i][j] = (G[i - 1][j - 1] * M[0][0] + G[i - 1][j] * M[0][1] + G[i - 1][j + 1] * M[0][2] +
                            G[i][j - 1] * M[1][0] + G[i][j] * M[1][1] + G[i][j + 1] * M[1][2] +
                            G[i + 1][j - 1] * M[2][0] + G[i + 1][j] * M[2][1] + G[i + 1][j + 1] * M[2][2]) /
                           (M[0][0] + M[0][1] + M[0][2] + M[1][0] + M[1][1] + M[1][2] + M[2][0] + M[2][1] + M[2][2]);

                Bn[i][j] = (B[i - 1][j - 1] * M[0][0] + B[i - 1][j] * M[0][1] + B[i - 1][j + 1] * M[0][2] +
                            B[i][j - 1] * M[1][0] + B[i][j] * M[1][1] + B[i][j + 1] * M[1][2] +
                            B[i + 1][j - 1] * M[2][0] + B[i + 1][j] * M[2][1] + B[i + 1][j + 1] * M[2][2]) /
                           (M[0][0] + M[0][1] + M[0][2] + M[1][0] + M[1][1] + M[1][2] + M[2][0] + M[2][1] + M[2][2]);
            }
    }
        for (int i = 0; i < lw; ++i)
            for (int j = 0; j < lk; ++j)
            {
                R[i][j] = Rn[i][j];
                G[i][j] = Gn[i][j];
                B[i][j] = Bn[i][j];
            }
        break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[] = {0.0f, 0.0f, 0.0f, 1.0f};
const GLfloat light_diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat light_position[] = {2.0f, 5.0f, 5.0f, 0.0f};

const GLfloat mat_ambient[] = {0.7f, 0.7f, 0.7f, 1.0f};
const GLfloat mat_diffuse[] = {0.8f, 0.8f, 0.8f, 1.0f};
const GLfloat mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat high_shininess[] = {100.0f};

/* Program entry point */

int main(int argc, char *argv[])
{

    ifstream plik;
    plik.open("zd3.txt");
    int pom;
    plik >> pom >> pom;
    for (int i = 0; i < lw; i++)
    {
        for (int j = 0; j < lk; j++)
        {
            plik >> R[i][j] >> G[i][j] >> B[i][j];
            Rg[i][j] = Rn[i][j] = R[i][j];
            Gg[i][j] = Gn[i][j] = G[i][j];
            Bg[i][j] = Bn[i][j] = B[i][j];
        }
    }

    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(1, 1, 1, 1);
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
