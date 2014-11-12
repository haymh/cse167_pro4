#include "MatrixTransform.h"
#include "GL\glut.h"
#include "Debug.h"


MatrixTransform::MatrixTransform(Matrix4d m){
	matrix = m;
	center = new Vector4d();
	bottomOfSphere = new Vector4d();
}

void MatrixTransform::setMatrix(Matrix4d m){
	matrix = m;
}

Matrix4d MatrixTransform::getMatrix(){
	return matrix;
}

void MatrixTransform::draw(Matrix4d & m){
	Matrix4d mm = m * matrix;
	Group::draw(mm);
}

Bs MatrixTransform::update(){
	bs = (*(children.begin()))->update();
	for (list<Node*>::const_iterator it = children.begin(); it != children.end(); ++it){
		bs = bs.merge((*it)->update());
	}
	return bs;
}

double MatrixTransform::getRadius(){
	return radius;
}

Vector3d MatrixTransform::getCenter(){
	return center->getVector3d();
}

void MatrixTransform::setBS(Vector4d c, Vector4d p){
	(*center) = c;
	(*bottomOfSphere) = p;
}

void MatrixTransform::drawBS(){
	Vector3d c = (matrix * (*center)).getVector3d();
	Vector3d p = (matrix * (*bottomOfSphere)).getVector3d();
	Vector3d d = c - p;
	double r = d.magnitude();
	Matrix4d t;
	t.makeTranslate(d[0], d[1], d[2]);
	//c.print("center:");
	//p.print("bottom:");
	//d.print("displace: ");
	//Debug::debug("radius: ", r);

	glMatrixMode(GL_MODELVIEW);
	glColor3d(1, 0, 1);
	glLoadMatrixd((matrix * t).getPointer());
	glutWireSphere(r, 10, 10);
	//sphereMatrix.print("sphereMatrix:");
	//Debug::debug("radius", radius);
}