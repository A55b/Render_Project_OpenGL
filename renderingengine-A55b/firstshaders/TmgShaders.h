#ifndef TmgShaders_H
#define	TmgShaders_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <Windows.h>
using namespace glm;
using namespace std;

class TmgShaders
{
public:

	void CreateShaders();
	string readFileToString(char* filename);
	void addShader(GLuint shaderProgram, const char* pShaderText, GLenum shaderType);
	GLuint GetShader();
	void setVertexShaderName(char* name);
	void setFragmentShaderName(char* name);


private:
	GLuint shaderProgram;
	float size;
	char* VertexShaderName ="vertexShader.glsl";
	char* FragmentShaderName ="fragmentShader.glsl";
	
};


#endif