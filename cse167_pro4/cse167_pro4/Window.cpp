#include <iostream>
#include "Window.h"
#include "Cube.h"
#include "Matrix4d.h"
#include "GL\glew.h"
#include "GL\glut.h"


using namespace std;



int Window::width  = 512;   // set window width in pixels here
int Window::height = 512;   // set window height in pixels here
int Window::old_x = width / 2;
int Window::old_y = height / 2;

MatrixTransform* Window::root = new MatrixTransform(Matrix4d());
Robot Window::robot(1.5,1.5,1,2,2,1, 2.5);

Vector3d eye(0, 10, 20);
Vector3d lookat(0, 0, 0);
Vector3d up(0, 1, 0);
FrustumCulling Window::fc(60.0, double(width) / (double)height, 1.0, 1000.0, eye, lookat, up);
bool wire = false;


void Window::init(){
	Matrix4d t;
	t.makeTranslate(0, -0.5, 0);
	MatrixTransform* floor = new MatrixTransform(t);
	root->addChild(robot.getRoot());
	root->addChild(floor);
	for (int i = -15; i < 15; i++){
		for (int j = -15; j < 15; j++){
			t.makeTranslate(i, 0, j);
			MatrixTransform* tile = new MatrixTransform(t);
			floor->addChild(tile);
			tile->addChild(new Cube(0.7, Vector3d(0.5, 0.3, 0.6), draw::WIRE));
		}
	}
}

//----------------------------------------------------------------------------
// Callback method called when system is idle.
void Window::idleCallback()
{
	
	displayCallback();         // call display routine to show the cube
}

//----------------------------------------------------------------------------
// Callback method called by GLUT when graphics window is resized by the user
void Window::reshapeCallback(int w, int h)
{
	cerr << "Window::reshapeCallback called" << endl;
	width = w;
	height = h;
	glViewport(0, 0, w, h);  // set new viewport size
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, double(width) / (double)height, 1.0, 1000.0); // set perspective projection viewing frustum
	gluLookAt(eye[0], eye[1], eye[2], lookat[0], lookat[1], lookat[2], up[0], up[1], up[2]);
	//glTranslatef(0, 0, -20);    // move camera back 20 units so that it looks at the origin (or else it's in the origin)
}

//----------------------------------------------------------------------------
// Callback method called by GLUT when window readraw is necessary or when glutPostRedisplay() was called.
void Window::displayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // clear color and depth buffers

	glMatrixMode(GL_MODELVIEW);  // make sure we're in Modelview mode
	root->draw(Matrix4d());
	if (wire)
		robot.getRoot()->drawBS();
	//system("pause");
	glFlush();
	glutSwapBuffers(); 
}

void Window::addNode(Group *parent, Node * child){
	parent->addChild(child);
}

MatrixTransform* Window::getRoot(){
	return root;
}

void Window::keyboardProcess(unsigned char key, int x, int y){
	switch (key){
	case 'r':
		robot.rotate(5);
		break;
	case 't':
		robot.rotate(-5);
		break;
	case 'w':
		robot.walk();
		break;
	case 'b':
		wire = !wire;
		break;
	case 27:
		exit(0);
	}
}
void Window::processSpecialKeys(int k, int x, int y){

}
void Window::mouseMotionProcess(int, int){

}
void Window::mouseProcess(int, int, int, int){

}
