#ifndef TmgCamera_H
#define	TmgCamera_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

class TmgCamera
{
private:
	mat4 worldToViewTransform;
	vec3 position = vec3(0.0f, 0.0f, 5.0f);
	vec3 viewDirection = vec3(0.0f, 0.0f, 0.0f);
	vec3 UP = vec3(0.0f, 1.0f, 0.0f); 
	float MOVEMENT_SPEED = 0.5f;
public:
	void UpdateworldToViewTransform();
	mat4 GetworldToViewTransform();
	void keyPressEvent();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void rotateRight();
	void rotateLeft();
	void zoomIn();
	void zoomOut();
};


#endif