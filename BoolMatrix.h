#pragma once
#include <iostream>
#include <ctime>
class Matrix {
	int **storage;
	static const int maxsize=10;
public: 
		int hsize, vsize;
		Matrix();
		Matrix (int h, int v);
		Matrix(const Matrix &);
		~Matrix();
		void sethsize(int);
		void setvsize(int);
		void printmatrix();
		bool addition(const Matrix &);
		bool multiplication(const Matrix &);
		bool inversion();
		void randomfill();
		int countones();
		int  countzerous();
		int countstrzer(int );
		int gethsize();
		int getvsize();
		bool lexicographical();
};