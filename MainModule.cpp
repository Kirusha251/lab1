#include "BoolMatrix.h"
#include <iostream>
using namespace std;

int checkmax(Matrix m[],int number)
{
	int maxvalue = 0;
	for (int i = 0; i < number; i++)
	{
		if (m[i].countones() > maxvalue)
			maxvalue = m[i].countones();
	}
	
	return maxvalue;
}

void printMaxObjects(Matrix m[], int number)
{
	int maxvalue = 0;
	maxvalue = checkmax(m, number);
	cout << "Матрицы с наибольшим кол-вом 1-иц:" << endl;
	for (int i = 0; i < number; i++)
	{
		if (m[i].countones() == maxvalue)
			cout << "Матрица №"<< i+1 << endl;
	}
}

void inverssion(Matrix m[])
{
	int i;
	cout << "Введите номер матриц:";
	cin >> i;
	if (m[i-1].inversion() == true)
		cout << "Матрица №"<< i << " Инверсирована" <<endl;

}

void print(Matrix m[], int number)
{
	for (int i = 0; i < number; i++)
	{
		cout << "Матрица №" << i + 1 << endl;
		m[i].printmatrix();
	}
}

void changesize(Matrix m[])
{
	int h, v, i=0;
	cout << "Введите номер матрицы:";
	cin >> i;
	cout << "Введите высоту столбца:";
	cin >> h;
	cout << "Введите длину столбца:";
	cin >> v;
	i--;
	m[i].sethsize(h);
	m[i].setvsize(v);
}

void sum(Matrix m[])
{
	int i, j;
	cout << "Введите номера матриц:";
	cin >> i;
	cin >> j;
	i--;
	j--;
	if (m[i].addition(m[j]) == false)
		cout << "Сложить матрицы неудалось" << endl;
	else
		cout << "Сложение выполнно успешно" << endl;
}

void multi(Matrix m[])
{
	int i, j;
	cout << "Введите номера матриц:";
	cin >> i;
	cin >> j;
	i--;
	j--;
	if (m[i].multiplication(m[j])==false)
		cout << "Перемножить матрицы неудалось" << endl;
	else
		cout << "Умножение выполнно успешно" << endl;

}

void checkstr(Matrix m[],int number)
{
	int i, j=0, k,counter=0,pointer=0;
	for (k = 0; k < number; k++)
	{
		counter++;

		for (j=counter ; j < number; j++)
		{
			for (i = 0; i < m[j].gethsize(); i++)
			{
				if (m[k].countstrzer(i) == m[j].countstrzer(i))
					pointer++;
			}

			if (pointer == m[j].gethsize())
				cout << "Матрицы " << k+1 << " и "<< j+1 <<" имеют одинаковое количество нулей в каждой строке"<<endl;
			pointer = 0;
		}

	}
}

void lexicograph(Matrix m[])
{
	int num;
	cout << "Введите номер массива:";
	cin >> num;
	num--;
	if (m[num].lexicographical() == true)
		cout << "Массив №"<< num+1 << " Упорядочен" << endl;
}

int main()
{
	setlocale(LC_ALL, ".1251");
	int number, selection;
	cout << "Введите количество матриц:";
	cin >> number;
	Matrix *matrix  = new Matrix[number];
	Matrix *m[2] = { new Matrix(3, 3), new Matrix(3, 3) };
	while (true)
	{
		cout << "1-Вывод матриц на экран" << endl;
		cout << "2-Одинаковое количество нулей" << endl;
		cout << "3-Инверсия матрицы" << endl;
		cout << "4-Матрицы с макстмальным количеством 1-иц" << endl;
		cout << "5-Изменить размеры матрицы" << endl;
		cout << "6-Сложить 2-е матрицы" << endl;
		cout << "7-Перемножить 2-е матрицы" << endl;
		cout << "8-Лексикографический порядок" << endl;
		cin >> selection;
		switch (selection)
		{
		case 1:print(matrix, number); break;
		case 2:checkstr(matrix,number); break;
		case 3:inverssion(matrix); break;
		case 4:printMaxObjects(matrix, number); break;
		case 5:changesize(matrix); break;
		case 6:sum(matrix); break;
		case 7:multi(matrix); break;
		case 8:lexicograph(matrix); break;
		}

	}
	system("pause");
}