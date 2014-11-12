#ifndef _GEODE_H_
#define _GEODE_H_

#include "Node.h"
#include "GL\glut.h"

class Geode : public Node{
public:
	Geode(){};
	void draw(Matrix4d & m){
		glMatrixMode(GL_MODELVIEW);
		glLoadMatrixd(m.getPointer());
		render();
	};
	virtual Bs update() = 0;
	void drawBS(){};
protected:
	virtual void render() = 0; 

};


#endif