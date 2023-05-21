#include <glm/glm.hpp>

class DrawPieces {
public:
	void drawPieces(glm::mat4 M);
	void movePieces();
};

extern DrawPieces *dp;