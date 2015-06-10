#include<iostream>
#include "s1031430_hw5_main.h"
#include "s1031430_Shape.h"

std::vector<MIME::Shape*> data;

int loadShapes(std::string file )
{
	std::ifstream infile(file, std::ifstream::in);
	if (!infile.good())
	{
		infile.close();
		std::cout << file << "*NOTE: file open fail!!";
		return -1;
	}
	int NUMofSHAPE = 0;
	char* empty = new char[255];
	for (int n; !infile.eof();)
	{
		infile >> n;
		float inX, inY;
		switch ((ShapeType)n)
		{
		case Shape :
			std::cout << "[LOADER] invalde abstract type: Shape" << std::endl;
			return NUMofSHAPE;

		case Triangle:
		std::cout << "[LOADER] add: Triangle" << std::endl;
		data.push_back(new MIME::Triangle());
		for (int i = 0; i < 3; i++)
		{
			infile >> inX >> inY;
			(data.back())->addVertex(inX, inY);
		}
		NUMofSHAPE++;
		break;

		case Quadrilateral:
			std::cout << "[LOADER] add: Quadrilateral" << std::endl;
			data.push_back(new MIME::Quadrilateral());
			for (int i = 0; i < 4; i++)
			{
				infile >> inX >> inY;
				(data.back())->addVertex(inX, inY);
			}
			NUMofSHAPE++;
			break;

		case Pentagon:
			std::cout << "[LOADER] add: Pentagon" << std::endl;
			data.push_back(new MIME::Pentagon());
			for (int i = 0; i < 5; i++)
			{
				infile >> inX >> inY;
				(data.back())->addVertex(inX, inY);
			}
			NUMofSHAPE++;
			break;

		case Parallelogram:
			std::cout << "[LOADER] add: Parallelogram" << std::endl;
			data.push_back(new MIME::Parallelogram());
			for (int i = 0; i < 4; i++)
			{
				infile >> inX >> inY;
				(data.back())->addVertex(inX, inY);
			}
			NUMofSHAPE++;
			break;

		case Square:
			std::cout << "[LOADER] add: Square" << std::endl;
			data.push_back(new MIME::Square());
			for (int i = 0; i < 4; i++)
			{
				infile >> inX >> inY;
				(data.back())->addVertex(inX, inY);
			}
			NUMofSHAPE++;
			break;

		case Trapezium:
			std::cout << "[LOADER] add: Trapezium" << std::endl;
			data.push_back(new MIME::Trapezium());
			for (int i = 0; i < 4; i++)
			{
				infile >> inX >> inY;
				(data.back())->addVertex(inX, inY);
			}
			NUMofSHAPE++;
			break;

		case Isosceles_triangle:
			std::cout << "[LOADER] add: Isosceles_triangle" << std::endl;
			data.push_back(new MIME::Isosceles_triangle());
			for (int i = 0; i < 3; i++)
			{
				infile >> inX >> inY;
				(data.back())->addVertex(inX, inY);
			}
			NUMofSHAPE++;
			break;

		case Regular_triangle:
			std::cout << "[LOADER] add: Regular_triangle" << std::endl;
			data.push_back(new MIME::Regular_triangle());
			for (int i = 0; i < 3; i++)
			{
				infile >> inX >> inY;
				(data.back())->addVertex(inX, inY);
			}
			NUMofSHAPE++;
			break;

		case Right_triangle:
			std::cout << "[LOADER] add: Right_triangle" << std::endl;
			data.push_back(new MIME::Right_triangle());
			for (int i = 0; i < 3; i++)
			{
				infile >> inX >> inY;
				(data.back())->addVertex(inX, inY);
			}
			NUMofSHAPE++;
			break;

		default:
			std::cout << "[LOADER] under construction: " << ShapeName[n] << std::endl;
			infile.getline(empty,255);	//eat line
			NUMofSHAPE++;
			return NUMofSHAPE;
		}
	}

	delete empty;
	infile.close();

	return NUMofSHAPE;
}

int main()
{
	int NUMofSHAPE = loadShapes("test_shape.txt");
	std::cout << "# of shapes = " << NUMofSHAPE << std::endl;

	//print out each sahpe
	for each (MIME::Shape* var in data)
	{
		var->print();
		std::cout << "AREA: " << var->getArea() << std::endl;
		std::cout << "Valid?: " << (var->isValid() ? "YES" : "NO") << std::endl;
		std::cout << "Convex?: " << (var->isConvex() ? "YES" : "NO") << std::endl << std::endl;
	}

	for each (MIME::Shape* var in data)
		delete var;

	system("PAUSE");
	return 0;
}