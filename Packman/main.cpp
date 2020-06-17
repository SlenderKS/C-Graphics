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

float posx = 0;
float posy = 0;

#include <iostream>
#include <cstdlib>



double v1 = (rand() % 8) / 10;
double v2 = (rand() % 8) / 10;

#include <time.h>
// FAZER RELOGIO COM UM RELOGIO DOS MINUTOS 

// CIRCULO (PREENCHIDO)
void drawCircle(float radius) {
	glBegin(GL_POLYGON); // ou GL_LINE_LOOP
	for (float ang = 0; ang <= 2 * PI; ang += 0.01) {
		glVertex2f(radius * cos(ang), radius * sin(ang));
	}
	glEnd();

}

void bocaMove(float radius) {
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);  // R, G, B de 0 a 1
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(3, 2.5);
	glVertex2f(3, -2.5);
	glEnd();
}

void bocaMove_left(float radius) {
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);  // R, G, B de 0 a 1
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(3, 2.5);
	glVertex2f(3, -2.5);
	glEnd();
}

void olho(float radius) {
	glBegin(GL_POLYGON); // ou GL_LINE_LOOP
	for (float ang = 0; ang <= 2 * PI; ang += 0.01) {
		glVertex2f(radius * cos(ang), 0.35 + radius * sin(ang));
	}
	glEnd();

}



// CIRCUNFERENCIA
void drawCircle2(float radius) {
	glBegin(GL_LINE_LOOP); // ou GL_LINE_LOOP
	for (float ang = 0; ang <= 2 * PI; ang += 0.01) {
		glVertex2f(radius * cos(ang), radius * sin(ang));
	}
	glEnd();
}

void drawHoras(float radius) {
	glBegin(GL_LINES);
	for (float ang = 0; ang <= 2 * PI; ang += 2 * PI / 12) {
		glVertex2f(radius * cos(ang), radius * sin(ang));
		glVertex2f((radius - 0.1) * cos(ang), (radius - 0.1) *sin(ang));
	}
	glEnd();
}

//Corpo do Pacman
void drawPacman() {
	glColor3f(1, 1, 0);
	drawCircle(0.5);
}

void drawPilula(float radius) {
	float v1 = (rand() % 8);
	float v2 = (rand() % 8) ;

	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON); // ou GL_LINE_LOOP
	for (float ang = 0; ang <= 2 * PI; ang += 0.01) {
		glVertex2f(v2 + radius * cos(ang), v1 +   radius * sin(ang));
	}
	glEnd();
}

float f(float x) {
	return sin(-x * PI);
}


bool contador_virardelado = false;
// Função chamada para desenhar na tela
void display() {



	time_t now = time(NULL); // retorna o tempo em MS que passou em segundos des de 1/1/1970(foi o ano que inventaram o time)
	tm* tmnow = localtime(&now); // detro do tm existe definição da data de hj
	int hora = tmnow->tm_hour;
	int min = tmnow->tm_min;
	int sec = tmnow->tm_sec;
	int mls = sec / 1000;
	//int mls = tmnow->tm_

	static float t = 0;
	t += 0.01;
	/*
	float m[16] = { 0.5,  0,    0,  0,     //  |===============
					0  ,  0.5,  0,  0,     //  |
					0  ,  0,    1,  0,     //  |
					0  ,  0,    0,  1      //  |----meche na escala, para deixar no normal, coloque 1
	};                                     //  |
										   //  |
	glLoadMatrixf(m);                      //  |===============   //sobrescreve modelView
 // glMultMatrixxf(m);               -->acumla m*modelview

	*/

	float m[16] = { 1 ,    0,  0,  0,     //  |===============
					0   , 1,  0,  0,     //  |
					0   ,    0,  1,  0,     //  |
					posx, posy,  0,  1      //  |----meche na escala, para deixar no normal, coloque 1
	};                                     //  |
										   //  |
	glLoadMatrixf(m);                      //  |===============   //sobrescreve modelView
 // glMultMatrixxf(m);               -->acumla m*modelview
	/*

// atalho: glLoadIdentity();

	static float t = 0;
	t += 0.01;
	// Define a cor de fundo
	glClearColor(1, 1, 1, 1); // R, G, B, A de 0 a 1, A (alpha) não é usado e pode ser qualquer valor
	*/

	// Limpa a tela com a cor definida no glClearColor
	glClear(GL_COLOR_BUFFER_BIT);



	drawPacman();
	/*
	// Corpo do Packman
	glColor3f(1, 1, 0);
	drawCircle(0.5);
	*/


	//Desenhar o olho
	glColor3f(0, 0, 0);
	olho(0.06);

	drawPilula(0.05);
	//glColor3f(1, 0, 0);
	//drawCircle(0.3);

	

	//Definição da boca do packman mechendo (com o loop)
	float ang = sec * 1 / 4 * PI / 2; // Precisa ser [esgundo *  * PI * quantidade de pi] , logo, >> [sec * 1/4 * PI * 2]

	glColor3f(0, 0, 0);  // R, G, B de 0 a 1
	glBegin(GL_POLYGON);


	//int contador_somador = 0;
	//int contador_somador = contador_somador + 1;
	//bool contador_virardelado = true;
	if (contador_virardelado == false) {
		if (sec % 2 == 0) {
			glVertex2f(0, 0);
			glVertex2f(3, 3);
			glVertex2f(3, 0);
			glEnd();
		}
		else {
			glVertex2f(0, 0);
			glVertex2f(3, 0.01);
			glVertex2f(3, 0);
			glEnd();
		}
	}
	else {
		if (sec % 2 == 0) {
			glVertex2f(0, 0);
			glVertex2f(-3, 3);
			glVertex2f(-3, 0);
			glEnd();
		}
		else {
			glVertex2f(0, 0);
			glVertex2f(3, -0.01);
			glVertex2f(3, 0);
			glEnd();
		}

	}
	//Desenhar moldura para as horas.
	////glColor3f(1,1,1);
	//glVertex2f(0.5 , 0.5);           // quero fazer o ponteiro do relógio aqui
	//
	//glEnd();

	//glBegin(GL_LINE_STRIP);
	//for (float x = -1; x <= 1; x += 0.01) {         //... x+= 0.01
	//	glColor3f(1, 0, 0);                  // seto a cor
	//	glVertex2f(x+t,f(x));
	//		
	//	}
	//glEnd();




	// Executa os comandos e desenha na tela
	glutSwapBuffers();

	glutPostRedisplay();


}






// Função chamada quando a janela é redimensionada
void reshape(int w, int h)
{
	// Redimensiona a tela
	glViewport(0, 0, w, h);
}

//(KEYPRESS);

int counter_cimabaixo = 0;
int counter_esquerdadireita = 0;


void keypress(unsigned char k, int x, int y) {
	// A ideia é fazer ele virar de lado. Se esta "false" ele fica para direita, e se fica "true" ele vira para esquerda.

	switch (k) {
	case 'a':
		if (counter_esquerdadireita > -5) {
			counter_esquerdadireita = counter_esquerdadireita - 1;

			posx -= 0.1;
			contador_virardelado = true;
		}
		break;
	case 'w':
		if (counter_cimabaixo < 5) {
			counter_cimabaixo = counter_cimabaixo + 1;
			posy += 0.1;
		}
		break;
	case 's':
		if (counter_cimabaixo > -5) {
			counter_cimabaixo = counter_cimabaixo - 1;
			posy -= 0.1;
		}
		break;
	case 'd':
		if (counter_esquerdadireita < 5) {
			counter_esquerdadireita = counter_esquerdadireita + 1;
			posx += 0.1;
			contador_virardelado = false;
		}
		break;
	}
}


/*  QUAL O PROBLEMA NESSE MODO DOG ?
void keypress(unsigned char k, int x, int y) {
	// A ideia é fazer ele virar de lado. Se esta "false" ele fica para direita, e se fica "true" ele vira para esquerda.

	switch (k) {
	case 'a':
		if (posx > -0.5){
			posx -= 0.1;
			contador_virardelado = true;
		}
		break;
	case 'w':
		if (posy < 0.5){
			posy += 0.1;
		}
		break;
	case 's':
		if (posy > -0.5){
			posy -= 0.1;
		}
		break;
	case 'd':
		if (posx > 0.5){
			posx += 0.1;
			contador_virardelado = false;
		}
		break;
	}
}
*/

void Timer(int iUnused) {
	glutPostRedisplay();
	glutTimerFunc(2, Timer, 0);
}

/*  https://www.youtube.com/watch?v=Oa5RWmR2OvI
void update(int value) {
	_angle += 2.0f;
	if (_angle > 360) {
		_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}
*/

int main(int argc, char* argv[])
{


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600); // tamanho da janela

	glutCreateWindow("Aula 1"); // cria uma janela com o título especificado
	glutReshapeFunc(reshape); // define a função que será chamada quando a janela redimensionar
	glutDisplayFunc(display); // define a função que será chamada para desenhar
	glutKeyboardFunc(keypress);


	glutMainLoop();  // loop de eventos do freeglut  --- nao pode ter nada depois dessa linha ---
	return 0;
}
