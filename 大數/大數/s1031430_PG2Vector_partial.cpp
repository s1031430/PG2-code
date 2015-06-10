// Member-function definitions for class Vector.
#include "s1031430_PG2Vector.h" // include definition of class Vector 

Vector::Vector( size_t n, const int val )
{
   if( n > 10 )
   {
      ptr = new int[ n ];
      // initialize array to val
      for( unsigned int i = 0; i < n; i++ )
         ptr[ i ] = val;

      size = n;
      capacity = n;
   }
   else if( n > 0 ) // n <= 10
   {
      ptr = new int[ 10 ];
      // initialize array to val
      for( unsigned int i = 0; i < n; i++ )
         ptr[ i ] = val;

      size = n;
      capacity = 10;
   }
   else
   {
      size = 0;
      capacity = 0;
	  ptr = new int[0];
   }
}

Vector::Vector(int *first, int *last)
{
	size = last - first;
	ptr = new int[size];
	for (int i = 0; i<size; i++)
	{
		ptr[i] = *(first + i);
	}
}

Vector::Vector(const Vector &copy)
{
	size = copy.size;
	ptr = new int[size];
	for (int i = 0; i<size; i++)
	{
		ptr[i] = copy.ptr[i];
	}
}

ostream &operator<<(ostream &output, const Vector &vec)	
{
	for (int i = 0; i < vec.size; i++)
	{
		output << vec.ptr[i]<<" ";
	}
	output << endl;
	return output;
}
//* destructor
Vector::~Vector()
{
	delete[] ptr;
}

const Vector &Vector::operator=(const Vector &right)
{
	this->size = right.size;
	this->capacity = right.capacity;
	this->ptr = right.ptr;
	return *this;
}

bool Vector::operator==(const Vector &right) const
{
	return (*this == right);
}

// inequality operator; returns opposite of == operator
bool Vector::operator!=( const Vector &right ) const  
{ 
   return !( *this == right ); // invokes Vector::operator==
}

int &Vector::operator[](size_t i)
{
	return ptr[i];
}

int Vector::operator[](size_t i) const
{
	return ptr[i];
}

int* Vector::begin()
{
   return ptr;
}

int* Vector::end()
{
   return ptr + size;
}

int& Vector::front()
{
   return ptr[0];
}

int& Vector::back()
{
   return ptr[ size - 1 ];
}

void Vector::pop_back()
{
   size--;
}

size_t Vector::getSize() const
{
   return size;
}

size_t Vector::getCapacity() const
{
   return capacity;
}

bool Vector::empty() const
{
   return ( size == 0 );
}

void Vector::clear()
{
   size = 0;
}

void Vector::resize(size_t n, const int val)
{
	if (n>size)
	{
		int ptr1[50];
		for (int k = 0; k<size; k++)
			ptr1[k] = ptr[k];
		delete[] ptr;
		ptr = new int[50];
		for (int k = 0; k<size; k++)
			ptr[k] = ptr1[k];
		for (int i = size; i < n; i++)
			ptr[i] = val;
	}
	size = n;
}

void Vector::shrink_to_fit()
{
	capacity = size;
}

void Vector::assign(int n, const int val)
{
	int ptr1[50];
	for (int k = 0; k<size; k++)
		ptr1[k] = ptr[k];
	delete[] ptr;
	ptr = new int[50];
	for (int k = 0; k<size; k++)
		ptr[k] = ptr1[k];
	size = n;
	for (int i = 0; i<size; i++)
	{
		ptr[i] = val;
	}
}

void Vector::assign(int *first, int *last)
{

	size = last - first;

	ptr = new int[size];
	for (int i = 0; i<size; i++)
	{
		ptr[i] = *(first + i);

	}
	capacity = size + 1;
}

int *Vector::insert(int *position, int *first, int *last)
{
	int m;
	for (m = size - 1; m>0; m--)
	{
		if (position == ptr + m)
			break;
	}
	int n = last - first;

	int ptr1[50];
	for (int k = 0; k<size; k++)
		ptr1[k] = ptr[k];
	delete[] ptr;
	ptr = new int[50];
	for (int k = 0; k<size; k++)
		ptr[k] = ptr1[k];
	m += n;
	size += n;
	for (int i = size - 1; i>0; i--)
	{
		ptr[i] = ptr[i - n];
		if (m == i)
		{
			for (int k = i - 1, j = 0; k>i - n - 1; k--, j++)
			{
				ptr[k] = *(first);
			}
			break;
		}
	}
	return ptr;
}

int *Vector::erase(int *first, int *last)
{
	int n = last - first;
	int k;
	for (k = 0; k<size; k++)
	{
		if (ptr[k] == *first)
			break;
	}
	for (int i = k; i<size - n; i++)
	{
		ptr[i] = ptr[i + n];
	}
	size -= n;
	return ptr;
}

void Vector::swap(Vector &x)
{
	int temp[40];
	int tsize;
	tsize = x.size;
	x.size = size;
	size = tsize;

	int ptr1[50];
	for (int k = 0; k<size; k++)
		ptr1[k] = x.ptr[k];
	delete[] x.ptr;
	x.ptr = new int[50];
	for (int k = 0; k<size; k++)
		x.ptr[k] = ptr1[k];


	for (int i = 0; i<size; i++)
	{
		temp[i] = x.ptr[i];
	}
	for (int i = 0; i<x.size; i++)
	{
		x.ptr[i] = ptr[i];
	}
	delete[] ptr;
	ptr = new int[size];
	for (int i = 0; i<size; i++)
	{
		ptr[i] = temp[i];
	}

}

void Vector::push_back(const int val)
{
	int *pointer;
	pointer = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		pointer[i] = ptr[i];
	}
	pointer[size] = val;
	size++;
	delete[] ptr;
	ptr = pointer;
}

void Vector::reserve(size_t n)
{
	int *pointer;
	pointer = new int[n];
	for (int i = 0; i < size; i++)
	{
		pointer[i] = ptr[i];
	}
	delete[] ptr;
	ptr = pointer;
	capacity = n;
}