// PivasKms.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

template <typename wtf>
class Graph
{
public:
	Graph(size_t am);
	~Graph();
	

private:
	const size_t size;
	wtf **matr;
};

template <typename wtf>
Graph<wtf>::Graph(size_t am) : size(am)
{
	this->matr = new wtf *[am];
	for (size_t i = 0; i < am; i++)
	{
		matr[i] = new wtf[am];
	}
}

template <typename wtf>
Graph<wtf>::~Graph()
{
	for (size_t i = 0; i < this->size; i++)
	{
		delete[] matr[i];
	}
	delete[] matr;
}


int main()
{
	Graph<int> Nuclear(2);
    return 0;
}

