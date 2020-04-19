#include "aiterror.h"
#include "TmgCamera.h"

void TmgCamera::UpdateworldToViewTransform()
{
	worldToViewTransform = lookAt(
		position,
		viewDirection, 
		UP
	);
}

mat4 TmgCamera::GetworldToViewTransform()
{
	return mat4(worldToViewTransform);
}

void TmgCamera::moveUp()
{
	viewDirection += vec3(0.0f, MOVEMENT_SPEED , 0.0f);
	UpdateworldToViewTransform();

}

void TmgCamera::moveDown()
{
	viewDirection -= vec3(0.0f, MOVEMENT_SPEED, 0.0f);
	UpdateworldToViewTransform();
}

void TmgCamera::moveLeft()
{
	viewDirection += vec3(MOVEMENT_SPEED, 0.0f, 0.0f);
	UpdateworldToViewTransform();
}

void TmgCamera::moveRight()
{
	viewDirection -= vec3( MOVEMENT_SPEED, 0.0f, 0.0f);
	UpdateworldToViewTransform();
}

void TmgCamera::rotateRight()
{
	position -= vec3(MOVEMENT_SPEED, 0.0f,  0.0f);
	UpdateworldToViewTransform();
}

void TmgCamera::rotateLeft()
{
	position += vec3(MOVEMENT_SPEED, 0.0f, 0.0f);
	UpdateworldToViewTransform();
}

void TmgCamera::zoomIn()
{
	position -= vec3(0.0f, 0.0f, MOVEMENT_SPEED);
	UpdateworldToViewTransform();
}

void TmgCamera::zoomOut()
{
	position += vec3(0.0f, 0.0f, MOVEMENT_SPEED);
	UpdateworldToViewTransform();
}

void TmgCamera::keyPressEvent()
{
	//switch (e->key())
	//{
	//case Qt::Key::Key_W:
	//	camera.moveForward();
	//	break;
	//case Qt::Key::Key_S:
	//	camera.moveBackward();
	//	break;
	//case Qt::Key::Key_A:
	//	camera.strafeLeft();
	//	break;
	//case Qt::Key::Key_D:
	//	camera.strafeRight();
	//	break;
	//case Qt::Key::Key_R:
	//	camera.moveUp();
	//	break;
	//case Qt::Key::Key_F:
	//	camera.moveDown();
	//	break;
	//}
	//repaint();
}


