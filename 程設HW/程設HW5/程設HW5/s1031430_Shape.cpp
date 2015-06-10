#include<iostream>
#include"s1031430_hw5_main.h"
#include "s1031430_Shape.h"

using namespace std;

namespace MIME{
	void Shape::print()
	{
		cout << "TYPE: " << ShapeName[CurrentType] << std::endl;
	}

	ShapeType Shape::getType()
	{
		return CurrentType;
	}

/*判断多边形凹凸可以用下面的方法：
对每个角都判断凹凸，设多边形是逆时针记录顶点的，三个连续的点P1(x1, y1), P2(x2, y2), P3(x3, y3)，
记S(P1, P2, P3) = (x1 - x3)*(y2 - y3) - (y1 - y3)*(x2 - x3)，
如果S(P1, P2, P3)<0，则角A2为凹角，
如果S(P1, P2, P3)>0，则角A2为凸角，
如果S(P1, P2, P3) = 0，P1P2P3三点共线。*/

	bool Shape::isConvex()
	{
		return (((vertices[0].x - vertices[2].x)*(vertices[1].y - vertices[2].y)) - ((vertices[0].y - vertices[2].y)*(vertices[1].x - vertices[2].x)));
	}

	Triangle::Triangle()
	{
		CurrentType = ShapeType::Triangle;
	}

	float Triangle::getArea()
	{
		float l1, l2, l3;
		float s;
		l1 = sqrt(((vertices[1].x - vertices[0].x)*(vertices[1].x - vertices[0].x)) + ((vertices[1].y - vertices[0].y)*(vertices[1].y - vertices[0].y)));
		l2 = sqrt(((vertices[1].x - vertices[2].x)*(vertices[1].x - vertices[2].x)) + ((vertices[2].y - vertices[1].y)*(vertices[2].y - vertices[1].y)));
		l3 = sqrt(((vertices[2].x - vertices[0].x)*(vertices[2].x - vertices[0].x)) + ((vertices[2].y - vertices[0].y)*(vertices[2].y - vertices[0].y)));
		s = (l1 + l2 + l3) / 2;
		return sqrt(s*(s - l1)*(s - l2)*(s - l3));
	}

	bool Triangle::isValid()
	{
		float l1, l2, l3;
		l1 = sqrt(((vertices[1].x - vertices[0].x)*(vertices[1].x - vertices[0].x)) + ((vertices[1].y - vertices[0].y)*(vertices[1].y - vertices[0].y)));
		l2 = sqrt(((vertices[1].x - vertices[2].x)*(vertices[1].x - vertices[2].x)) + ((vertices[2].y - vertices[1].y)*(vertices[2].y - vertices[1].y)));
		l3 = sqrt(((vertices[2].x - vertices[0].x)*(vertices[2].x - vertices[0].x)) + ((vertices[2].y - vertices[0].y)*(vertices[2].y - vertices[0].y)));
		if (l1 + l2 > l3 && l1 + l3 > l2 && l2 + l3 > l1)
			return true;
		else
			return false;
		if (l1-l2<l3 && l1-l3<l2 && l2-l3<l1)
			return true;
		else 
			return false;
	}

	Quadrilateral::Quadrilateral()
	{
		CurrentType = ShapeType::Quadrilateral;
	}

	float Quadrilateral::getArea()
	{
		float l1, l2, l3, l4, l5;
		float s1, s2;
		float A1, A2;
		l1 = sqrt(((vertices[1].x - vertices[0].x)*(vertices[1].x - vertices[0].x)) + ((vertices[1].y - vertices[0].y)*(vertices[1].y - vertices[0].y)));
		l2 = sqrt(((vertices[1].x - vertices[2].x)*(vertices[1].x - vertices[2].x)) + ((vertices[2].y - vertices[1].y)*(vertices[2].y - vertices[1].y)));
		l3 = sqrt(((vertices[2].x - vertices[0].x)*(vertices[2].x - vertices[0].x)) + ((vertices[2].y - vertices[0].y)*(vertices[2].y - vertices[0].y)));
		s1 = (l1 + l2 + l3) / 2;
		A1 = sqrt(s1*(s1 - l1)*(s1 - l2)*(s1 - l3));
		l4 = sqrt(((vertices[2].x - vertices[3].x)*(vertices[2].x - vertices[3].x)) + ((vertices[2].y - vertices[3].y)*(vertices[2].y - vertices[3].y)));
		l5 = sqrt(((vertices[0].x - vertices[3].x)*(vertices[0].x - vertices[3].x)) + ((vertices[0].y - vertices[3].y)*(vertices[0].y - vertices[3].y)));
		s2 = (l3 + l4 + l5) / 2;
		A2 = sqrt(s2*(s2 - l3)*(s2 - l4)*(s2 - l5));
		return A1 + A2;
	}

	bool Quadrilateral::isValid()
	{
		float m1, m2;
		m1 = (vertices[3].y - vertices[0].y) / (vertices[3].x - vertices[0].x);
		m2 = (vertices[2].y - vertices[0].y) / (vertices[2].x - vertices[0].x);
		if (m1 == m2)
			return false;
		else 
			return true;
	}

	Pentagon::Pentagon()
	{
		CurrentType = ShapeType::Pentagon;
	}

	float Pentagon::getArea()
	{
		float l1, l2, l3, l4, l5, l6, l7;
		float s1, s2, s3;
		float A1, A2, A3;
		l1 = sqrt(((vertices[1].x - vertices[0].x)*(vertices[1].x - vertices[0].x)) + ((vertices[1].y - vertices[0].y)*(vertices[1].y - vertices[0].y)));
		l2 = sqrt(((vertices[1].x - vertices[2].x)*(vertices[1].x - vertices[2].x)) + ((vertices[2].y - vertices[1].y)*(vertices[2].y - vertices[1].y)));
		l3 = sqrt(((vertices[2].x - vertices[0].x)*(vertices[2].x - vertices[0].x)) + ((vertices[2].y - vertices[0].y)*(vertices[2].y - vertices[0].y)));
		s1 = (l1 + l2 + l3) / 2;
		A1 = sqrt(s1*(s1 - l1)*(s1 - l2)*(s1 - l3));
		l4 = sqrt(((vertices[2].x - vertices[3].x)*(vertices[2].x - vertices[3].x)) + ((vertices[2].y - vertices[3].y)*(vertices[2].y - vertices[3].y)));
		l5 = sqrt(((vertices[0].x - vertices[3].x)*(vertices[0].x - vertices[3].x)) + ((vertices[0].y - vertices[3].y)*(vertices[0].y - vertices[3].y)));
		s2 = (l3 + l4 + l5) / 2;
		A2 = sqrt(s2*(s2 - l3)*(s2 - l4)*(s2 - l5));
		l6 = sqrt(((vertices[3].x - vertices[4].x)*(vertices[3].x - vertices[4].x)) + ((vertices[3].y - vertices[4].y)*(vertices[3].y - vertices[4].y)));
		l7 = sqrt(((vertices[4].x - vertices[0].x)*(vertices[4].x - vertices[0].x)) + ((vertices[4].y - vertices[0].y)*(vertices[4].y - vertices[0].y)));
		s3 = (l5 + l6 + l7) / 2;
		A3 = sqrt(s3*(s3 - l5)*(s3 - l6)*(s3 - l7));
		return A1 + A2 + A3;
	}

	bool Pentagon::isValid()
	{
		float m1, m2;
		m1 = (vertices[4].y - vertices[0].y) / (vertices[4].x - vertices[0].x);
		m2 = (vertices[3].y - vertices[0].y) / (vertices[3].x - vertices[0].x);
		if (m1 == m2)
			return false;
		else
			return true;
	}

	Parallelogram::Parallelogram()
	{
		CurrentType = ShapeType::Parallelogram;
	}

	float Parallelogram::getArea()
	{
		float l1, l2, l3, l4, l5;
		float s1, s2;
		float A1, A2;
		l1 = sqrt(((vertices[1].x - vertices[0].x)*(vertices[1].x - vertices[0].x)) + ((vertices[1].y - vertices[0].y)*(vertices[1].y - vertices[0].y)));
		l2 = sqrt(((vertices[1].x - vertices[2].x)*(vertices[1].x - vertices[2].x)) + ((vertices[2].y - vertices[1].y)*(vertices[2].y - vertices[1].y)));
		l3 = sqrt(((vertices[2].x - vertices[0].x)*(vertices[2].x - vertices[0].x)) + ((vertices[2].y - vertices[0].y)*(vertices[2].y - vertices[0].y)));
		s1 = (l1 + l2 + l3) / 2;
		A1 = sqrt(s1*(s1 - l1)*(s1 - l2)*(s1 - l3));
		l4 = sqrt(((vertices[2].x - vertices[3].x)*(vertices[2].x - vertices[3].x)) + ((vertices[2].y - vertices[3].y)*(vertices[2].y - vertices[3].y)));
		l5 = sqrt(((vertices[0].x - vertices[3].x)*(vertices[0].x - vertices[3].x)) + ((vertices[0].y - vertices[3].y)*(vertices[0].y - vertices[3].y)));
		s2 = (l3 + l4 + l5) / 2;
		A2 = sqrt(s2*(s2 - l3)*(s2 - l4)*(s2 - l5));
		return A1 + A2;
	}

	bool Parallelogram::isValid()
	{
		float m1, m2, m3, m4;
		m1 = (vertices[1].y - vertices[0].y) / (vertices[1].x - vertices[0].x);
		m2 = (vertices[2].y - vertices[1].y) / (vertices[2].x - vertices[1].x);
		m3 = (vertices[2].y - vertices[3].y) / (vertices[2].x - vertices[3].x);
		m4 = (vertices[3].y - vertices[0].y) / (vertices[3].x - vertices[0].x);
		if (m1 == m3 && m2 == m4)
			return true;
		else
			return false;
	}

	Square::Square()
	{
		CurrentType = ShapeType::Square;
	}

	float Square::getArea()
	{
		float l1, l2;
		l1 = sqrt(((vertices[1].x - vertices[0].x)*(vertices[1].x - vertices[0].x)) + ((vertices[1].y - vertices[0].y)*(vertices[1].y - vertices[0].y)));
		l2 = sqrt(((vertices[1].x - vertices[2].x)*(vertices[1].x - vertices[2].x)) + ((vertices[2].y - vertices[1].y)*(vertices[2].y - vertices[1].y)));
		return l1*l2;
	}

	bool Square::isValid()
	{
		float l1, l2, l3;
		l1 = sqrt(((B.x - A.x)*(B.x - A.x)) + ((B.y - A.y)*(B.y - A.y)));
		l2 = sqrt(((B.x - C.x)*(B.x - C.x)) + ((C.y - B.y)*(C.y - B.y)));
		l3 = sqrt(((C.x - A.x)*(C.x - A.x)) + ((C.y - A.y)*(C.y - A.y)));
		if ((l1*l1) + (l2*l2) == (l3*l3))
			return true;
		else
			return false;
	}

	Trapezium::Trapezium()
	{
		CurrentType = ShapeType::Trapezium;
	}

	float Trapezium::getArea()
	{
		float l1, l2, l3, l4, l5;
		float s1, s2;
		float A1, A2;
		l1 = sqrt(((vertices[1].x - vertices[0].x)*(vertices[1].x - vertices[0].x)) + ((vertices[1].y - vertices[0].y)*(vertices[1].y - vertices[0].y)));
		l2 = sqrt(((vertices[1].x - vertices[2].x)*(vertices[1].x - vertices[2].x)) + ((vertices[2].y - vertices[1].y)*(vertices[2].y - vertices[1].y)));
		l3 = sqrt(((vertices[2].x - vertices[0].x)*(vertices[2].x - vertices[0].x)) + ((vertices[2].y - vertices[0].y)*(vertices[2].y - vertices[0].y)));
		s1 = (l1 + l2 + l3) / 2;
		A1 = sqrt(s1*(s1 - l1)*(s1 - l2)*(s1 - l3));
		l4 = sqrt(((vertices[2].x - vertices[3].x)*(vertices[2].x - vertices[3].x)) + ((vertices[2].y - vertices[3].y)*(vertices[2].y - vertices[3].y)));
		l5 = sqrt(((vertices[0].x - vertices[3].x)*(vertices[0].x - vertices[3].x)) + ((vertices[0].y - vertices[3].y)*(vertices[0].y - vertices[3].y)));
		s2 = (l3 + l4 + l5) / 2;
		A2 = sqrt(s2*(s2 - l3)*(s2 - l4)*(s2 - l5));
		return A1 + A2;
	}

	bool Trapezium::isValid()
	{
		float m1, m2;
		m1 = (vertices[1].y - vertices[0].y) / (vertices[1].x - vertices[0].x);
		m2 = (vertices[2].y - vertices[3].y) / (vertices[2].x - vertices[3].x);
		if (m1 == m2)
			return true;
		else
			return false;
	}

	Isosceles_triangle::Isosceles_triangle()
	{
		CurrentType = ShapeType::Isosceles_triangle;
	}

	float Isosceles_triangle::getArea()
	{
		float l1, l2, l3, l4;
		l1 = sqrt(((vertices[1].x - vertices[0].x)*(vertices[1].x - vertices[0].x)) + ((vertices[1].y - vertices[0].y)*(vertices[1].y - vertices[0].y)));
		l2 = sqrt(((vertices[1].x - vertices[2].x)*(vertices[1].x - vertices[2].x)) + ((vertices[2].y - vertices[1].y)*(vertices[2].y - vertices[1].y)));
		l3 = sqrt(((vertices[2].x - vertices[0].x)*(vertices[2].x - vertices[0].x)) + ((vertices[2].y - vertices[0].y)*(vertices[2].y - vertices[0].y)));
		if (l1 == l2)
		{
			l4 = sqrt((l1*l1) - ((l3 / 2)*(l3 / 2)));
			return (l3*l4) / 2;
		}
		if (l2 == l3)
		{
			l4 = sqrt((l2*l2) - (l1 / 2)*(l1 / 2));
			return (l2*l4) / 2;
		}
		if (l1 == l3)
		{
			l4 = sqrt((l1*l1) - (l2 / 2)*(l2 / 2));
			return (l1*l4) / 2;
		}
	}

	bool Isosceles_triangle::isValid()
	{
		float l1, l2, l3;
		l1 = sqrt(((vertices[1].x - vertices[0].x)*(vertices[1].x - vertices[0].x)) + ((vertices[1].y - vertices[0].y)*(vertices[1].y - vertices[0].y)));
		l2 = sqrt(((vertices[1].x - vertices[2].x)*(vertices[1].x - vertices[2].x)) + ((vertices[2].y - vertices[1].y)*(vertices[2].y - vertices[1].y)));
		l3 = sqrt(((vertices[2].x - vertices[0].x)*(vertices[2].x - vertices[0].x)) + ((vertices[2].y - vertices[0].y)*(vertices[2].y - vertices[0].y)));
		if (l1 == l2)
		{
			return true;
		}
		if (l2 == l3)
		{
			return true;
		}
		if (l1 == l3)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	Regular_triangle::Regular_triangle()
	{
		CurrentType = ShapeType::Regular_triangle;
	}

	float Regular_triangle::getArea()
	{
		float l1, l2, l3;
		l1 = sqrt(((vertices[1].x - vertices[0].x)*(vertices[1].x - vertices[0].x)) + ((vertices[1].y - vertices[0].y)*(vertices[1].y - vertices[0].y)));
		l2 = sqrt(((vertices[1].x - vertices[2].x)*(vertices[1].x - vertices[2].x)) + ((vertices[2].y - vertices[1].y)*(vertices[2].y - vertices[1].y)));
		l3 = sqrt(((vertices[2].x - vertices[0].x)*(vertices[2].x - vertices[0].x)) + ((vertices[2].y - vertices[0].y)*(vertices[2].y - vertices[0].y)));
		return (1.73205080 / 4)*(l1*l1);
	}

	bool Regular_triangle::isValid()
	{
		float l1, l2, l3;
		l1 = sqrt(((vertices[1].x - vertices[0].x)*(vertices[1].x - vertices[0].x)) + ((vertices[1].y - vertices[0].y)*(vertices[1].y - vertices[0].y)));
		l2 = sqrt(((vertices[1].x - vertices[2].x)*(vertices[1].x - vertices[2].x)) + ((vertices[2].y - vertices[1].y)*(vertices[2].y - vertices[1].y)));
		l3 = sqrt(((vertices[2].x - vertices[0].x)*(vertices[2].x - vertices[0].x)) + ((vertices[2].y - vertices[0].y)*(vertices[2].y - vertices[0].y)));
		if (l1 == l2 && l2 == l3 && l1==l3)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	Right_triangle::Right_triangle()
	{
		CurrentType = ShapeType::Right_triangle;
	}

	float Right_triangle::getArea()
	{
		float l1, l2, l3;
		l1 = sqrt(((vertices[1].x - vertices[0].x)*(vertices[1].x - vertices[0].x)) + ((vertices[1].y - vertices[0].y)*(vertices[1].y - vertices[0].y)));
		l2 = sqrt(((vertices[1].x - vertices[2].x)*(vertices[1].x - vertices[2].x)) + ((vertices[2].y - vertices[1].y)*(vertices[2].y - vertices[1].y)));
		l3 = sqrt(((vertices[2].x - vertices[0].x)*(vertices[2].x - vertices[0].x)) + ((vertices[2].y - vertices[0].y)*(vertices[2].y - vertices[0].y)));
		if ((l1*l1) + (l2*l2) == (l3*l3))
		{
			return (l1*l2) / 2;
		}
		if ((l1*l1) + (l3*l3) == (l2*l2))
		{
			return (l1*l3) / 2;
		}
		if ((l2*l2) + (l3*l3) == (l1*l1))
		{
			return (l2*l3) / 2;
		}
	}

	bool Right_triangle::isValid()
	{
		float l1, l2, l3;
		l1 = sqrt(((vertices[1].x - vertices[0].x)*(vertices[1].x - vertices[0].x)) + ((vertices[1].y - vertices[0].y)*(vertices[1].y - vertices[0].y)));
		l2 = sqrt(((vertices[1].x - vertices[2].x)*(vertices[1].x - vertices[2].x)) + ((vertices[2].y - vertices[1].y)*(vertices[2].y - vertices[1].y)));
		l3 = sqrt(((vertices[2].x - vertices[0].x)*(vertices[2].x - vertices[0].x)) + ((vertices[2].y - vertices[0].y)*(vertices[2].y - vertices[0].y)));
		if ((l1*l1) + (l2*l2) == (l3*l3))
		{
			return true;
		}
		if ((l1*l1) + (l3*l3) == (l2*l2))
		{
			return true;
		}
		if ((l2*l2) + (l3*l3) == (l1*l1))
		{
			return true;
		}
		else
			return false;
	}
}