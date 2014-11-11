#ifndef _GROUP_H_
#define _GROUP_H_

#include "Node.h"
#include <list>

class Group : Node{
public :
	~Group();
	virtual void draw(Matrix4d &);
	void addChild(Node *);
	void removeChild(Node *);

protected :
	std::list<Node*> children;
};

#endif