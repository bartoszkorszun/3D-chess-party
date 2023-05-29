#include <glm/glm.hpp>

class DrawBoard {
public:
	void drawBoard(glm::mat4 M);
	void initTextures();
};

extern DrawBoard* db;