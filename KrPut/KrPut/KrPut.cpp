// KrPut.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include<fstream>
using namespace std;


int main()
{
	ofstream fout;
	ifstream fin;
	fin.open("01");
	fout.open("path.out", ios_base::trunc);
	int n, m;
	fin >> n >> m;
    return 0;
}

