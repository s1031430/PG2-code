#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

static enum ShapeType{
	Shape = 0, Triangle, Quadrilateral, Pentagon, Parallelogram, Square,
	Trapezium, Isosceles_triangle, Regular_triangle, Right_triangle, Polygon
};

static char *ShapeName[] = {
	"Shape", "Triangle", "Quadrilateral", "Pentagon", "Parallelogram", "Square",
	"Trapezium", "Isosceles_triangle", "Regular_triangle", "Right_triangle", "Polygon"
};