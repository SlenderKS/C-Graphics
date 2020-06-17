#ifdef _WIN32
#include <windows.h>
#define _USE_MATH_DEFINES
#endif

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdio.h>
#include <math.h>

#define PI 3.14159265

#include <time.h> 
// ela será usada para o fazer do relógio andar

// CIRCULO (PRAENCHIDO)
void drawCircle(float radius) {
	glBegin(GL_POLYGON); // ou GL_LINE_LOOP
	for (float ang = 0; ang <= 2 * PI; ang += 0.01) {
		glVertex2f(radius * cos(ang), radius * sin(ang));
	}
	glEnd();
}

//CIRCUNFERENCIA
void DrawCircle2(float radius) {
	glBegin(GL_LINE_LOOP);
	for (float ang = 0; ang <= 2 * PI; ang += 0.01) {
		glVertex2f(radius*cos(ang), radius * sin(ang));
	}
}

void drawHoras(float radius) {
	glBegin(GL_LINES);
	for (float ang = 0; ang <= 2 * PI; ang += 2 * PI / 12) {
		glVertex2f(radius * cos(ang), radius * sin(ang));
		glVertex2f((radius - 0.1) * cos(ang), (radius - 0.1) * sin(ang));
	}
	glEnd();
}

float fl(float x) {
	return sin(-x * PI);
}

//Função chamada para desenhar na tela
void Display() {
	time_t now = time(NULL); // retorna o tempo em MS que passou em segundos des de 1/1/1970 (foi o ano em que inventaram o time)
	tm* tmnow = localtime(&now); // dentro do tm existe definição de data de hj
	int hora = tmnow->tm_hour;
	int min = tmnow->tm_min;
	int sec = tmnow->tm_sec;

	static float t = 0;
	t += 0.01;
	// Define a cor de fundo
	glClearColor(1, 1, 1, 1); // R G B A  de 0 a 1 , alpha não é usado e pode ser qualquer valor

	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
	glColor3f(0.5, 0, 0);
	glVertex2f(-1, -1);
	glVertex2f(-1, 1);
	glColor3f(0, 0, 0);
	glVertex2f(1, 1);
	glVertex2f(1, -1);
	glEnd();

	glColor3f(0, 0, 0);
	drawCircle(0.55);

	glColor3f(0, 0, 0);
	drawCircle(0.55);

	glColor3f(0.2, 0.2, 0.2);
	drawHoras(0.5);
	// Define a cor usadada por todos os vértices definidos após essa chamada
	glColor3f(0, 0, 0); //R, G, B de 0 a 1

	// Desenhando os ponteiros
	//glBegin(GK_Lines);
	//glLineWidth(2);
	//glVertex2f(-0.5 , 0);
	//glVertex2f(0.5 , 0);
	//glEnd();

	//
	float ang = sec * 2 * PI / 60;
	float ang2 = min * 2 * PI / 60;
	float ang3 = hora * 2 * PI / 12;

	glColor3f(0.6, 0, 0);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(0.5 * sin(ang), 0.5*cos(ang));
	glEnd();

	glColor3f(0, 0, 0);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(0.5*sin(ang2), 0.5*cos(ang2));
	glEnd();

	glColor3f(0, 0, 0);
	glLineWidth(10);
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(0.3*sin(ang3), 0.3*cos(ang3));
	glEnd();

	//Desenhar moldura para as horas.

	//glColor3f(0 , 0 , 0); // R, G , B de 0 a 1
	//glBergin(GL_LINES);
	//glLineWidth(2);
	//glVertex2f(-1, 0);   //X, Y,    a tela vai de -1, 1 (inferior esquerdo) a 1,1 (superior direito)
	//glVertex2f(1, 0);
	//glVertex2f(0, 1);  // X, Y, a tela vai de -1, -1 (inferior esquerdo) a 1, 1 (superior direito)
	//glVertex2f(0, -1);

	//glColor3f(1, 1, 1);
	//glVertex2f(0.5 , 0.5);    // quero fazer o ponteiro do relógio aqui
	//
	//glEnd();

	//glBegin(GL_LINE_STRIP);
	//for (float x = -1; x<=1; x+= 0.01){         // ... x+= 0.01
	//		glColor3f(1,0,0);                         //seto a cor
	//      glVertex2f(x+t, f(x) );
	//      
	//      }
	//glEnd();

	// Executa os comandos e desenha na tela
	glutSwapBuffers();
	glutPostRedisplay();
}

// Função chamada quando a janlea é redimensionada 
void reshape(int w, int h) {
	//redimensiona a tela
	glViewport(0, 0, w, h);
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600); // tamanho da janela

	glutCreateWindow("Aula 1"); //cria uma janela com o título especificado
	glutReshapeFunc(reshape); // define a função que será chamada quando a janlea redimensionar
	glutDisplayFunc(Display); // define a função que será chamada para desenhar


	glutMainLoop();  //loop de eventos do freeglut
	return 0;
}

// glBegin(GL_LINESTRIP);
// for (float x=-1; x<=1; x<=1; x+=0.01){
//      glVertex
// }
//
//
//
//
//
//