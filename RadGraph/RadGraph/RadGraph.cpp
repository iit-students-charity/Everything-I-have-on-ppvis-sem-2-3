// TranzGraph.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;


int main()
{
	ofstream fout;
	ifstream fin;
	fin.open("in.txt");
	fout.open("out.txt", ios_base::trunc);
	int n, r;
	fin >> n >> r;	//n- количество вершин, r - количество ребер
	vector<vector<short int>> graph(n);	//сюда записываем матрицу инцидентности
	for (int i = 0; i < n; i++)	//чтение графа
	{
		for (int j = 0; j < r; j++)
		{
			int u;
			fin >> u;
			graph[i].push_back(u);
		}
	}
	vector<int> e;	//тут будем хранить эксцентриситеты для каждой вершины
	for (int i = 0; i < n-1; i++)	//обход в глубину для каждой вершины
	{
		int s = i;	//выбираем вершину
		queue<int> q;	//очередь вершин для bfs
		q.push(s);	//первая вершина в очереди и used
		vector<bool> used(n);
		vector<int> d(n);	//массив кратчайших путей
		
		used[s] = true;	//ну вот тут used
		while (!q.empty())
		{
			int v = q.front();	//выбираем вершину из очереди
			q.pop();	//ужаляем вершину из очереди
			int to = v;	//след вершина
			for (size_t i = 0; i < graph[v].size(); ++i)
			{

				if (/*i != v &&*/ graph[i][v] == 1)
				{
					to = i;	//если вершина смежна с ребром и эта вершина не является стартовой
					if (!used[to])
					{
						used[to] = true;	//юзед тру
						q.push(to);	//отправляем в очередь
						d[to] = d[v] + 1;	//изменяем значение пути
					}
				}
			}

		}
		e.push_back(*max_element(d.begin(),d.end()));	//выбираем эксцентриситет для вершины, это будет наибольший из кратчайших путей
	}
	
	fout << *min_element(e.begin(), e.end());	//радиусом будет наименьший из эксцентриситетов
	fin.close();
	fout.close();
	return 0;
}

