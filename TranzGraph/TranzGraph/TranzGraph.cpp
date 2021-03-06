// TranzGraph.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <utility>
using namespace std;


int main()
{
	ofstream fout;
	ifstream fin;
	fin.open("in.txt");
	fout.open("out.txt", ios_base::trunc);
	int n, d;
	fin >> n >> d;
	vector<vector<short int>> graph(n);
	for (int i = 0; i < n; i++)	//чтение граФА
	{
		for (int j = 0; j < d; j++)
		{
			int u;
			fin >> u;
			graph[i].push_back(u);
		}
	}
	vector<pair<int, int>> svyz;	//список для проверки связей
	for (int i = 0; i < d; i++)
	{
		int start = -1, end = -1;
		for (int j = 0; j < n; j++)
		{
			if (graph[j][i] == 1) start = j;
			if (graph[j][i] == -1) end = j;
		}
		svyz.push_back(make_pair(start, end));
	}
	/*for (int i = 0; i < d; i++)
	{
		cout << svyz[i].first << " " << svyz[i].second<<endl;
	}*/
	for (int i = 0; i < d; i++)	//ребро i
	{
		for(int j = 0; j < d; j++)	//ребро j
		{
			if (i!=j && svyz[i].second == svyz[j].first)	//если дуга i инцидентна с той же вершиной, что и ребро j, то есть необхожимое условие тринзитивности
			{
				for (int z = 0; z < d; z++)	//ребро z
				{
					if (svyz[j].second == svyz[z].first && svyz[i].second != svyz[z].first)	//если если дуга i не инцидентна с той же вершиной, что и ребро z, то нет достаточного условия транзитивности, граф нетранзитивен
					{
						fout << "netranzitivniy graf";
						return 0;
					}
				}
			}
		}
	}
	fout << "tranzitivniy graf";	//если есть все условия, то граф транзитивен
	fin.close();
	fout.close();
	return 0;
}

