#include "Group.h"

using namespace std;

Group::~Group(){
	for (std::list<Node *>::iterator it = children.begin(); it != children.end(); ++it)
		delete *it;
}

void Group::addChild(Node * n){
	children.push_back(n);
}

void Group::removeChild(Node * n){
	children.remove(n);
}

void Group::draw(Matrix4d & m){
	for (std::list<Node *>::iterator it = children.begin(); it != children.end(); ++it)
		(*it)->draw(m);
}