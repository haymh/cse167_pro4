#include "MatrixTransform.h"

MatrixTransform::MatrixTransform(Matrix4d m){
	matrix = m;
}

void MatrixTransform::setMatrix(Matrix4d m){
	matrix = m;
}

void MatrixTransform::draw(Matrix4d & m){
	Matrix4d mm = m * matrix;
	Group::draw(mm);
}