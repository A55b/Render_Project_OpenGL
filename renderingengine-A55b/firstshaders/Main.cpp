#include <iostream>
#include <sstream>
#include <fstream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Windows.h>

#include "aiterror.h"
#include "TmgRender.h"
#include "TmgShaders.h"
#include "TmgMesh.h"
#include "TmgCamera.h"

using namespace std;
using namespace glm;

const int windowWidth = 1024;
const int windowHeight = 768;

TmgRender R;
TmgRender R2;
TmgShaders S;
TmgCamera C;

bool pause = true;
float speed;

using namespace glm;


void keyPressed(unsigned char key, int x, int y) {
	int i = 0;
	//movement of player 1 
	if (key == 'w') {
		C.moveUp();
		R.SetworldToViewTransform(C.GetworldToViewTransform());
		R2.SetworldToViewTransform(C.GetworldToViewTransform());
	}
	if (key == 's') {
		C.moveDown();
		R.SetworldToViewTransform(C.GetworldToViewTransform());
		R2.SetworldToViewTransform(C.GetworldToViewTransform());
	}
	if (key == 'a') {
		C.moveRight();
		R.SetworldToViewTransform(C.GetworldToViewTransform());
		R2.SetworldToViewTransform(C.GetworldToViewTransform());
	}
	if (key == 'd') {
		C.moveLeft();
		R.SetworldToViewTransform(C.GetworldToViewTransform());
		R2.SetworldToViewTransform(C.GetworldToViewTransform());
	}
	if (key == 'e') {
		C.zoomIn();
		R.SetworldToViewTransform(C.GetworldToViewTransform());
		R2.SetworldToViewTransform(C.GetworldToViewTransform());
	}
	if (key == 'q') {
		C.zoomOut();
		R.SetworldToViewTransform(C.GetworldToViewTransform());
		R2.SetworldToViewTransform(C.GetworldToViewTransform());
	}

	if (key == 'p') {
		if (pause == false) {
			speed = 1.0f;
			pause = true;
		}
		
		else if (pause == true) {
			speed = 0.0f;
			pause = false;
		}

		R.setRotatespeed(speed);
		R2.setRotatespeed(speed);
	}
}

static void renderSceneCallBack()
{
	// Clear the back buffer and the z-buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	R.render();
	R2.render();
	glutSwapBuffers();
	//cout <<"Render \n";
}

static void initializeGlutCallbacks()
{
    glutDisplayFunc(renderSceneCallBack);
	glutIdleFunc(renderSceneCallBack);
	glutKeyboardFunc(keyPressed);
	//cout << "Render2 \n";
}

static void createVertexBuffer()
{
	C.UpdateworldToViewTransform();
	R.SetworldToViewTransform(C.GetworldToViewTransform());
	R.SetShader(S.GetShader());
	R.createVboFromArray("assets/bunny.obj");
	R.setPos(vec3(1.0f, 0.0f, 0.0f));
	R.setRotatation(vec3 (1.0f, 0.0f, 0.0f));
	R.setObjScale(vec3(0.5f, 0.3f, 0.2f));

	R2.SetworldToViewTransform(C.GetworldToViewTransform());
	R2.SetShader(S.GetShader());
	R2.createVboFromArray("assets/monkey.obj");
	R2.setPos(vec3(-1.0f, 0.0f, 0.0f));
	R2.setRotatation(vec3(0.0f, 1.0f, 0.5f));

	glutSwapBuffers();

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    //glutInitWindowSize(1024, 768);
	glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("First Shaders");

    initializeGlutCallbacks();

    // Must be done after glut is initialized!
    GLenum res = glewInit();
    if (res != GLEW_OK) 
    {
		cerr<<"Error: "<<glewGetErrorString(res)<<"\n";
		return 1;
    }
	C.UpdateworldToViewTransform();
	S.setVertexShaderName("vertexShader.glsl");
	S.setFragmentShaderName("fragmentShader.glsl");
	S.CreateShaders();

	// Create a vertex buffer
	createVertexBuffer();
	
	// Enable the z-buffer
	glEnable(GL_DEPTH_TEST);
	// GL_LESS - Passes if the incoming depth value is less than the stored depth value
	glDepthFunc(GL_LESS);

    glutMainLoop();
    
    return 0;
}

















//
//
//#include <iostream>
//#include <sstream>
//#include <fstream>
//#include <GL/glew.h>
//#include <GL/freeglut.h>
//#include <glm/glm.hpp>
//#include <Windows.h>
//
//#include "aiterror.h"
//#include "TmgRender.h"
//
//using namespace std;
//using namespace glm;
//
//GLuint VBO;
//const int NUMVERTS = 3;
//TmgRender R;
//
//static void renderSceneCallBack()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glEnableVertexAttribArray(0);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
//
//	glDrawArrays(GL_TRIANGLES, 0, NUMVERTS);
//
//	glDisableVertexAttribArray(0);
//
//	glutSwapBuffers();
//
//	//R.render();
//}
//
//static void initializeGlutCallbacks()
//{
//	glutDisplayFunc(renderSceneCallBack);
//}
//
//static void createVertexBuffer()
//{
//	// Create some vertices to put in our VBO.
//	vec3 vertices[NUMVERTS];
//	vertices[0] = vec3(-0.5f, -0.5f, 0.0f);
//	vertices[1] = vec3(0.5f, -0.5f, 0.0f);
//	vertices[2] = vec3(0.0f, 0.5f, 0.0f);
//
//	//R.createVboFromArray(vertices, NUMVERTS);
//
//	glGenBuffers(1, &VBO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//}
//
///*
//static void addShader(GLuint shaderProgram, const char* pShaderText, GLenum shaderType)
//{
//	GLuint shaderObj = glCreateShader(shaderType);
//
//	if (shaderObj == 0)
//	{
//		std::stringstream ss;
//		ss<<"Error creating shader type "<<shaderType<<endl;
//		AIT_ASSERT(0, ss.str());
//	}
//
//	const GLchar* p[1];
//	p[0] = pShaderText;
//	GLint Lengths[1];
//	Lengths[0]= strlen(pShaderText);
//	glShaderSource(shaderObj, 1, p, Lengths);
//	glCompileShader(shaderObj);
//	GLint success;
//	glGetShaderiv(shaderObj, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		GLchar InfoLog[1024];
//		glGetShaderInfoLog(shaderObj, 1024, NULL, InfoLog);
//		std::stringstream ss;
//		ss <<"Error compiling shader type "<<shaderType<<": "<<InfoLog<<endl;
//		AIT_ASSERT(0, ss.str());
//	}
//
//	glAttachShader(shaderProgram, shaderObj);
//}
//
//const string readFileToString(char* filename)
//{
//	ifstream file(filename, ios::in);
//	if (file.is_open())
//	{
//		stringstream continut;
//		continut << file.rdbuf();
//		continut << '\0';
//		return continut.str();
//	}
//	return "";
//}
//
//static void buildShaders()
//{
//	GLuint shaderProgram = glCreateProgram();
//
//	if (shaderProgram == 0)
//	{
//		AIT_ASSERT(0, "Error creating shader program\n");
//	}
//
//	string VS = readFileToString("vertexShader.glsl");
//	string FS = readFileToString("fragmentShader.glsl");
//
//	addShader(shaderProgram, VS.c_str(), GL_VERTEX_SHADER);
//	addShader(shaderProgram, FS.c_str(), GL_FRAGMENT_SHADER);
//
//	GLint success = 0;
//	GLchar errorLog[1024] = { 0 };
//
//	glLinkProgram(shaderProgram);
//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//	if (success == 0)
//	{
//		glGetProgramInfoLog(shaderProgram, sizeof(errorLog), NULL, errorLog);
//		std::stringstream ss;
//		ss<<"Error linking shader program: "<<errorLog<<endl;
//		AIT_ASSERT(0, ss.str());
//	}
//
//	glValidateProgram(shaderProgram);
//	glGetProgramiv(shaderProgram, GL_VALIDATE_STATUS, &success);
//	if (!success)
//	{
//		glGetProgramInfoLog(shaderProgram, sizeof(errorLog), NULL, errorLog);
//		cerr<<"Error linking shader program: "<<errorLog<<endl;
//		std::stringstream ss;
//		ss<<"Error linking shader program: "<<errorLog<<endl;
//		AIT_ASSERT(0, ss.str());
//	}
//
//	glUseProgram(shaderProgram);
//}
//*/
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//	glutInitWindowSize(1024, 768);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("First Shaders");
//
//	initializeGlutCallbacks();
//
//	// Must be done after glut is initialized!
//	GLenum res = glewInit();
//	if (res != GLEW_OK)
//	{
//		cerr << "Error: " << glewGetErrorString(res) << "\n";
//		return 1;
//	}
//
//	//buildShaders();
//
//	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//
//	// Create a vertex buffer
//	createVertexBuffer();
//
//	glutMainLoop();
//
//	return 0;
//}