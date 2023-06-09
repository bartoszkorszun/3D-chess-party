#include <mainheader.h>

void error_callback(int error, const char* description) {
	fputs(description, stderr);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		if (key == GLFW_KEY_LEFT) speed_x = -PI / 2;
		if (key == GLFW_KEY_RIGHT) speed_x = PI / 2;
		if (key == GLFW_KEY_UP) speed_y = PI / 2;
		if (key == GLFW_KEY_DOWN) speed_y = -PI / 2;
		if (key == GLFW_KEY_SPACE) play = !play;
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
	glClearColor(0, 0, 0, 1);
	glfwSetWindowSizeCallback(window, windowResizeCallback);
	glfwSetKeyCallback(window, keyCallback);

	db->initTextures(); // Zainicjowanie tekstur planszy
	dp->initTextures(); // Zainicjowanie tekstur pionk�w
	sp = new ShaderProgram("v_simplest.glsl", NULL, "f_simplest.glsl");
	dp->readFile("party.txt"); // odczytanie danych z pliku rozgrywki
}

void freeOpenGLProgram(GLFWwindow* window) {

	delete db;
	delete dp;
	delete sp;
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

	// Rysowanie planszy
	db->drawBoard(M);

	// Rysowanie pionk�w
	dp->drawPieces(M);

	sp->use();//Aktywacja programu cieniuj�cego
	//Przeslij parametry programu cieniuj�cego do karty graficznej
	glUniformMatrix4fv(sp->u("P"), 1, false, glm::value_ptr(P));
	glUniformMatrix4fv(sp->u("V"), 1, false, glm::value_ptr(V));
	
	// �r�d�a �wiat�a
	glUniform4f(sp->u("lp1"), 2, 2, 0, 1);
	glUniform4f(sp->u("lp2"), -2, 2, 0, 1);

	glUniform1i(sp->u("textureMap0"), 0);
	glUniform1i(sp->u("textureMap1"), 1);

	glDisableVertexAttribArray(sp->a("vertex"));  //Wy��cz przesy�anie danych do atrybutu vertex
	glDisableVertexAttribArray(sp->a("normals"));
	glDisableVertexAttribArray(sp->a("texCoord0"));

	glfwSwapBuffers(window);
}

int main(void) {

	GLFWwindow* window;

	glfwSetErrorCallback(error_callback);

	if (!glfwInit()) {
		fprintf(stderr, "Nie mo�na zainicjowa� GLFW.\n");
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(800, 800, "OpenGL", NULL, NULL);

	if (!window)
	{
		fprintf(stderr, "Nie mo�na utworzy� okna.\n");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Nie mo�na zainicjowa� GLEW.\n");
		exit(EXIT_FAILURE);
	}

	initOpenGLProgram(window);

	while (!glfwWindowShouldClose(window)) {
		
		// Blokada obrotu planszy
		angle_x += speed_x * glfwGetTime();
		if ((angle_y >= 0 && angle_y < 0.2) || angle_y <= 0 && angle_y > -1.5) {
			angle_y += speed_y * glfwGetTime();
		} 
		else {
			if (angle_y < 0) angle_y = -1.49;
			if (angle_y > 0) angle_y = 0.19;
		}
		
		if(play) dp->movePieces(); // Wywo�anie metody z ruchami

		glfwSetTime(0);
		drawScene(window);
		glfwPollEvents();
	}

	freeOpenGLProgram(window);

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}