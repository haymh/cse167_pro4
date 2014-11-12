#ifndef _NODE_H_
#define _NODE_H_

#include "Matrix4d.h"

struct Bs{
	Vector3d center;
	double radius;
	Bs(){};
	Bs(Vector3d c, double r){
		center = c;
		radius = r;
	}
	Bs merge(Bs & other){
		double d = (center - other.center).magnitude();
		double diff = abs(radius - other.radius);
		if (d > diff){			// intersects
			return Bs((center + other.center).scale(0.5), (d + radius + other.radius) / 2);
		}
		else{
			return radius > other.radius ? Bs(center, radius) : other;
		}
	}
};

class Node{
public :
	Node() {};
	virtual void draw(Matrix4d &) = 0; 
	virtual Bs update() = 0;
	virtual void drawBS() = 0;

protected:
	Bs bs;
};


#endif