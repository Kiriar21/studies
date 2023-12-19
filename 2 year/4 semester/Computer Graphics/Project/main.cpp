//definiowanie gluta
#ifdef __APPLE__
#include "glpomoc.h"
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

//definiowanie wbudowanych bibliotek c++
#include <windows.h>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <cmath>

//definiowanie wlasnych bibliotek c++
#include "Biblioteki/materials.h"
#include "Biblioteki/biblioteka.h"
#include "Biblioteki/glpomoc.h"

using namespace std;

//Wczytanie tekstur
#define LICZBA_OB_TEXTUR 3
GLuint obiektyTextur [LICZBA_OB_TEXTUR];
char *plikiTextur[LICZBA_OB_TEXTUR] = {"D:\\Studia\\Semestr 4\\Grafika Komputerowa\\Laboratoria\\Projekt_grafika_lab\\Matuszczyk_135869_Projekt_Lab9\\Tekstury\\drzwi.tga",
"D:\\Studia\\Semestr 4\\Grafika Komputerowa\\Laboratoria\\Projekt_grafika_lab\\Matuszczyk_135869_Projekt_Lab9\\Tekstury\\szyba.tga",
"D:\\Studia\\Semestr 4\\Grafika Komputerowa\\Laboratoria\\Projekt_grafika_lab\\Matuszczyk_135869_Projekt_Lab9\\Tekstury\\klamka.tga"};

//Zmienne do tworzenia teksur
int lWez,lEle, **Ele;
double **Wez;

int lWez1, lEle1, **Ele1;
double **Wez1;

int lWez2, lEle2, **Ele2;
double **Wez2;

//Wspolrzedne
double gx=-5, gy=-10;

//Zmienne do ruchu kamery
GLfloat PI = 3.14, alfa = -PI / 2, skok_point = 300.0f, skok_eye = 10.0f, eyex = 0, eyey = 0, eyez = -1, pointx = skok_point * cos (alfa), pointy = 0.0, pointz = skok_point * sin (alfa);

//Zmienne do obracania teksturami
float rotationAngle = 0.0f,rotationSpeed = 1.0f, translationAngle = 0.0f, translationSpeed = 1.0f, nextAngle = 0.0f, nextSpeed = 1.0f;

//Zmienne do ruszania obiektem
double prevMouseX = 0.0, prevMouseY = 0.0;

//Zmienne do reflektorow w swietle kierunkowym
static float katRef=30, skupRef=2;
GLfloat fPozycja_reflektora[4] ={0.0f, 0.0f, -4.f, 1.0f};
GLfloat fKierunek_reflektora[4] ={0.f, 1.2f, -6.f, 1.0f};
GLfloat fSlabe_swiatlo[] ={0.0f, 0.2f, 0.0f, 1.0f};
GLfloat fMocne_swiatlo[] ={0.0f, 1.0f, 0.0f, 1.0f};
const GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

//Zmienne do perspektyw
GLfloat aktualny_zakres = 12.0f, blisko = 1.0f, daleko= 100.0f;
GLdouble aspect = 1;

//zmienne do menu
enum { ORTO,
 SKALA_1_1,
 PERSP,
 FRUST,
 EXIT
 };

//zmienne do zarzadzania widokami
int rzut=-1, skala=-1, kat = 90;

static void display(void)
{
    glLoadIdentity();

    //ustalenie koloru tla
    glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    gluLookAt (eyex, eyey, eyez, pointx, pointy, pointz, 0.0, 1.0, 0.0);
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_CULL_FACE);

    glPushMatrix();

        //ustalenia podstawowe dla tekstur
        glTranslated(gx,gy,-40);
        glScaled(1,1,1);

        //wywolanie rotacji - poruszania drzwiami
        glRotated(translationAngle,5,0,0);
        glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);
        glTranslatef(0.0f, nextAngle,-5.0f);

        //Nakładanie tekstur na drzwi
        glBindTexture(GL_TEXTURE_2D, 1);
        glBegin(GL_TRIANGLES);
            for(int nrEl = 0; nrEl < lEle; nrEl++)
            {
                glNormal3f(0.0f, 1.0f, 0.0f);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(Wez[Ele[nrEl][0]][0], Wez[Ele[nrEl][0]][1], Wez[Ele[nrEl][0]][2]);
                glTexCoord2f(1.0f, 0.0f);
                glVertex3f(Wez[Ele[nrEl][1]][0], Wez[Ele[nrEl][1]][1], Wez[Ele[nrEl][1]][2]);
                glTexCoord2f(1.0f, 1.0f);
                glVertex3f(Wez[Ele[nrEl][2]][0], Wez[Ele[nrEl][2]][1], Wez[Ele[nrEl][2]][2]);
            }
        glEnd();

        //Nakładanie tekstur na szybe
        glBindTexture(GL_TEXTURE_2D, 2);
        glBegin(GL_TRIANGLES);
            for(int nrEl1 = 0; nrEl1 < lEle1; nrEl1++)
            {
                glNormal3f(0.0f, 1.0f, 0.0f);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(Wez1[Ele1[nrEl1][0]][0], Wez1[Ele1[nrEl1][0]][1], Wez1[Ele1[nrEl1][0]][2]);
                glTexCoord2f(1.0f, 0.0f);
                glVertex3f(Wez1[Ele1[nrEl1][1]][0], Wez1[Ele1[nrEl1][1]][1], Wez1[Ele1[nrEl1][1]][2]);
                glTexCoord2f(1.0f, 1.0f);
                glVertex3f(Wez1[Ele1[nrEl1][2]][0], Wez1[Ele1[nrEl1][2]][1], Wez1[Ele1[nrEl1][2]][2]);
            }
        glEnd();

        //Nakładanie tekstur na klamke
        glBindTexture(GL_TEXTURE_2D, 3);
        glBegin(GL_TRIANGLES);
            for(int nrEl = 0; nrEl < lEle2; nrEl++)
            {
                glNormal3f(0.0f, 1.0f, 0.0f);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(Wez2[Ele2[nrEl][0]][0], Wez2[Ele2[nrEl][0]][1], Wez2[Ele2[nrEl][0]][2]);
                glTexCoord2f(1.0f, 0.0f);
                glVertex3f(Wez2[Ele2[nrEl][1]][0], Wez2[Ele2[nrEl][1]][1], Wez2[Ele2[nrEl][1]][2]);
                glTexCoord2f(1.0f, 1.0f);
                glVertex3f(Wez2[Ele2[nrEl][2]][0], Wez2[Ele2[nrEl][2]][1], Wez2[Ele2[nrEl][2]][2]);
            }
        glEnd();
        glEnable(GL_CULL_FACE);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //Tworzenie podłogi
    for(int j=0;j<10;j++)
    {
        for(int i=0;i<8;i++)
        {
            glPushMatrix();
            if((i+j)%2==0)
            {
                glColor4f(1,1,1,0.1);
            }
            else
            {
                glColor4f(0,0,0,0.8);
            }
            glTranslatef(-4+i,-1,-10+j);
            glBegin(GL_QUADS);
            glVertex3f(-0.5,-1,-0.5);
            glVertex3f(-0.5,-1,0.5);
            glVertex3f(0.5,-1,0.5);
            glVertex3f(0.5,-1,-0.5);
            glEnd();
            glPopMatrix();
        }
    }
    glEnable(GL_TEXTURE_2D);

    //pierwsza sfera
    glPushMatrix();
        glTranslated(2.4,1.2,-6);
        glRotated(a*2,1,0,0);
        glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);
        glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);
        glutSolidSphere(1,20,20);
        glDisable(GL_TEXTURE_GEN_S);
        glDisable(GL_TEXTURE_GEN_T);
    glPopMatrix();

    //druga sfera
    glPushMatrix();
        glTranslated(0,1.2,0);
        glRotated(a*2,1,0,0);
        glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);
        glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);
        glutSolidSphere(1,20,20);
        glDisable(GL_TEXTURE_GEN_S);
        glDisable(GL_TEXTURE_GEN_T);
    glPopMatrix();

    //trzecia sfera
    glPushMatrix();
        glTranslated(-2.4,1.2,-6);
        glRotated(a*2,1,0,0);
        glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);
        glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);
        glutSolidSphere(1,20,20);
        glDisable(GL_TEXTURE_GEN_S);
        glDisable(GL_TEXTURE_GEN_T);
    glPopMatrix();

    //czajnik :D
    glPushMatrix();
        glTranslated(0,0,-60);
        glRotated(a*a,1,0,0);
        glDisable(GL_TEXTURE_GEN_S);
        glDisable(GL_TEXTURE_GEN_T);
        glutSolidTeapot(1.0);
    glPopMatrix();

    glutSwapBuffers();
}

void resize(int width, int height)
{
    const float ar = (float) width / (float) height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //Warunkowo zmiana widoku
    if (rzut == ORTO)
    {
        glOrtho(-aktualny_zakres, aktualny_zakres, -aktualny_zakres, aktualny_zakres, -4 * aktualny_zakres, 4 * aktualny_zakres);
    }
    else if (rzut == PERSP)
    {
        if (height > 0)
        {
            aspect = width / (GLdouble) height;
            gluPerspective(kat, aspect, blisko, daleko);
        }
    }
    else
    {
        glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    display();
}

static void mouseMove(int x, int y)
{

    //Przystosowanie ruchu myszka do rozdzielczosci FullHD
    double mouseX = x / 1920.0 * 22 - 11;
    double mouseY = -y / 1080.0 * 14 + 7;
    double dx = mouseX - prevMouseX;
    double dy = mouseY - prevMouseY;
    gx += dx;
    gy += dy;
    prevMouseX = mouseX;
    prevMouseY = mouseY;
    display();
}

void klawisze_specjalne(int key, int x, int y)
{
    //ruch kamery
    switch(key)
    {
        case GLUT_KEY_UP:
            skok_eye += 10.0f;
            eyex = skok_eye * cos (alfa) + eyex;
            eyez = skok_eye * sin (alfa) + eyez;
            pointx = skok_point * cos (alfa) + eyex;
            pointz = skok_point * sin (alfa) + eyez;
            skok_eye = 0.0f;
            aktualny_zakres += 10.0f;
            break;

        case GLUT_KEY_DOWN:
            skok_eye -= 10.0f;
            eyex = skok_eye * cos (alfa) + eyex;
            eyez = skok_eye * sin (alfa) + eyez;
            pointx = skok_point * cos (alfa) + eyex;
            pointz = skok_point * sin (alfa) + eyez;
            skok_eye = 0.0f;
            aktualny_zakres -= 10.0f;
            break;

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
    }
    resize(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

static void key(unsigned char key, int x, int y)
{
    //Obsluga klawiatury - rusznie tekstura i reflektorem + wyjscie
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case 'a':
            fPozycja_reflektora[0] -= 0.1;
            glLightfv(GL_LIGHT1, GL_POSITION, fPozycja_reflektora);
            break;

        case 'd':
            fPozycja_reflektora[0] += 0.1;
            glLightfv(GL_LIGHT1, GL_POSITION, fPozycja_reflektora);
            break;

        case 'g':
            fKierunek_reflektora[0] -= 0.1;
            glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, fKierunek_reflektora);
            break;

        case 'j':
            fKierunek_reflektora[0] += 0.1;
            glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, fKierunek_reflektora);
            break;

        case '1':
            skupRef -= 1;
            glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, skupRef);
            break;

        case '2':
            skupRef += 1;
            glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, skupRef);
            break;

        case '3':
            katRef += 1;
            glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, katRef);
            break;

        case '4':
            katRef -= 1;
            glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, katRef);
            break;

        case '5':
            rotationAngle += rotationSpeed;
            break;

        case '6':
            rotationAngle -= rotationSpeed;
            break;

        case '7':
            translationAngle += translationSpeed;
            break;

        case '8':
            translationAngle -= translationSpeed;
            break;

        case '9':
            nextAngle += nextSpeed;
            break;

        case '0':
            nextAngle -= nextSpeed;
            break;

        default:
            break;
    }
    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

void wczytajPlik(char *nazwaPliku, char *nazwaPliku1, char *nazwaPliku2 )
{
    //wczytanie tekstury drzwi
    ifstream plik(nazwaPliku);
    int pom1;
    plik>>lWez;
    Wez = new double* [lWez];
    for(int i=0; i<lWez; i++)
    {
        Wez[i]=new double[3];
    }
    for(int i=0;i<lWez;i++)
    {
        plik>>pom1>>Wez[i][0]>>Wez[i][1]>>Wez[i][2];
    }
    plik>>lEle;
    Ele = new int* [lEle];
    for(int i=0; i<lEle; i++)
    {
        Ele[i]=new int[3];
    }
    for(int i=0; i<lEle;i++)
    {
        plik>>pom1>>pom1>>pom1>>pom1>>pom1>>Ele[i][0]>>Ele[i][1]>>Ele[i][2];
        Ele[i][0]--;
        Ele[i][1]--;
        Ele[i][2]--;
    }
    cout<<"Liczba wezlow: "<<lWez<<"\t"<<"Liczba elementow: "<<lEle<<endl;
    plik.close();

    //wczytanie tekstury szyby
    ifstream plik1(nazwaPliku1);
    plik1>>lWez1;
    Wez1 = new double* [lWez1];
    for(int i=0; i<lWez1; i++)
    {
        Wez1[i]=new double[3];
    }
    for(int i=0;i<lWez1;i++)
    {
        plik1>>pom1>>Wez1[i][0]>>Wez1[i][1]>>Wez1[i][2];
    }
    plik1>>lEle1;
    Ele1 = new int* [lEle1];
    for(int i=0; i<lEle1; i++)
    {
       Ele1[i]=new int[3];
    }

    for(int i=0; i<lEle1;i++)
    {
        plik1>>pom1>>pom1>>pom1>>pom1>>pom1>>Ele1[i][0]>>Ele1[i][1]>>Ele1[i][2];
        Ele1[i][0]--;
        Ele1[i][1]--;
        Ele1[i][2]--;
    }
    cout<<"Liczba wezlow: "<<lWez1<<"\t"<<"Liczba elementow: "<<lEle1<<endl;
    plik1.close();

    //wczytanie tekstury klamki
    ifstream plik2(nazwaPliku2);
    plik2>>lWez2;
    Wez2 = new double* [lWez2];
    for(int i=0; i<lWez2; i++)
    {
        Wez2[i]=new double[3];
    }
    for(int i=0;i<lWez2;i++)
    {
        plik2>>pom1>>Wez2[i][0]>>Wez2[i][1]>>Wez2[i][2];
    }
    plik2>>lEle2;
    Ele2 = new int* [lEle2];
    for(int i=0; i<lEle2; i++)
    {
        Ele2[i]=new int[3];
    }
    for(int i=0; i<lEle2;i++)
    {
        plik2>>pom1>>pom1>>pom1>>pom1>>pom1>>Ele2[i][0]>>Ele2[i][1]>>Ele2[i][2];
        Ele2[i][0]--;
        Ele2[i][1]--;
        Ele2[i][2]--;
    }
    cout<<"Liczba wezlow: "<<lWez2<<"\t"<<"Liczba elementow: "<<lEle2<<endl;
    plik2.close();
}

void MainMenu(int value)
{
    switch (value)
    {
        case EXIT:
        exit (0);
    }
}

void menuswiatlo(int value)
{
    //ustawienia swiatla - wlacz
    if(value == 0)
    {
        glDisable(GL_LIGHT1);
        glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);
        glEnable(GL_LIGHT0);
    }
    //ustawienia swiatla - wylacz
    else if(value == 1)
    {
        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHT1);
    }
    //ustawienia swiatla kierunkowego
    else if(value == 2)
    {
        glDisable(GL_LIGHT0);
        glLightfv (GL_LIGHT1, GL_AMBIENT, fSlabe_swiatlo);
        glLightfv (GL_LIGHT1, GL_DIFFUSE, fMocne_swiatlo);
        glLightfv (GL_LIGHT1, GL_SPECULAR, fMocne_swiatlo);
        glEnable(GL_LIGHT1);
    }
}

void menuintensywnosc(int value)
{
    // wartosci dla swiatla - slabe
    if(value == 6)
    {
        glLightfv(GL_LIGHT0, GL_AMBIENT, fSlabe_swiatlo);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, fSlabe_swiatlo);
        glLightfv(GL_LIGHT0, GL_SPECULAR, fSlabe_swiatlo);
    }

    // wartosci dla swiatla - mocne
    if(value == 7)
    {
        glLightfv(GL_LIGHT0, GL_AMBIENT, fMocne_swiatlo);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, fMocne_swiatlo);
        glLightfv(GL_LIGHT0, GL_SPECULAR, fMocne_swiatlo);
    }

    // wartosci dla swiatla kierunkowego - slabe
    if (value == 8)
    {
        glLightfv(GL_LIGHT1, GL_AMBIENT, fSlabe_swiatlo);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, fSlabe_swiatlo);
        glLightfv(GL_LIGHT1, GL_SPECULAR, fSlabe_swiatlo);
    }

    // wartosci dla swiatla kierunkowego - mocne
    if (value == 9)
    {
        glLightfv(GL_LIGHT1, GL_AMBIENT, fMocne_swiatlo);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, fMocne_swiatlo);
        glLightfv(GL_LIGHT1, GL_SPECULAR, fMocne_swiatlo);
    }
}

void MenuR(int value)
{
    //menu dla perpektyw
    switch (value)
    {
        case ORTO:
            rzut=ORTO;
            resize(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
            break;

        case PERSP:
            rzut=PERSP;
            resize(glutGet (GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
            break;

        case FRUST:
            rzut=FRUST;
            resize(glutGet (GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
    }
}

int main(int argc, char *argv[])
{
    //opis sterowania i informacje
    cout<<"Autor: Artur Matuszczyk \nProjekt na przedmiot: Grafika Komputerowa rok 2022/2023 semest zimowy\nRozdzielczosc projektu wyswietlanego 1920x1080 (FullHD)\n\n";
    cout<<"Menu poruszania sie po programie:\n"<<
    "1 - zmniejsza skupienie reflektora"<<"\n"<<
    "2 - zwieksza skupienie reflektora"<<"\n"<<
    "3 - zwieksza kat reflektora"<<"\n"<<
    "4 - zmniejsza kat reflektora"<<"\n"<<
    "5 - obraca drzwi w lewo"<<"\n"<<
    "6 - obraca drzwi w prawo"<<"\n"<<
    "7 - obraca drzwi do przodu"<<"\n"<<
    "8 - obraca drzwi do tylu"<<"\n"<<
    "9 - przesuwa drzwi w gore"<<"\n"<<
    "0 - przesuwa drzwi w dol"<<"\n"<<
    "q - wyjscie"<<"\n"<<
    "a - zmienia pozycje reflektora w lewo"<<"\n"<<
    "d - zmienia pozycje reflektora w prawo"<<"\n"<<
    "g - zmienia kierunek reflektora w lewo"<<"\n"<<
    "j - zmienia kierunek reflektora w prawo"<<"\n"<<
    "strzalki - ruch kamera"<<"\n"<<
    "lewy przycisk myszy - obrot obiektem\n\n\n"<<"Potwierdzenie wczytania 3 tekstur:"<<endl;

    //wczytanie tekstur
    wczytajPlik("D:\\Studia\\Semestr 4\\Grafika Komputerowa\\Laboratoria\\Projekt_grafika_lab\\Matuszczyk_135869_Projekt_Lab9\\Msh\\drzwi.msh",
                "D:\\Studia\\Semestr 4\\Grafika Komputerowa\\Laboratoria\\Projekt_grafika_lab\\Matuszczyk_135869_Projekt_Lab9\\Msh\\szyba.msh",
                "D:\\Studia\\Semestr 4\\Grafika Komputerowa\\Laboratoria\\Projekt_grafika_lab\\Matuszczyk_135869_Projekt_Lab9\\Msh\\klamka.msh");

    //poczatek projektu
    glutInit(&argc, argv);

    //ustalenie rozmiaru okna
    glutInitWindowSize(1920,1080);
    glutInitWindowPosition(10,10);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    //nazwa okna aplikacji
    glutCreateWindow("Projekt Grafika Lab9 22/23 Matuszczyk Artur");

    //wlaczenie tekstur
    glEnable(GL_TEXTURE_2D);

    //Przygotowanie tablicy tekstur
    glGenTextures(LICZBA_OB_TEXTUR, obiektyTextur);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //Tworzenie i wywolywanie funkcji do utworzenia tekstur z wczytanych plikow msh - drzwi
    GLubyte *pBytes1;
    GLint iWidth1, iHeight1, iComponents1;
    GLenum eFormat1;
    pBytes1 = glploadtga(plikiTextur[0], &iWidth1, &iHeight1, &iComponents1, &eFormat1);

    //szyba
    GLubyte *pBytes2;
    GLint iWidth2, iHeight2, iComponents2;
    GLenum eFormat2;
    pBytes2 = glploadtga(plikiTextur[1], &iWidth2, &iHeight2, &iComponents2, &eFormat2);

    //klamka
    GLubyte *pBytes3;
    GLint iWidth3, iHeight3, iComponents3;
    GLenum eFormat3;
    pBytes3 = glploadtga(plikiTextur[2], &iWidth3, &iHeight3, &iComponents3, &eFormat3);

    // Bryła 1 - przypisanie tekstury do jednostki teksturującej 1
    glBindTexture(GL_TEXTURE_2D, 1);
    glTexImage2D(GL_TEXTURE_2D, 0, iComponents1, iWidth1, iHeight1, 0, eFormat1, GL_UNSIGNED_BYTE, pBytes1);
    gluBuild2DMipmaps(GL_TEXTURE_2D, iComponents1, iWidth1, iHeight1, eFormat1, GL_UNSIGNED_BYTE, pBytes1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Bryła 2 - przypisanie tekstury do jednostki teksturującej 2
    glBindTexture(GL_TEXTURE_2D, 2);
    glTexImage2D(GL_TEXTURE_2D, 0, iComponents2, iWidth2, iHeight2, 0, eFormat2, GL_UNSIGNED_BYTE, pBytes2);
    gluBuild2DMipmaps(GL_TEXTURE_2D, iComponents2, iWidth2, iHeight2, eFormat2, GL_UNSIGNED_BYTE, pBytes2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Bryła 3 - przypisanie tekstury do jednostki teksturującej 3
    glBindTexture(GL_TEXTURE_2D, 3);
    glTexImage2D(GL_TEXTURE_2D, 0, iComponents3, iWidth3, iHeight3, 0, eFormat3, GL_UNSIGNED_BYTE, pBytes3);
    gluBuild2DMipmaps(GL_TEXTURE_2D, iComponents3, iWidth3, iHeight3, eFormat3, GL_UNSIGNED_BYTE, pBytes3);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //Nakladanie tekstur na obiekty
    glBindTexture(GL_TEXTURE_2D, obiektyTextur[0]);
    glBindTexture(GL_TEXTURE_2D, obiektyTextur[1]);
    glBindTexture(GL_TEXTURE_2D, obiektyTextur[2]);


    //Wywolanie funkcji - potrzebne do dzialania programu
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutSpecialFunc(klawisze_specjalne);
    glutIdleFunc(idle);
    glutMotionFunc(mouseMove);


    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    //Ustalenie swiatla
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glLightf (GL_LIGHT1, GL_SPOT_CUTOFF,katRef);
    glLightf(GL_LIGHT1,GL_SPOT_EXPONENT,skupRef);

    glLightfv (GL_LIGHT1, GL_AMBIENT, fSlabe_swiatlo);
    glLightfv (GL_LIGHT1, GL_DIFFUSE, fMocne_swiatlo);
    glLightfv (GL_LIGHT1, GL_SPECULAR, fMocne_swiatlo);
    glLightfv (GL_LIGHT1, GL_POSITION, fPozycja_reflektora);
    glLightfv (GL_LIGHT1, GL_SPOT_DIRECTION, fKierunek_reflektora);

    //Tworzenie menu
    int swiatlo = glutCreateMenu (menuswiatlo);
    glutAddMenuEntry ("Wlacz swiatlo", 0);
    glutAddMenuEntry ("Wylacz swiatlo", 1);
    glutAddMenuEntry ("Wlacz swiatlo kierunkowe", 2);

    int intensywnosc1 = glutCreateMenu (menuintensywnosc);
    glutAddMenuEntry ("Slabe", 6);
    glutAddMenuEntry ("Mocne", 7);

    int intensywnosc2 = glutCreateMenu (menuintensywnosc);
    glutAddMenuEntry ("Slabe", 8);
    glutAddMenuEntry ("Mocne", 9);

    int perspektywa = glutCreateMenu (MenuR);
    glutAddMenuEntry ("Ortogonalny", ORTO);
    glutAddMenuEntry ("perspektywiczny", PERSP);
    glutAddMenuEntry ("perspektywiczny frustrum", FRUST);

    int mainMenu = glutCreateMenu(MainMenu);
    glutAddSubMenu("Oswietlenie", swiatlo);
    glutAddSubMenu("Intensywnosc swiatla", intensywnosc1);
    glutAddSubMenu("Intensywnosc swiatla kierunkowego", intensywnosc2);
    glutAddSubMenu("Widok", perspektywa);
    glutAddMenuEntry ("Wyjscie",EXIT);
    glutAttachMenu (GLUT_RIGHT_BUTTON);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutMainLoop();

    return EXIT_SUCCESS;
}
