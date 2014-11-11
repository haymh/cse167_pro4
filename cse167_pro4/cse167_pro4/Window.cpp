#include <iostream>
#include "Window.h"
#include "Cube.h"
#include "Matrix4d.h"
#include "GL\glew.h"
#include "GL\glut.h"


using namespace std;

enum KEY{ F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12 };

int Window::width  = 512;   // set window width in pixels here
int Window::height = 512;   // set window height in pixels here
int Window::old_x = width / 2;
int Window::old_y = height / 2;


Camera cam1(Vector3d(0, 10, 10), Vector3d(0, 0, 0), Vector3d(0, 1, 0));
Camera cam2(Vector3d(-15, 5, 10), Vector3d(-5, 0, 0), Vector3d(0, 1, 0.5));


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
	glTranslatef(0, 0, -20);    // move camera back 20 units so that it looks at the origin (or else it's in the origin)
	glMatrixMode(GL_MODELVIEW);
}

//----------------------------------------------------------------------------
// Callback method called by GLUT when window readraw is necessary or when glutPostRedisplay() was called.
void Window::displayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // clear color and depth buffers
	glMatrixMode(GL_MODELVIEW);  // make sure we're in Modelview mode


	glFlush();
	glutSwapBuffers();
}
