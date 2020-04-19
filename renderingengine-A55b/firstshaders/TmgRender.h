#ifndef TmgRender_H
#define	TmgRender_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>
#include <Windows.h>
#include <string>

//#include "TmgShaders.h"

#include "TmgVertex.h"

using namespace glm;

class TmgRender
{
public:
	//TmgRender() {};
	~TmgRender() {};

	bool createVboFromArray(char* filename);
	void render();
	void SetShader(GLuint Shader);
	void SetworldToViewTransform(mat4 Transform);
	void SetObj(char* obj);
	void setRotatespeed(float rot);
	void setRotatation(vec3 rot);
	void setPos(vec3 pos);
	void setObjScale(vec3 pos);

private:
	unsigned int numVerts;
	char* ObjName;
	float Rotatespeed = 1.0f;
	vec3 RenderPos = vec3(0.0f, 0.0f, 0.0f);
	vec3 Rotation = vec3(0.0f, 1.0f, 0.0f);
	vec3 ObjScale = vec3(0.5f, 0.5f, 0.5f);
	GLuint gModelToWorldTransformLocation;
	GLuint gWorldToViewTransformLocation;
	GLuint gProjectionTransformLocation;
	mat4 worldToViewTransform;
	GLuint shaderProgram;
	GLuint vbo;
	// Materials uniform location
	GLuint gKaLoc;
	GLuint gKdLoc;

};

	
	


#endif