#ifndef _GROUP_H_
#define _GROUP_H_

#include "Node.h"
#include <list>


class Group : public Node{
public :
	Group(){};
	~Group();
	virtual void draw(Matrix4d &);
	virtual Bs update() = 0;
	virtual void drawBS() = 0;
	void addChild(Node *);
	void removeChild(Node *);

protected :
	std::list<Node*> children;
}; 

#endif