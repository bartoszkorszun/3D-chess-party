#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <shaderprogram.h>
#include <allmodels.h>
#include <initpositions.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <thread>
#include <drawpieces.h>
#include <readtextures.h>

using namespace std;

GLuint texLight;
GLuint texDark;
GLuint texSurfacePieces;

string moves[107][2];

int nextMove = 0;

bool castle = false;
bool isOnTop = false;
bool isKingOnTop = false;
bool isRookOnTop = false;

float fNextPosition[2];

const float movementSpeed = 0.05f;