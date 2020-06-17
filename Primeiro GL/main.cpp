#ifdef _WIN32
#include <windows.h>
#define _USE_MATH_DEFINES
#endif

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

// Função chamada para desenhar na tela
void display()
{
	// Define a cor de fundo
	glClearColor(1, 1, 1, 1); // R, G, B, A de 0 a 1, A (alpha) não é usado e pode ser qualquer valor

	// Limpa a tela com a cor definida no glClearColor
	glClear(GL_COLOR_BUFFER_BIT);

	// Define a cor usada por todos os vértices definidos após essa chamada
	glColor3f(1, 0, 0);  // R, G, B de 0 a 1

	// Define os vértices do triângulo (ver OpenGL primitives no Google!)
	glBegin(GL_LINES);
	glVertex2f(-1, -1);  // X,  Y,  a tela vai de -1, -1 (inferior esquerdo) a 1, 1 (superior direito)
	glVertex2f(0, 1);
	glEnd();



	glBegin(GL_LINES);
	glVertex2f(0.75, 1);  // X,  Y,  a tela vai de -1, -1 (inferior esquerdo) a 1, 1 (superior direito)
	glVertex2f(0.75, -1);
	glEnd();



	/*
	// ponto final
	glPushMatrix();                      //
	
	glTranslatef(0.9, -0.9, 0);
	glColor3f(1, 0, 0);
	glutSolidSphere(0.1, 32, 32);
	glColor3f(1, 1, 1);
	glutSolidSphere(0.07, 32, 32);
	glColor3f(1, 0, 0);
	glutSolidSphere(0.04, 32, 32);

	glColor3f(0,1,0);
	glTranslatef(0, 0.5, 0);
	glutSolidSphere(0.05, 32, 32);

	glColor3f(0,0,1);
	glTranslatef(0,  0.1, 0);
	glutSolidSphere(0.05, 32, 32);
	glPopMatrix();
	glPopMatrix();

	*/
















	//              
	

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

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600); // tamanho da janela

	glutCreateWindow("Aula 1"); // cria uma janela com o título especificado
	glutReshapeFunc(reshape); // define a função que será chamada quando a janela redimensionar
	glutDisplayFunc(display); // define a função que será chamada para desenhar

	glutMainLoop();  // loop de eventos do freeglut
	return 0;
}