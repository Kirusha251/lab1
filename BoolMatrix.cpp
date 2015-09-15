#include "BoolMatrix.h"
#include <time.h>
#include <locale>
Matrix::Matrix()
{
	storage = new int *[maxsize];
	for (int i = 0; i < maxsize; i++)
		storage[i] = new int[maxsize];
		hsize = vsize = maxsize;
		this->randomfill();
}

Matrix::Matrix(int h, int v)
{
	std::cout << "Конструктор с параметрами\n";
	storage = new int *[maxsize];
	for (int i = 0; i < maxsize; i++)
		storage[i] = new int[maxsize];
	hsize = h;
	vsize = v;
	this->randomfill();
}

Matrix::Matrix(const Matrix& m)
{
	std::cout << "Конструктор копирования\n";
	storage = new int *[maxsize];
	for (int i = 0; i < maxsize; i++)
		storage[i] = new int[maxsize];
	hsize = m.hsize;
	vsize = m.vsize;
	for (int i = 0; i < maxsize; i++)
		for (int j = 0; j < maxsize; j++)
			storage[i][j] = m.storage[i][j];
}

Matrix::~Matrix()
{
	std::cout << "Вызов деструктора\n";
	for (int i = 0; i < maxsize; i++)
		delete[] storage[i];
	delete[] storage;
}

int Matrix::countones()
{
	int count = 0;
	for (int i = 0; i < hsize; i++)
	{
		for (int j = 0; j < vsize; j++)
		{
			if (storage[i][j] == 1)
				count++;
		}
	}

	return count;
}

bool Matrix::inversion()
{
	int** copy;
	copy = new int *[maxsize];
	for (int i = 0; i < maxsize; i++)
		copy[i] = new int[maxsize];
	for (int i = 0; i < maxsize; i++)
		for (int j = 0; j < maxsize; j++)
			copy[i][j] = storage[i][j];

		int t;
		t = hsize;
		hsize = vsize;
		vsize = t;

		for (int i = 0; i < vsize; i++)
		{
			for (int j = 0; j < hsize; j++)
				storage[j][i] = copy[i][j];
		}

		for (int i = 0; i < maxsize; i++)
		delete[] copy[i]; 
		delete[] copy;
		return true;
			
}

bool Matrix::multiplication(const Matrix& m)
{


	if (hsize != m.hsize || vsize != m.vsize)

		return false;

		for (int i = 0; i < hsize; i++)
		{
			for (int j = 0; j < vsize; j++)
			{

				if ((storage[i][j] * m.storage[i][j])> 0)
					storage[i][j] = 1;
				else
					storage[i][j] = 0;
			}
		}
		return true;

}
bool Matrix::addition(const Matrix & m)
{

	if (hsize == m.hsize && vsize == m.vsize)
	{

		for (int i = 0; i < hsize; i++)
		{
			for (int j = 0; j < vsize; j++)
			{

				if ((storage[i][j] + m.storage[i][j])> 0)
					storage[i][j] = 1;
				else
					storage[i][j] = 0;
			}
		}
		return true;
	}
	return false;
}

bool Matrix::lexicographical()
{
	for (int i = 0; i < hsize; i++)
	{
		for (int j = 0; j < vsize; j++)
		{
			for (int k = 0; k < hsize; k++)
			{
				if (storage[i][j] < storage[i][k])
					std::swap(storage[i][j], storage[i][k]);
			}
		}
	}
	return true;
}

int Matrix::countstrzer(int k)
{
	int i, j,count=0;
	for (i = 0; i <= k; i++)
	{
		for (j = 0; j < vsize; j++)
		{
			if (storage[i][j] == 0)
				count++;
		}
	}
	return count;
}

void Matrix::printmatrix()
{
	for (int i = 0; i < hsize; i++)
	{
		for (int j = 0; j < vsize; j++)
			std::cout << storage[i][j] << " ";
		std::cout<<std::endl;
	}
	std::cout << std::endl;
}

void Matrix::randomfill()
{
	srand(time(NULL));
	for (int i = 0; i<hsize; i++)
	for (int j = 0; j<vsize; j++)
	if (storage[i][j]<0)
		storage[i][j] = rand() % 2;
}

void Matrix::sethsize(int h)
{ 
	hsize = h;
	this->randomfill(); 

} 

void Matrix::setvsize(int v)
{ 
	vsize = v;
	this->randomfill();

}

int Matrix::gethsize()
{
	return this->hsize;
}


int Matrix::getvsize()
{
	return this->vsize;
}