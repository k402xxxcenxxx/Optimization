#pragma once
#include <iostream>
#include <vector>
#include "GL/glew.h"
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include "../glm/gtc/type_ptr.hpp"
#include "LoadShaders.h"

typedef struct a {
	int d;
}b,*c;
class ShaderManager
{
public:
	std::vector<glm::vec3> Points;
	std::vector<glm::vec3> PColors;
	std::vector<glm::vec3> Lines;
	std::vector<glm::vec3> LColors;

private:
	GLuint Program;
	GLuint VAO;
	GLuint pVBOs;
	GLuint pcVBOs;
	GLuint lVBOs;
	GLuint lcVBOs;
	GLuint gVBOs;
	GLuint gcVBOs;
	
	std::vector<glm::vec3> Grids;
	std::vector<glm::vec3> GColors;
public:
	ShaderManager();
	void Render(glm::mat4 projectionMatrix, glm::mat4 viewMatrix, glm::mat4 modelMatrix);
	
private:

};
