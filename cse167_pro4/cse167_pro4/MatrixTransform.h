#ifndef _MATRIXTRANSFORM_H_
#define _MATRIXTRANSFORM_H_

#include "Group.h"
#include "Matrix4d.h"

class MatrixTransform : Group{
public:
	MatrixTransform(Matrix4d m);
	void setMatrix(Matrix4d m);
	void draw(Matrix4d& m);
private:
	Matrix4d matrix;
};

#endif