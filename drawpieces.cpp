#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <shaderprogram.h>
#include <drawpieces.h>
#include <allmodels.h>

DrawPieces* dp;

void DrawPieces::drawPieces(glm::mat4 M) { 

	glm::mat4 M1 = M;

	glUniform4f(sp->u("color"), 0, 0, 0, 1);
	glUniformMatrix4fv(sp->u("M"), 1, false, glm::value_ptr(M1));

	glEnableVertexAttribArray(sp->a("vertex"));  //W³¹cz przesy³anie danych do atrybutu vertex
	glVertexAttribPointer(sp->a("vertex"), 4, GL_FLOAT, false, 0, bishopVerts); //Wska¿ tablicê z danymi dla atrybutu vertex

	glEnableVertexAttribArray(sp->a("normals"));
	glVertexAttribPointer(sp->a("normals"), 4, GL_FLOAT, false, 0, bishopNormals);

	glEnableVertexAttribArray(sp->a("texCoord0"));
	glVertexAttribPointer(sp->a("texCoord0"), 2, GL_FLOAT, false, 0, bishopTexCoords);

	glDrawArrays(GL_TRIANGLES, 0, bishopNumVerts); //Narysuj obiekt
}
