#include <GL/glew.h>
#include <lodepng.h>

class ReadTextures {
public:
	GLuint readTexture(const char* filename);
};

extern ReadTextures* rt;