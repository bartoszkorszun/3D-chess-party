#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <shaderprogram.h>
#include <drawboard.h>
#include <field.h>

DrawBoard* db;

void DrawBoard::drawBoard(glm::mat4 M) {

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