#include <GL/glew.h>
#include <string>

using namespace std;

class DrawPieces {
public:
	void drawPieces(glm::mat4 M);
	void movePieces();
	void readFile(string filename);
	void initTextures();
};

extern DrawPieces *dp;