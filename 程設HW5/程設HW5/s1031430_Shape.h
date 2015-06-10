#pragma once
#include "hw5_main.h"

namespace MIME{
	class Vertex{
	public:
		Vertex() : x(0.0f), y(0.0f){}
		Vertex(const float inX, const float inY) : x(inX), y(inY){}
		void print(){ std::cout << "(" << x << "," << y << ")"; }

		float x, y;
	};

	class Shape{
	public:
		Shape() : CurrentType(ShapeType::Shape){}

		//add a Vertex
		size_t addVertex(const Vertex inV){ vertices.push_back(inV); return vertices.size(); }
		size_t addVertex(const float inX, const float inY){ vertices.push_back(Vertex(inX, inY)); return vertices.size(); }

		//??? void print();
		//??? ShapeType getType();
		//??? float getArea();
		//??? bool isValid();
		//??? bool isConvex();
	protected:
		ShapeType CurrentType;
		std::vector<Vertex> vertices;
	};

	class Triangle : public Shape{
	public:
		/* ... */
	};

}