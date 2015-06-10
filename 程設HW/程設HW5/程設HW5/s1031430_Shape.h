#pragma once
#include "s1031430_hw5_main.h"
#include<vector> 

//isConvex == true ¬°¥Y ¡A else ¬°¥W

namespace MIME{
	class Vertex{
	public:
		Vertex() : x(0.0f), y(0.0f){}
		Vertex(const float inX, const float inY) : x(inX), y(inY){}
		void print(){ std::cout << "(" << x << "," << y << ")"; }
		
		float x, y;
	};

	class Shape :public Vertex
	{
	public:
		Shape() : CurrentType(ShapeType::Shape){}

		//add a Vertex
		size_t addVertex(const Vertex inV){ vertices.push_back(inV); return vertices.size(); }
		size_t addVertex(const float inX, const float inY){ vertices.push_back(Vertex(inX, inY)); return vertices.size(); }
		void print();
		virtual float getArea() = 0;
		virtual bool isValid() = 0;
		bool isConvex();
		Vertex A, B, C, D, E;
		ShapeType getType();
	protected:
		ShapeType CurrentType;
		std::vector<Vertex> vertices;
	};

	class Triangle : public Shape{
	public:
		Triangle();
		float getArea();
		bool isValid();
	};

	class Quadrilateral : public Shape
	{
	public:
		Quadrilateral();
		float getArea();
		bool isValid();
	};

	class Pentagon : public Shape
	{
	public:
		Pentagon();
		float getArea();
		bool isValid();
	};

	class Parallelogram : public Shape
	{
	public:
		Parallelogram();
		float getArea();
		bool isValid();
	};

	class Square : public Shape
	{
	public:
		Square();
		float getArea();
		bool isValid();
	};

	class Trapezium : public Shape
	{
	public:
		Trapezium();
		float getArea();
		bool isValid();
	};

	class Isosceles_triangle : public Shape
	{
	public:
		Isosceles_triangle();
		float getArea();
		bool isValid();
	};

	class Regular_triangle : public Shape
	{
	public:
		Regular_triangle();
		float getArea();
		bool isValid();
	};

	class Right_triangle : public Shape
	{
	public:
		Right_triangle();
		float getArea();
		bool isValid();
	};
}