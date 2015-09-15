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
	cout << "������� � ���������� ���-��� 1-��:" << endl;
	for (int i = 0; i < number; i++)
	{
		if (m[i].countones() == maxvalue)
			cout << "������� �"<< i+1 << endl;
	}
}

void inverssion(Matrix m[])
{
	int i;
	cout << "������� ����� ������:";
	cin >> i;
	if (m[i-1].inversion() == true)
		cout << "������� �"<< i << " �������������" <<endl;

}

void print(Matrix m[], int number)
{
	for (int i = 0; i < number; i++)
	{
		cout << "������� �" << i + 1 << endl;
		m[i].printmatrix();
	}
}

void changesize(Matrix m[])
{
	int h, v, i=0;
	cout << "������� ����� �������:";
	cin >> i;
	cout << "������� ������ �������:";
	cin >> h;
	cout << "������� ����� �������:";
	cin >> v;
	i--;
	m[i].sethsize(h);
	m[i].setvsize(v);
}

void sum(Matrix m[])
{
	int i, j;
	cout << "������� ������ ������:";
	cin >> i;
	cin >> j;
	i--;
	j--;
	if (m[i].addition(m[j]) == false)
		cout << "������� ������� ���������" << endl;
	else
		cout << "�������� �������� �������" << endl;
}

void multi(Matrix m[])
{
	int i, j;
	cout << "������� ������ ������:";
	cin >> i;
	cin >> j;
	i--;
	j--;
	if (m[i].multiplication(m[j])==false)
		cout << "����������� ������� ���������" << endl;
	else
		cout << "��������� �������� �������" << endl;

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
				cout << "������� " << k+1 << " � "<< j+1 <<" ����� ���������� ���������� ����� � ������ ������"<<endl;
			pointer = 0;
		}

	}
}

void lexicograph(Matrix m[])
{
	int num;
	cout << "������� ����� �������:";
	cin >> num;
	num--;
	if (m[num].lexicographical() == true)
		cout << "������ �"<< num+1 << " ����������" << endl;
}

int main()
{
	setlocale(LC_ALL, ".1251");
	int number, selection;
	cout << "������� ���������� ������:";
	cin >> number;
	Matrix *matrix  = new Matrix[number];
	Matrix *m[2] = { new Matrix(3, 3), new Matrix(3, 3) };
	while (true)
	{
		cout << "1-����� ������ �� �����" << endl;
		cout << "2-���������� ���������� �����" << endl;
		cout << "3-�������� �������" << endl;
		cout << "4-������� � ������������ ����������� 1-��" << endl;
		cout << "5-�������� ������� �������" << endl;
		cout << "6-������� 2-� �������" << endl;
		cout << "7-����������� 2-� �������" << endl;
		cout << "8-������������������ �������" << endl;
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