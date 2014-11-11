#include "Cube.h"

Cube::Cube(double s, Vector3d c, draw::mode m){
	size = s;
	color = c;
	mode = m;
}

void Cube::render(){
	glColor3d(color[0], color[1], color[2]);
	switch (mode){
	case draw::SOLID:
		glutSolidCube(size);
		break;
	case draw::WIRE:
		glutWireCube(size);
		break;
	}
}