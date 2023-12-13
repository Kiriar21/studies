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
#include <stdlib.h>
#include <glpomoc.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <cmath>



static int slices = 16;
static int stacks = 16;

/* GLUT callback Handlers */
GLfloat PI = 3.14;
GLfloat alfa = -PI / 2;
GLfloat skok_point = 300.0f; ///odleglosc punktu obserwowania
GLfloat skok_eye = 10.0f; ///do pozycji oka
GLfloat eyex = 0; ///wspolrzedne pozycji oka
GLfloat eyey = 0;
GLfloat eyez = -1;
GLfloat pointx = skok_point * cos (alfa); ///wspolrzedne punktu, w ktorysie patrzymy
GLfloat pointy = 0.0;
GLfloat pointz = skok_point * sin (alfa);
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
    glLoadIdentity();
    gluLookAt (eyex, eyey, eyez, pointx, pointy, pointz, 0.0, 1.0, 0.0);
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);

    glPushMatrix();
        glColor3d(1,1,0.5);
        glTranslatef(0.0f, 0.0f, -13.0f);
        glRotatef(a/1.5, 1.0f, 1.0f, 1.0f);
        glutSolidSphere(0.9f,17,9);

        glPushMatrix();
            glColor3d(0.5,0.8,0.3);
            glTranslatef(0.0f, 0.0f, -3.0f);
            glRotatef(a/1.5, 0.0f, 1.0f, 0.0f);
            glutSolidSphere(0.5f,17,9);

                glPushMatrix();
                    glColor3d(0.8,0.8,0.8);
                    glTranslatef(0.0f, 0.0f, -2.0f);
                    glRotatef(a*1.5, 0.0f, 1.0f, 0.0f);
                    glutSolidSphere(0.5f,17,9);

                    glPushMatrix();
                        glColor3d(0,0,0);
                        glTranslated(0.0f,0.0f, -7.0f);
                        glRotatef(a/(2), 1.0f, 1.0f, 0.0f);
                        glutSolidSphere(0.9f,17,9);

                            glPushMatrix();
                                glColor3d(1, 0.2, 0.3);
                                glScaled(1.0f, 1.0f, 0.1f);
                                glRotatef(30.0f, 0.0f, 1.0f, 0.0f);
                                glutSolidTorus(0.1f, 1.2f, 80,40);
                                glColor3d(0, 0.2, 0.3);
                                glutSolidTorus(0.1f, 1.4f, 80, 40);
                                glColor3d(0, 0.1, 0.2);
                                glutSolidTorus(0.1f, 1.6f, 80, 40);

                            glPopMatrix();
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();
    glPopMatrix();


    glutSwapBuffers();
}

void klawisze_specjalne(int key, int x, int y)
{
     switch(key)
     {
         case GLUT_KEY_LEFT:
             alfa -= PI / 32;
             pointx = skok_point * cos (alfa) + eyex;
             pointz = skok_point * sin (alfa) + eyez;
         break;
         case GLUT_KEY_RIGHT:
             alfa += PI / 32;
             pointx = skok_point * cos (alfa) + eyex;
             pointz = skok_point * sin (alfa) + eyez;
         break;
         case GLUT_KEY_UP:
             skok_eye += 10.0f;
             eyex = skok_eye * cos (alfa) + eyex;
             eyez = skok_eye * sin (alfa) + eyez;
             pointx = skok_point * cos (alfa) + eyex;
             pointz = skok_point * sin (alfa) + eyez;
             skok_eye = 0.0f;
         break;
         case GLUT_KEY_DOWN:
             skok_eye -= 10.0f;
             eyex = skok_eye * cos (alfa) + eyex;
             eyez = skok_eye * sin (alfa) + eyez;
             pointx = skok_point * cos (alfa) + eyex;
             pointz = skok_point * sin (alfa) + eyez;
             skok_eye = 0.0f;
         break;
     }
     resize(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
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
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutSpecialFunc(klawisze_specjalne);
    glutIdleFunc(idle);


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
