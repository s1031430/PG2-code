#include "hw5_main.h"
#include "Shape.h"

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

		//case Triangle:
		//	std::cout << "[LOADER] add: Triangle" << std::endl;
		//	data.push_back(new MIME::Triangle());
		//	/* ... */
		//	break;

		default:
			std::cout << "[LOADER] under construction: " << ShapeName[n] << std::endl;
			infile.getline(empty,255);	//eat line
			NUMofSHAPE++;
			//return NUMofSHAPE;
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
	//	var->print();
	//	std::cout << "AREA: " << var->getArea() << std::endl;
	//	std::cout << "Valid?: " << (var->isValid() ? "YES" : "NO") << std::endl;
	//	std::cout << "Convex?: " << (var->isConvex() ? "YES" : "NO") << std::endl << std::endl;
	
	//**SAMPLE**
	//TYPE: Isosceles_triangle
	//(-2, 0)
	//(0, 6)
	//(2, 0)
	//AREA: 12
	//Valid?: YES
	//Convex?: YES
	}

	for each (MIME::Shape* var in data)
		delete var;

	system("PAUSE");
	return 0;
}