#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>
#include <Windows.h>

#include "aiterror.h"
#include "TmgRender.h"
#include "TmgMesh.h"

using namespace std;
using namespace glm;

bool TmgRender::createVboFromArray(char* filename)
{

	TmgMesh mesh1;
	//if (!mesh1.loadFromObj("assets/bunny.obj"))
	if (!mesh1.loadFromObj(filename))
	{
		cerr << "Error loading mesh from obj file." << endl;
		system("pause");
		exit(0);
	}
	vector<TmgVertex> verts;
	verts = mesh1.getVertices();
	numVerts = verts.size();

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(TmgVertex) * numVerts, &verts[0], GL_STATIC_DRAW);

	gModelToWorldTransformLocation = glGetUniformLocation(shaderProgram, "gModelToWorldTransform");
	assert(gModelToWorldTransformLocation != 0xFFFFFFFF);
	gWorldToViewTransformLocation = glGetUniformLocation(shaderProgram, "gWorldToViewTransform");
	assert(gWorldToViewTransformLocation != 0xFFFFFFFF);
	gProjectionTransformLocation = glGetUniformLocation(shaderProgram, "gProjectionTransform");
	assert(gProjectionTransformLocation != 0xFFFFFFFF);
	
	return true;
}

void TmgRender::render() {

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(TmgVertex), 0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(TmgVertex), (const GLvoid*)12);

	// Create out projection transform
	mat4 projectionTransform = perspective(45.0f, (float)1024 / (float)768, 1.0f, 100.0f);

	// Update the transforms in the shader program on the GPU
	glUniformMatrix4fv(gWorldToViewTransformLocation, 1, GL_FALSE, &worldToViewTransform[0][0]);
	glUniformMatrix4fv(gProjectionTransformLocation, 1, GL_FALSE, &projectionTransform[0][0]);

	// Create a new model to world transform
	mat4 scalem = mat4(1.0f);
	scalem = scale(scalem, ObjScale);

	static float angle = 0.0f;
	angle += Rotatespeed;
	mat4 rot = mat4(1.0f);
	rot = rotate(rot, angle, Rotation);

	mat4 trans = mat4(1.0f);
	trans = translate(trans, RenderPos);
	//mat4 modelToWorldTransform = rot * scalem;
	mat4 modelToWorldTransform = trans * rot * scalem;

	glUniformMatrix4fv(gModelToWorldTransformLocation, 1, GL_FALSE, &modelToWorldTransform[0][0]);
	glDrawArrays(GL_TRIANGLES, 0, numVerts);
	
	// Draw triangle two behind triangle one
	// Create model space to world space transformation matrix
	//modelToWorldTransform = mat4(1.0f);
	
	//trans = translate(trans, vec3(-2.0f, 0.0f, 0.0f));
	//modelToWorldTransform = trans * rot * scalem;
	//glUniformMatrix4fv(gModelToWorldTransformLocation, 1, GL_FALSE, &modelToWorldTransform[0][0]);
	//glDrawArrays(GL_TRIANGLES, 0, numVerts);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

void TmgRender::setPos(vec3 pos) 
{
	RenderPos =	pos;
}

void TmgRender::setObjScale(vec3 scale)
{
	ObjScale = scale;
}

void TmgRender::SetShader(GLuint Shader)
{
	shaderProgram = Shader;
}

void TmgRender::SetworldToViewTransform(mat4 Transform)
{
	worldToViewTransform = Transform;
}

void TmgRender::SetObj(char* obj)
{
	ObjName = obj;
}

void TmgRender::setRotatespeed(float rot)
{
	Rotatespeed = rot;
}

void TmgRender::setRotatation(vec3 rot)
{
	Rotation = rot;
}
