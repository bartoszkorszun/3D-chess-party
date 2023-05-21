#include <glm/glm.hpp>
#include <string>

using namespace std;

class DrawPieces {
public:
	void drawPieces(glm::mat4 M);
	void movePieces();
	void readFile(string filename);
};

extern DrawPieces *dp;