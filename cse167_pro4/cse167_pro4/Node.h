#ifndef _NODE_H_
#define _NODE_H_

#include "Matrix4d.h"

class Node{
public :
	virtual void draw(Matrix4d &) = 0;
};


#endif