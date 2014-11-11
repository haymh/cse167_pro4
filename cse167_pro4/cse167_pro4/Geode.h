#ifndef _GEODE_H_
#define _GEODE_H_

#include "Node.h"
#include "GL\glut.h"

class Geode : Node{
public:
	void draw(Matrix4d & m){
		glMatrixMode(GL_MODELVIEW);
		glLoadMatrixd(m.getPointer());
		render();
	};
protected:
	virtual void render() = 0;

};


#endif