#include "ShaderManager.h"

ShaderManager::ShaderManager()
{
	ShaderInfo shaders[] =
	{
		{ GL_VERTEX_SHADER,		"./Shader/Base.vert" },
		{ GL_FRAGMENT_SHADER,	"./Shader/Base.frag" },
		{ GL_NONE, NULL }
	};
	Program = LoadShaders(shaders);

	//VAO
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	//VBO
	glGenBuffers(1, &pVBOs);
	glBindBuffer(GL_ARRAY_BUFFER, pVBOs);
	//glBufferData(GL_ARRAY_BUFFER, Points.size()*sizeof(glm::vec3), &Points[0], GL_DYNAMIC_DRAW);

	glGenBuffers(1, &pcVBOs);
	glBindBuffer(GL_ARRAY_BUFFER, pcVBOs);
	//glBufferData(GL_ARRAY_BUFFER, PColors.size()*sizeof(glm::vec3), &PColors[0], GL_DYNAMIC_DRAW);

	glGenBuffers(1, &lVBOs);
	glBindBuffer(GL_ARRAY_BUFFER, lVBOs);
	//glBufferData(GL_ARRAY_BUFFER, Lines.size()*sizeof(glm::vec3), &Lines[0], GL_DYNAMIC_DRAW);

	glGenBuffers(1, &lcVBOs);
	glBindBuffer(GL_ARRAY_BUFFER, lcVBOs);
	//glBufferData(GL_ARRAY_BUFFER, LColors.size()*sizeof(glm::vec3), &LColors[0], GL_DYNAMIC_DRAW);

	glGenBuffers(1, &gVBOs);
	glBindBuffer(GL_ARRAY_BUFFER, gVBOs);
	//glBufferData(GL_ARRAY_BUFFER, Grids.size()*sizeof(glm::vec3), &Grids[0], GL_DYNAMIC_DRAW);

	glGenBuffers(1, &gcVBOs);
	glBindBuffer(GL_ARRAY_BUFFER, gcVBOs);
	//glBufferData(GL_ARRAY_BUFFER, GColors.size()*sizeof(glm::vec3), &GColors[0], GL_DYNAMIC_DRAW);


	// Set up Grid
	const int hw = 5000;
	const int step = 50;
	glm::vec3 gridColor = glm::vec3(0.2, 0.2, 0.2);
	for (int i = -hw; i <= hw; i += step) 
	{
		Grids.push_back(glm::vec3(i, 0, -hw));
		Grids.push_back(glm::vec3(i, 0, hw));
		Grids.push_back(glm::vec3(-hw, 0, i));
		Grids.push_back(glm::vec3(hw, 0, i));

		GColors.push_back(gridColor);
		GColors.push_back(gridColor);
		GColors.push_back(gridColor);
		GColors.push_back(gridColor);
	}
	Grids.push_back(glm::vec3(0, 0, 0));
	Grids.push_back(glm::vec3(0, 1000, 0));
	GColors.push_back(glm::vec3(0.4, 0.4, 0.4));
	GColors.push_back(glm::vec3(0.4, 0.4, 0.4));
}

void ShaderManager::Render(glm::mat4 projectionMatrix, glm::mat4 viewMatrix, glm::mat4 modelMatrix)
{

	for (int i = 0; i < 3; i++)
	{
		glUseProgram(Program);
		glBindVertexArray(VAO);

		glUniformMatrix4fv(glGetUniformLocation(Program, "ModelMatrix"), 1, GL_FALSE, &modelMatrix[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(Program, "ViewMatrix"), 1, GL_FALSE, &viewMatrix[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(Program, "ProjectionMatrix"), 1, GL_FALSE, &projectionMatrix[0][0]);
		switch(i)
		{
			case 0:
				glBindBuffer(GL_ARRAY_BUFFER, pVBOs);
				glBufferData(GL_ARRAY_BUFFER, Points.size()*sizeof(glm::vec3), &Points[0], GL_DYNAMIC_DRAW);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
				glEnableVertexAttribArray(0);

				glBindBuffer(GL_ARRAY_BUFFER, pcVBOs);
				glBufferData(GL_ARRAY_BUFFER, PColors.size()*sizeof(glm::vec3), &PColors[0], GL_DYNAMIC_DRAW);
				glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
				glEnableVertexAttribArray(1);

				glDrawArrays(GL_POINTS, 0, Points.size());
			break;
			case 1:
				glBindBuffer(GL_ARRAY_BUFFER, lVBOs);
				glBufferData(GL_ARRAY_BUFFER, Lines.size()*sizeof(glm::vec3), &Lines[0], GL_DYNAMIC_DRAW);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
				glEnableVertexAttribArray(0);

				glBindBuffer(GL_ARRAY_BUFFER, lcVBOs);
				glBufferData(GL_ARRAY_BUFFER, LColors.size()*sizeof(glm::vec3), &LColors[0], GL_DYNAMIC_DRAW);
				glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
				glEnableVertexAttribArray(1);

				glDrawArrays(GL_LINES, 0, Lines.size());
			break;
			case 2:
				glBindBuffer(GL_ARRAY_BUFFER, gVBOs);
				glBufferData(GL_ARRAY_BUFFER, Grids.size()*sizeof(glm::vec3), &Grids[0], GL_DYNAMIC_DRAW);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
				glEnableVertexAttribArray(0);

				glBindBuffer(GL_ARRAY_BUFFER, gcVBOs);
				glBufferData(GL_ARRAY_BUFFER, GColors.size()*sizeof(glm::vec3), &GColors[0], GL_DYNAMIC_DRAW);
				glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
				glEnableVertexAttribArray(1);

				glDrawArrays(GL_LINES, 0, Grids.size());
			break;
		}
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glUseProgram(0);
	}
	
}
