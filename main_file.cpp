#define GLM_FORCE_RADIANS

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <shaderprogram.h>
#include <constants.h>
#include <allmodels.h>

void error_callback(int error, const char* description) {
	fputs(description, stderr);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		if (key == GLFW_KEY_LEFT) speed_x = -PI / 2;
		if (key == GLFW_KEY_RIGHT) speed_x = PI / 2;
		if (key == GLFW_KEY_UP) speed_y = PI / 2;
		if (key == GLFW_KEY_DOWN) speed_y = -PI / 2;
	}
	if (action == GLFW_RELEASE) {
		if (key == GLFW_KEY_LEFT) speed_x = 0;
		if (key == GLFW_KEY_RIGHT) speed_x = 0;
		if (key == GLFW_KEY_UP) speed_y = 0;
		if (key == GLFW_KEY_DOWN) speed_y = 0;
	}
}

void windowResizeCallback(GLFWwindow* window, int width, int height) {
	if (height == 0) return;
	aspectRatio = (float)width / (float)height;
	glViewport(0, 0, width, height);
}

void initOpenGLProgram(GLFWwindow* window) {
	
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.3, 0.3, 0.3, 1);
	glfwSetWindowSizeCallback(window, windowResizeCallback);
	glfwSetKeyCallback(window, keyCallback);

	sp = new ShaderProgram("v_simplest.glsl", NULL, "f_simplest.glsl");

	printf("init\n");
}

void freeOpenGLProgram(GLFWwindow* window) {

	delete sp;

	printf("free");
}

void drawBoard(glm::mat4 M) {

	glm::mat4 M1 = M;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			M1 = glm::translate(M1, glm::vec3(1.0f, 0.0f, 0.0f));

			if (i % 2 == 0) {
				if (j % 2 == 0) {
					glUniform4f(sp->u("color"), 0, 0, 0, 1);
				}
				else {
					glUniform4f(sp->u("color"), 1, 1, 1, 1);
				}
			}
			else {
				if (j % 2 == 0) {
					glUniform4f(sp->u("color"), 1, 1, 1, 1);
				}
				else {
					glUniform4f(sp->u("color"), 0, 0, 0, 1);
				}
			}
		
			glUniformMatrix4fv(sp->u("M"), 1, false, glm::value_ptr(M1));

			glEnableVertexAttribArray(sp->a("vertex"));  //W³¹cz przesy³anie danych do atrybutu vertex
			glVertexAttribPointer(sp->a("vertex"), 4, GL_FLOAT, false, 0, fieldVerts); //Wska¿ tablicê z danymi dla atrybutu vertex

			glEnableVertexAttribArray(sp->a("normals"));
			glVertexAttribPointer(sp->a("normals"), 4, GL_FLOAT, false, 0, fieldNormals);

			glEnableVertexAttribArray(sp->a("texCoord0"));
			glVertexAttribPointer(sp->a("texCoord0"), 2, GL_FLOAT, false, 0, fieldTexCoords);

			glDrawArrays(GL_TRIANGLES, 0, fieldNumVerts); //Narysuj obiekt
		}
		if (i < 7) {
			M1 = glm::translate(M1, glm::vec3(-8.0f, 0.0f, 1.0f));
		}
	}
}

void drawPieces(glm::mat4 M) {


}

void drawScene(GLFWwindow* window) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Wyliczenie macierzy widoku
	glm::mat4 V = glm::lookAt(
		glm::vec3(0, 0, -5),
		glm::vec3(0, 0, 0),
		glm::vec3(0.0f, 1.0f, 0.0f));

	//Wyliczenie macierzy rzutowania perspektywicznego
	glm::mat4 P = glm::perspective(50.0f * PI / 180.0f, aspectRatio, 0.01f, 50.0f);

	//Podstawienie macierzy jednostkowej do macierzy modelu
	glm::mat4 M = glm::mat4(1.0f);
	M = glm::rotate(M, angle_y, glm::vec3(1.0f, 0.0f, 0.0f));
	M = glm::rotate(M, angle_x, glm::vec3(0.0f, 1.0f, 0.0f));
	M = glm::scale(M, glm::vec3(0.3f, 0.3f, 0.3f));
	M = glm::translate(M, glm::vec3(-4.5f, -3.0f, -3.5f));

	drawBoard(M);

	sp->use();//Aktywacja programu cieniuj¹cego
	//Przeslij parametry programu cieniuj¹cego do karty graficznej
	glUniformMatrix4fv(sp->u("P"), 1, false, glm::value_ptr(P));
	glUniformMatrix4fv(sp->u("V"), 1, false, glm::value_ptr(V));
	glUniform4f(sp->u("lp1"), 3, 5, 0, 1);
	glUniform4f(sp->u("lp2"), -3, 5, 0, 1);

	glDisableVertexAttribArray(sp->a("vertex"));  //Wy³¹cz przesy³anie danych do atrybutu vertex
	glDisableVertexAttribArray(sp->a("normals"));
	glDisableVertexAttribArray(sp->a("texCoord0"));

	glfwSwapBuffers(window);
}

int main(void) {

	GLFWwindow* window;

	glfwSetErrorCallback(error_callback);

	if (!glfwInit()) {
		fprintf(stderr, "Nie mo¿na zainicjowaæ GLFW.\n");
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(1400, 700, "OpenGL", NULL, NULL);

	if (!window)
	{
		fprintf(stderr, "Nie mo¿na utworzyæ okna.\n");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Nie mo¿na zainicjowaæ GLEW.\n");
		exit(EXIT_FAILURE);
	}

	initOpenGLProgram(window);

	while (!glfwWindowShouldClose(window)) {
		angle_x += speed_x * glfwGetTime();
		angle_y += speed_y * glfwGetTime();
		glfwSetTime(0);
		drawScene(window);
		glfwPollEvents();
	}

	freeOpenGLProgram(window);

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}