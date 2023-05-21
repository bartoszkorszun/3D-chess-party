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
#include <initpositions.h>

#include <chrono>
#include <thread>

DrawPieces* dp;

void drawPiece(glm::mat4 M,float x, float y, float z, bool isWhite, 
	float verts[], float normals[], float texCoords[], unsigned int numVerts) {

	glm::mat4 M1 = M;
	M1 = glm::translate(M, glm::vec3(x, y, z));

	if (isWhite) {
		M1 = glm::rotate(M1, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(sp->u("color"), 1, 1, 1, 1);
	}
	else {
		M1 = glm::rotate(M1, glm::radians(270.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform4f(sp->u("color"), 0, 0, 0, 1);
	}

	glUniformMatrix4fv(sp->u("M"), 1, false, glm::value_ptr(M1));

	glEnableVertexAttribArray(sp->a("vertex"));  //W³¹cz przesy³anie danych do atrybutu vertex
	glVertexAttribPointer(sp->a("vertex"), 4, GL_FLOAT, false, 0, verts); //Wska¿ tablicê z danymi dla atrybutu vertex

	glEnableVertexAttribArray(sp->a("normals"));
	glVertexAttribPointer(sp->a("normals"), 4, GL_FLOAT, false, 0, normals);

	glEnableVertexAttribArray(sp->a("texCoord0"));
	glVertexAttribPointer(sp->a("texCoord0"), 2, GL_FLOAT, false, 0, texCoords);

	glDrawArrays(GL_TRIANGLES, 0, numVerts); //Narysuj obiekt
}

void DrawPieces::movePieces() {
	
}

void DrawPieces::drawPieces(glm::mat4 M) { 

	// Rooks
	drawPiece(M, rookWLX, rookWLY, rookWLZ, true, rookVerts, rookNormals, rookTexCoords, rookNumVerts);
	drawPiece(M, rookWRX, rookWRY, rookWRZ, true, rookVerts, rookNormals, rookTexCoords, rookNumVerts);
	drawPiece(M, rookBLX, rookBLY, rookBLZ, false, rookVerts, rookNormals, rookTexCoords, rookNumVerts);
	drawPiece(M, rookBRX, rookBRY, rookBRZ, false, rookVerts, rookNormals, rookTexCoords, rookNumVerts);

	// Knights
	drawPiece(M, knightWLX, knightWLY, knightWLZ, true, knightVerts, knightNormals, knightTexCoords, knightNumVerts);
	drawPiece(M, knightWRX, knightWRY, knightWRZ, true, knightVerts, knightNormals, knightTexCoords, knightNumVerts);
	drawPiece(M, knightBLX, knightBLY, knightBLZ, false, knightVerts, knightNormals, knightTexCoords, knightNumVerts);
	drawPiece(M, knightBRX, knightBRY, knightBRZ, false, knightVerts, knightNormals, knightTexCoords, knightNumVerts);

	// Bishops
	drawPiece(M, bishopWLX, bishopWLY, bishopWLZ, true, bishopVerts, bishopNormals, bishopTexCoords, bishopNumVerts);
	drawPiece(M, bishopWRX, bishopWRY, bishopWRZ, true, bishopVerts, bishopNormals, bishopTexCoords, bishopNumVerts);
	drawPiece(M, bishopBLX, bishopBLY, bishopBLZ, false, bishopVerts, bishopNormals, bishopTexCoords, bishopNumVerts);
	drawPiece(M, bishopBRX, bishopBRY, bishopBRZ, false, bishopVerts, bishopNormals, bishopTexCoords, bishopNumVerts);

	// Queens
	drawPiece(M, queenWX, queenWY, queenWZ, true, queenVerts, queenNormals, queenTexCoords, queenNumVerts);
	drawPiece(M, queenBX, queenBY, queenBZ, false, queenVerts, queenNormals, queenTexCoords, queenNumVerts);

	// Kings
	drawPiece(M, kingWX, kingWY, kingWZ, true, kingVerts, kingNormals, kingTexCoords, kingNumVerts);
	drawPiece(M, kingBX, kingBY, kingBZ, false, kingVerts, kingNormals, kingTexCoords, kingNumVerts);

	// Pawns
	// White
	drawPiece(M, pawnW1X, pawnW1Y, pawnW1Z, true, pawnVerts, pawnNormals, pawnTexCoords, pawnNumVerts);
	drawPiece(M, pawnW2X, pawnW2Y, pawnW2Z, true, pawnVerts, pawnNormals, pawnTexCoords, pawnNumVerts);
	drawPiece(M, pawnW3X, pawnW3Y, pawnW3Z, true, pawnVerts, pawnNormals, pawnTexCoords, pawnNumVerts);
	drawPiece(M, pawnW4X, pawnW4Y, pawnW4Z, true, pawnVerts, pawnNormals, pawnTexCoords, pawnNumVerts);
	drawPiece(M, pawnW5X, pawnW5Y, pawnW5Z, true, pawnVerts, pawnNormals, pawnTexCoords, pawnNumVerts);
	drawPiece(M, pawnW6X, pawnW6Y, pawnW6Z, true, pawnVerts, pawnNormals, pawnTexCoords, pawnNumVerts);
	drawPiece(M, pawnW7X, pawnW7Y, pawnW7Z, true, pawnVerts, pawnNormals, pawnTexCoords, pawnNumVerts);
	drawPiece(M, pawnW8X, pawnW8Y, pawnW8Z, true, pawnVerts, pawnNormals, pawnTexCoords, pawnNumVerts);

	// Black
	drawPiece(M, pawnB1X, pawnB1Y, pawnB1Z, false, pawnVerts, pawnNormals, pawnTexCoords, pawnNumVerts);
	drawPiece(M, pawnB2X, pawnB2Y, pawnB2Z, false, pawnVerts, pawnNormals, pawnTexCoords, pawnNumVerts);
	drawPiece(M, pawnB3X, pawnB3Y, pawnB3Z, false, pawnVerts, pawnNormals, pawnTexCoords, pawnNumVerts);
	drawPiece(M, pawnB4X, pawnB4Y, pawnB4Z, false, pawnVerts, pawnNormals, pawnTexCoords, pawnNumVerts);
	drawPiece(M, pawnB5X, pawnB5Y, pawnB5Z, false, pawnVerts, pawnNormals, pawnTexCoords, pawnNumVerts);
	drawPiece(M, pawnB6X, pawnB6Y, pawnB6Z, false, pawnVerts, pawnNormals, pawnTexCoords, pawnNumVerts);
	drawPiece(M, pawnB7X, pawnB7Y, pawnB7Z, false, pawnVerts, pawnNormals, pawnTexCoords, pawnNumVerts);
	drawPiece(M, pawnB8X, pawnB8Y, pawnB8Z, false, pawnVerts, pawnNormals, pawnTexCoords, pawnNumVerts);
}