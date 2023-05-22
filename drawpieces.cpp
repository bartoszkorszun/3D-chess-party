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
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

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

	glEnableVertexAttribArray(sp->a("vertex"));  //W��cz przesy�anie danych do atrybutu vertex
	glVertexAttribPointer(sp->a("vertex"), 4, GL_FLOAT, false, 0, verts); //Wska� tablic� z danymi dla atrybutu vertex

	glEnableVertexAttribArray(sp->a("normals"));
	glVertexAttribPointer(sp->a("normals"), 4, GL_FLOAT, false, 0, normals);

	glEnableVertexAttribArray(sp->a("texCoord0"));
	glVertexAttribPointer(sp->a("texCoord0"), 2, GL_FLOAT, false, 0, texCoords);

	glDrawArrays(GL_TRIANGLES, 0, numVerts); //Narysuj obiekt
}

string moves[107][2];

void DrawPieces::readFile(string filename) {

	ifstream inputFile("party.txt"); // Replace "example.txt" with your file path

	if (inputFile.is_open()) {
		int i = 0;
		int j = 0;
		string move;
		string line;

		while (getline(inputFile, line)) {
			
			stringstream ss(line);
			while (ss >> move) {
				moves[i][j] = move;
				j++;
			}
			j = 0;
			i++;
		}

		inputFile.close(); // Close the file when finished reading
	}
	else {
		cout << "Failed to open the file." << endl;
	}
}

int nextMove = 0;
bool isFinished = false;
bool castle = false;

float fNextPosition[2];

void nextPosition(string sNextPosition) {
	
	// A
	if (sNextPosition == "a1") { fNextPosition[0] = a1[0]; fNextPosition[1] = a1[1]; }
	if (sNextPosition == "a2") { fNextPosition[0] = a2[0]; fNextPosition[1] = a2[1]; }
	if (sNextPosition == "a3") { fNextPosition[0] = a3[0]; fNextPosition[1] = a3[1]; }
	if (sNextPosition == "a4") { fNextPosition[0] = a4[0]; fNextPosition[1] = a4[1]; }
	if (sNextPosition == "a5") { fNextPosition[0] = a5[0]; fNextPosition[1] = a5[1]; }
	if (sNextPosition == "a6") { fNextPosition[0] = a6[0]; fNextPosition[1] = a6[1]; }
	if (sNextPosition == "a7") { fNextPosition[0] = a7[0]; fNextPosition[1] = a7[1]; }
	if (sNextPosition == "a8") { fNextPosition[0] = a8[0]; fNextPosition[1] = a8[1]; }

	// B
	if (sNextPosition == "b1") { fNextPosition[0] = b1[0]; fNextPosition[1] = b1[1]; }
	if (sNextPosition == "b2") { fNextPosition[0] = b2[0]; fNextPosition[1] = b2[1]; }
	if (sNextPosition == "b3") { fNextPosition[0] = b3[0]; fNextPosition[1] = b3[1]; }
	if (sNextPosition == "b4") { fNextPosition[0] = b4[0]; fNextPosition[1] = b4[1]; }
	if (sNextPosition == "b5") { fNextPosition[0] = b5[0]; fNextPosition[1] = b5[1]; }
	if (sNextPosition == "b6") { fNextPosition[0] = b6[0]; fNextPosition[1] = b6[1]; }
	if (sNextPosition == "b7") { fNextPosition[0] = b7[0]; fNextPosition[1] = b7[1]; }
	if (sNextPosition == "b8") { fNextPosition[0] = b8[0]; fNextPosition[1] = b8[1]; }

	// C
	if (sNextPosition == "c1") { fNextPosition[0] = c1[0]; fNextPosition[1] = c1[1]; }
	if (sNextPosition == "c2") { fNextPosition[0] = c2[0]; fNextPosition[1] = c2[1]; }
	if (sNextPosition == "c3") { fNextPosition[0] = c3[0]; fNextPosition[1] = c3[1]; }
	if (sNextPosition == "c4") { fNextPosition[0] = c4[0]; fNextPosition[1] = c4[1]; }
	if (sNextPosition == "c5") { fNextPosition[0] = c5[0]; fNextPosition[1] = c5[1]; }
	if (sNextPosition == "c6") { fNextPosition[0] = c6[0]; fNextPosition[1] = c6[1]; }
	if (sNextPosition == "c7") { fNextPosition[0] = c7[0]; fNextPosition[1] = c7[1]; }
	if (sNextPosition == "c8") { fNextPosition[0] = c8[0]; fNextPosition[1] = c8[1]; }

	// D
	if (sNextPosition == "d1") { fNextPosition[0] = d1[0]; fNextPosition[1] = d1[1]; }
	if (sNextPosition == "d2") { fNextPosition[0] = d2[0]; fNextPosition[1] = d2[1]; }
	if (sNextPosition == "d3") { fNextPosition[0] = d3[0]; fNextPosition[1] = d3[1]; }
	if (sNextPosition == "d4") { fNextPosition[0] = d4[0]; fNextPosition[1] = d4[1]; }
	if (sNextPosition == "d5") { fNextPosition[0] = d5[0]; fNextPosition[1] = d5[1]; }
	if (sNextPosition == "d6") { fNextPosition[0] = d6[0]; fNextPosition[1] = d6[1]; }
	if (sNextPosition == "d7") { fNextPosition[0] = d7[0]; fNextPosition[1] = d7[1]; }
	if (sNextPosition == "d8") { fNextPosition[0] = d8[0]; fNextPosition[1] = d8[1]; }
	
	// E
	if (sNextPosition == "e1") { fNextPosition[0] = e1[0]; fNextPosition[1] = e1[1]; }
	if (sNextPosition == "e2") { fNextPosition[0] = e2[0]; fNextPosition[1] = e2[1]; }
	if (sNextPosition == "e3") { fNextPosition[0] = e3[0]; fNextPosition[1] = e3[1]; }
	if (sNextPosition == "e4") { fNextPosition[0] = e4[0]; fNextPosition[1] = e4[1]; }
	if (sNextPosition == "e5") { fNextPosition[0] = e5[0]; fNextPosition[1] = e5[1]; }
	if (sNextPosition == "e6") { fNextPosition[0] = e6[0]; fNextPosition[1] = e6[1]; }
	if (sNextPosition == "e7") { fNextPosition[0] = e7[0]; fNextPosition[1] = e7[1]; }
	if (sNextPosition == "e8") { fNextPosition[0] = e8[0]; fNextPosition[1] = e8[1]; }
	
	// F
	if (sNextPosition == "f1") { fNextPosition[0] = f1[0]; fNextPosition[1] = f1[1]; }
	if (sNextPosition == "f2") { fNextPosition[0] = f2[0]; fNextPosition[1] = f2[1]; }
	if (sNextPosition == "f3") { fNextPosition[0] = f3[0]; fNextPosition[1] = f3[1]; }
	if (sNextPosition == "f4") { fNextPosition[0] = f4[0]; fNextPosition[1] = f4[1]; }
	if (sNextPosition == "f5") { fNextPosition[0] = f5[0]; fNextPosition[1] = f5[1]; }
	if (sNextPosition == "f6") { fNextPosition[0] = f6[0]; fNextPosition[1] = f6[1]; }
	if (sNextPosition == "f7") { fNextPosition[0] = f7[0]; fNextPosition[1] = f7[1]; }
	if (sNextPosition == "f8") { fNextPosition[0] = f8[0]; fNextPosition[1] = f8[1]; }
	
	// G
	if (sNextPosition == "g1") { fNextPosition[0] = g1[0]; fNextPosition[1] = g1[1]; }
	if (sNextPosition == "g2") { fNextPosition[0] = g2[0]; fNextPosition[1] = g2[1]; }
	if (sNextPosition == "g3") { fNextPosition[0] = g3[0]; fNextPosition[1] = g3[1]; }
	if (sNextPosition == "g4") { fNextPosition[0] = g4[0]; fNextPosition[1] = g4[1]; }
	if (sNextPosition == "g5") { fNextPosition[0] = g5[0]; fNextPosition[1] = g5[1]; }
	if (sNextPosition == "g6") { fNextPosition[0] = g6[0]; fNextPosition[1] = g6[1]; }
	if (sNextPosition == "g7") { fNextPosition[0] = g7[0]; fNextPosition[1] = g7[1]; }
	if (sNextPosition == "g8") { fNextPosition[0] = g8[0]; fNextPosition[1] = g8[1]; }
	
	// H
	if (sNextPosition == "h1") { fNextPosition[0] = h1[0]; fNextPosition[1] = h1[1]; }
	if (sNextPosition == "h2") { fNextPosition[0] = h2[0]; fNextPosition[1] = h2[1]; }
	if (sNextPosition == "h3") { fNextPosition[0] = h3[0]; fNextPosition[1] = h3[1]; }
	if (sNextPosition == "h4") { fNextPosition[0] = h4[0]; fNextPosition[1] = h4[1]; }
	if (sNextPosition == "h5") { fNextPosition[0] = h5[0]; fNextPosition[1] = h5[1]; }
	if (sNextPosition == "h6") { fNextPosition[0] = h6[0]; fNextPosition[1] = h6[1]; }
	if (sNextPosition == "h7") { fNextPosition[0] = h7[0]; fNextPosition[1] = h7[1]; }
	if (sNextPosition == "h8") { fNextPosition[0] = h8[0]; fNextPosition[1] = h8[1]; }
}

void movePiece(string moveToPosition, float &x, float &y, float &z) {

	nextPosition(moveToPosition);

	// TODO
}

void DrawPieces::movePieces() {
	
	if (moves[nextMove][0] == "castle") { castle = true; nextMove++; }
	
	if (castle) {
		
	}
	
	if (!castle) {
		// Rooks
		if (moves[nextMove][0] == "rwl") { movePiece(moves[nextMove][1], rookWLX, rookWLY, rookWLZ); }
		if (moves[nextMove][0] == "rwr") { movePiece(moves[nextMove][1], rookWRX, rookWRY, rookWRZ); }
		if (moves[nextMove][0] == "rbl") { movePiece(moves[nextMove][1], rookBLX, rookBLY, rookBLZ); }
		if (moves[nextMove][0] == "rbr") { movePiece(moves[nextMove][1], rookBRX, rookBRY, rookBRZ); }

		// Knights
		if (moves[nextMove][0] == "kwl") { movePiece(moves[nextMove][1], knightWLX, knightWLY, knightWLZ); }
		if (moves[nextMove][0] == "kwr") { movePiece(moves[nextMove][1], knightWRX, knightWRY, knightWRZ); }
		if (moves[nextMove][0] == "kbl") { movePiece(moves[nextMove][1], knightBLX, knightBLY, knightBLZ); }
		if (moves[nextMove][0] == "kbr") { movePiece(moves[nextMove][1], knightBRX, knightBRY, knightBRZ); }

		// Bishops
		if (moves[nextMove][0] == "bwl") { movePiece(moves[nextMove][1], bishopWLX, bishopWLY, bishopWLZ); }
		if (moves[nextMove][0] == "bwr") { movePiece(moves[nextMove][1], bishopWRX, bishopWRY, bishopWRZ); }
		if (moves[nextMove][0] == "bbl") { movePiece(moves[nextMove][1], bishopBLX, bishopBLY, bishopBLZ); }
		if (moves[nextMove][0] == "bbr") { movePiece(moves[nextMove][1], bishopBRX, bishopBRY, bishopBRZ); }

		// Queens
		if (moves[nextMove][0] == "qw") { movePiece(moves[nextMove][1], queenWX, queenWY, queenWZ); }
		if (moves[nextMove][0] == "qb") { movePiece(moves[nextMove][1], queenBX, queenBY, queenBZ); }

		// Kings
		if (moves[nextMove][0] == "kw") { movePiece(moves[nextMove][1], kingWX, kingWY, kingWZ); }
		if (moves[nextMove][0] == "kb") { movePiece(moves[nextMove][1], kingBX, kingBY, kingBZ); }

		// Pawns
		if (moves[nextMove][0] == "pw1") { movePiece(moves[nextMove][1], pawnW1X, pawnW1Y, pawnW1Z); }
		if (moves[nextMove][0] == "pw2") { movePiece(moves[nextMove][1], pawnW2X, pawnW2Y, pawnW2Z); }
		if (moves[nextMove][0] == "pw3") { movePiece(moves[nextMove][1], pawnW3X, pawnW3Y, pawnW3Z); }
		if (moves[nextMove][0] == "pw4") { movePiece(moves[nextMove][1], pawnW4X, pawnW4Y, pawnW4Z); }
		if (moves[nextMove][0] == "pw5") { movePiece(moves[nextMove][1], pawnW5X, pawnW5Y, pawnW5Z); }
		if (moves[nextMove][0] == "pw6") { movePiece(moves[nextMove][1], pawnW6X, pawnW6Y, pawnW6Z); }
		if (moves[nextMove][0] == "pw7") { movePiece(moves[nextMove][1], pawnW7X, pawnW7Y, pawnW7Z); }
		if (moves[nextMove][0] == "pw8") { movePiece(moves[nextMove][1], pawnW8X, pawnW8Y, pawnW8Z); }

		if (moves[nextMove][0] == "pb1") { movePiece(moves[nextMove][1], pawnB1X, pawnB1Y, pawnB1Z); }
		if (moves[nextMove][0] == "pb2") { movePiece(moves[nextMove][1], pawnB2X, pawnB2Y, pawnB2Z); }
		if (moves[nextMove][0] == "pb3") { movePiece(moves[nextMove][1], pawnB3X, pawnB3Y, pawnB3Z); }
		if (moves[nextMove][0] == "pb4") { movePiece(moves[nextMove][1], pawnB4X, pawnB4Y, pawnB4Z); }
		if (moves[nextMove][0] == "pb5") { movePiece(moves[nextMove][1], pawnB5X, pawnB5Y, pawnB5Z); }
		if (moves[nextMove][0] == "pb6") { movePiece(moves[nextMove][1], pawnB6X, pawnB6Y, pawnB6Z); }
		if (moves[nextMove][0] == "pb7") { movePiece(moves[nextMove][1], pawnB7X, pawnB7Y, pawnB7Z); }
		if (moves[nextMove][0] == "pb8") { movePiece(moves[nextMove][1], pawnB8X, pawnB8Y, pawnB8Z); }
	}

	if (isFinished) {
		nextMove++;
		isFinished = false;
	}
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