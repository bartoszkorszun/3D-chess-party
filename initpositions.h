#include <string>

using namespace std;

// Rooks
// White Left
float rookWLX = 1.0f;
float rookWLY = 0.2f;
float rookWLZ = 0.0f;
bool bRookWL = true;

// White Right
float rookWRX = 1.0f;
float rookWRY = 0.2f;
float rookWRZ = 7.0f;
bool bRookWR = true;

// Black Left
float rookBLX = 8.0f;
float rookBLY = 0.2f;
float rookBLZ = 7.0f;
bool bRookBL = true;

// Black Right
float rookBRX = 8.0f;
float rookBRY = 0.2f;
float rookBRZ = 0.0f;
bool bRookBR = true;

// Knights
// White Left
float knightWLX = 1.0f;
float knightWLY = 0.2f;
float knightWLZ = 1.0f;
bool bKnightWL = true;

// White Right
float knightWRX = 1.0f;
float knightWRY = 0.2f;
float knightWRZ = 6.0f;
bool bKnightWR = true;

// Black Left
float knightBLX = 8.0f;
float knightBLY = 0.2f;
float knightBLZ = 6.0f;
bool bKnightBL = true;

// Black Right
float knightBRX = 8.0f;
float knightBRY = 0.2f;
float knightBRZ = 1.0f;
bool bKnightBR = true;

// Bishops
// White Left
float bishopWLX = 1.0f;
float bishopWLY = 0.2f;
float bishopWLZ = 2.0f;
bool bBishopWL = true;

// White Right
float bishopWRX = 1.0f;
float bishopWRY = 0.2f;
float bishopWRZ = 5.0f;
bool bBishopWR = true;

// Black Left
float bishopBLX = 8.0f;
float bishopBLY = 0.2f;
float bishopBLZ = 5.0f;
bool bBishopBL = true;

// Black Right
float bishopBRX = 8.0f;
float bishopBRY = 0.2f;
float bishopBRZ = 2.0f;
bool bBishopBR = true;

// Queens
// White
float queenWX = 1.0f;
float queenWY = 0.2f;
float queenWZ = 3.0f;
bool bQueenW = true;

// Black
float queenBX = 8.0f;
float queenBY = 0.2f;
float queenBZ = 3.0f;
bool bQueenB = true;

// Kings
// White
float kingWX = 1.0f;
float kingWY = 0.2f;
float kingWZ = 4.0f;
bool bKingW = true;

// Black
float kingBX = 8.0f;
float kingBY = 0.2f;
float kingBZ = 4.0f;
bool bKingB = true;

// Pawns
// White 1
float pawnW1X = 2.0f;
float pawnW1Y = 0.2f;
float pawnW1Z = 0.0f;
bool bPawnW1 = true;

// White 2
float pawnW2X = 2.0f;
float pawnW2Y = 0.2f;
float pawnW2Z = 1.0f;
bool bPawnW2 = true;

// White 3
float pawnW3X = 2.0f;
float pawnW3Y = 0.2f;
float pawnW3Z = 2.0f;
bool bPawnW3 = true;

// White 4
float pawnW4X = 2.0f;
float pawnW4Y = 0.2f;
float pawnW4Z = 3.0f;
bool bPawnW4 = true;

// White 5
float pawnW5X = 2.0f;
float pawnW5Y = 0.2f;
float pawnW5Z = 4.0f;
bool bPawnW5 = true;

// White 6
float pawnW6X = 2.0f;
float pawnW6Y = 0.2f;
float pawnW6Z = 5.0f;
bool bPawnW6 = true;

// White 7
float pawnW7X = 2.0f;
float pawnW7Y = 0.2f;
float pawnW7Z = 6.0f;
bool bPawnW7 = true;

// White 8
float pawnW8X = 2.0f;
float pawnW8Y = 0.2f;
float pawnW8Z = 7.0f;
bool bPawnW8 = true;

// Black 1
float pawnB1X = 7.0f;
float pawnB1Y = 0.2f;
float pawnB1Z = 7.0f;
bool bPawnB1 = true;

// Black 2
float pawnB2X = 7.0f;
float pawnB2Y = 0.2f;
float pawnB2Z = 6.0f;
bool bPawnB2 = true;

// Black 3
float pawnB3X = 7.0f;
float pawnB3Y = 0.2f;
float pawnB3Z = 5.0f;
bool bPawnB3 = true;

// Black 4
float pawnB4X = 7.0f;
float pawnB4Y = 0.2f;
float pawnB4Z = 4.0f;
bool bPawnB4 = true;

// Black 5
float pawnB5X = 7.0f;
float pawnB5Y = 0.2f;
float pawnB5Z = 3.0f;
bool bPawnB5 = true;

// Black 6
float pawnB6X = 7.0f;
float pawnB6Y = 0.2f;
float pawnB6Z = 2.0f;
bool bPawnB6 = true;

// Black 7
float pawnB7X = 7.0f;
float pawnB7Y = 0.2f;
float pawnB7Z = 1.0f;
bool bPawnB7 = true;

// Black 8
float pawnB8X = 7.0f;
float pawnB8Y = 0.2f;
float pawnB8Z = 0.0f;
bool bPawnB8 = true;

// Fields
const float a1[] = { 1.0f, 0.0f };
const float a2[] = { 2.0f, 0.0f };
const float a3[] = { 3.0f, 0.0f };
const float a4[] = { 4.0f, 0.0f };
const float a5[] = { 5.0f, 0.0f };
const float a6[] = { 6.0f, 0.0f };
const float a7[] = { 7.0f, 0.0f };
const float a8[] = { 8.0f, 0.0f };

const float b1[] = { 1.0f, 1.0f };
const float b2[] = { 2.0f, 1.0f };
const float b3[] = { 3.0f, 1.0f };
const float b4[] = { 4.0f, 1.0f };
const float b5[] = { 5.0f, 1.0f };
const float b6[] = { 6.0f, 1.0f };
const float b7[] = { 7.0f, 1.0f };
const float b8[] = { 8.0f, 1.0f };

const float c1[] = { 1.0f, 2.0f };
const float c2[] = { 2.0f, 2.0f };
const float c3[] = { 3.0f, 2.0f };
const float c4[] = { 4.0f, 2.0f };
const float c5[] = { 5.0f, 2.0f };
const float c6[] = { 6.0f, 2.0f };
const float c7[] = { 7.0f, 2.0f };
const float c8[] = { 8.0f, 2.0f };

const float d1[] = { 1.0f, 3.0f };
const float d2[] = { 2.0f, 3.0f };
const float d3[] = { 3.0f, 3.0f };
const float d4[] = { 4.0f, 3.0f };
const float d5[] = { 5.0f, 3.0f };
const float d6[] = { 6.0f, 3.0f };
const float d7[] = { 7.0f, 3.0f };
const float d8[] = { 8.0f, 3.0f };

const float e1[] = { 1.0f, 4.0f };
const float e2[] = { 2.0f, 4.0f };
const float e3[] = { 3.0f, 4.0f };
const float e4[] = { 4.0f, 4.0f };
const float e5[] = { 5.0f, 4.0f };
const float e6[] = { 6.0f, 4.0f };
const float e7[] = { 7.0f, 4.0f };
const float e8[] = { 8.0f, 4.0f };

const float f1[] = { 1.0f, 5.0f };
const float f2[] = { 2.0f, 5.0f };
const float f3[] = { 3.0f, 5.0f };
const float f4[] = { 4.0f, 5.0f };
const float f5[] = { 5.0f, 5.0f };
const float f6[] = { 6.0f, 5.0f };
const float f7[] = { 7.0f, 5.0f };
const float f8[] = { 8.0f, 5.0f };

const float g1[] = { 1.0f, 6.0f };
const float g2[] = { 2.0f, 6.0f };
const float g3[] = { 3.0f, 6.0f };
const float g4[] = { 4.0f, 6.0f };
const float g5[] = { 5.0f, 6.0f };
const float g6[] = { 6.0f, 6.0f };
const float g7[] = { 7.0f, 6.0f };
const float g8[] = { 8.0f, 6.0f };

const float h1[] = { 1.0f, 7.0f };
const float h2[] = { 2.0f, 7.0f };
const float h3[] = { 3.0f, 7.0f };
const float h4[] = { 4.0f, 7.0f };
const float h5[] = { 5.0f, 7.0f };
const float h6[] = { 6.0f, 7.0f };
const float h7[] = { 7.0f, 7.0f };
const float h8[] = { 8.0f, 7.0f };

string currentPositions[32][2] = {
	{"a1","rwl"},
	{"b1","kwl"},
	{"c1","bwl"},
	{"d1","qw"},
	{"e1","kw"},
	{"f1","bwr"},
	{"g1","kwr"},
	{"h1","rwr"},
	{"a2","pw1"},
	{"b2","pw2"},
	{"c2","pw3"},
	{"d2","pw4"},
	{"e2","pw5"},
	{"f2","pw6"},
	{"g2","pw7"},
	{"h2","pw8"},
	{"a7","pb8"},
	{"b7","pb7"},
	{"c7","pb6"},
	{"d7","pb5"},
	{"e7","pb4"},
	{"f7","pb3"},
	{"g7","pb2"},
	{"h7","pb1"},
	{"a8","rbr"},
	{"b8","kbr"},
	{"c8","bbr"},
	{"d8","qb"},
	{"e8","kb"},
	{"f8","bbl"},
	{"g8","kbl"},
	{"h8","rbl"}
};