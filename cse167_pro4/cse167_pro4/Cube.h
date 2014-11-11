#ifndef _CUBE_H_
#define _CUBE_H_

#include "Geode.h"
#include "Vector3d.h"
#include "Const.h"


class Cube : Geode{

public:
	Cube(double s, Vector3d c, draw::mode);
private:
	void render();

	double size;
	Vector3d color;
	draw::mode mode;
};

#endif