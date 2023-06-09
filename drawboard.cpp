#include <drawboardheader.h>

DrawBoard* db;

// Inicjalizacja textur
void DrawBoard::initTextures() {
	texWhite = rt->readTexture("bmarble.png");
	texBlack = rt->readTexture("wmarble.png");
	texSurfaceBoard = rt->readTexture("marble.png");
}

// Rysowanie planszy
void DrawBoard::drawBoard(glm::mat4 M) {

	glm::mat4 M1 = M;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			M1 = glm::translate(M1, glm::vec3(1.0f, 0.0f, 0.0f));

			glUniformMatrix4fv(sp->u("M"), 1, false, glm::value_ptr(M1));

			glEnableVertexAttribArray(sp->a("vertex"));  //W��cz przesy�anie danych do atrybutu vertex
			glVertexAttribPointer(sp->a("vertex"), 4, GL_FLOAT, false, 0, fieldVerts); //Wska� tablic� z danymi dla atrybutu vertex

			glEnableVertexAttribArray(sp->a("normals"));
			glVertexAttribPointer(sp->a("normals"), 4, GL_FLOAT, false, 0, fieldNormals);

			glEnableVertexAttribArray(sp->a("texCoord0"));
			glVertexAttribPointer(sp->a("texCoord0"), 2, GL_FLOAT, false, 0, fieldTexCoords);

			if (i % 2 == 0) {
				if (j % 2 == 0) {
					glActiveTexture(GL_TEXTURE0);
					glBindTexture(GL_TEXTURE_2D, texWhite);
				}
				else {
					glActiveTexture(GL_TEXTURE0);
					glBindTexture(GL_TEXTURE_2D, texBlack);
				}
			}
			else {
				if (j % 2 == 0) {
					glActiveTexture(GL_TEXTURE0);
					glBindTexture(GL_TEXTURE_2D, texBlack);
				}
				else {
					glActiveTexture(GL_TEXTURE0);
					glBindTexture(GL_TEXTURE_2D, texWhite);
				}
			}

			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_TEXTURE_2D, texSurfaceBoard);

			glDrawArrays(GL_TRIANGLES, 0, fieldNumVerts); //Narysuj obiekt
		}
		if (i < 7) {
			M1 = glm::translate(M1, glm::vec3(-8.0f, 0.0f, 1.0f));
		}
	}
}