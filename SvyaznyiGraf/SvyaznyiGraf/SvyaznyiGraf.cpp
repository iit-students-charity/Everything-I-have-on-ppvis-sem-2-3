// SvyaznyiGraf.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "vector"
#include <fstream>
#include <queue>
using namespace std;


int main()
{
	ofstream fout;
	ifstream fin;
	fin.open("graph.txt");
	fout.open("output.txt", ios_base::trunc);
	int n, p;
	fin >> n >> p;
	vector<vector<int>> graph(n);	//список смежности
	for (int i = 0; i < p; i++) {	//заполнение неориентированного графа в виде списка смежности
		int u, v;
		fin >> u >> v;
		u--, v--;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	queue<int> q;	//сюда будем помещать вершины, которые нужно будет посетить
	q.push(0);	// помещаем нулевую вершину, для проверки графа на связность можно поместить вообще любую, которая существует в графе
	vector<bool> used(n);	//здесь будем отмечать посещенные вершины
	used[0] = true;		//нулевая вершина отмечена как посещенная
	while (!q.empty()) {	//поиск в ширину работает до тех пор, пока не посещены все вершины, до которых можно добраться, т.е. пока очередь не опустошится
		int v = q.front();	// берем следующую вершину
		q.pop();	//удаляем вершину из очереди
		for (size_t i = 0; i<graph[v].size(); ++i) {	//просмотр всех связей взятой вершины
			int to = graph[v][i];	//свяь
			if (!used[to]) {	//если не посещена
				used[to] = true;	//то вершина отмечается посещенной и добавляется в очередь
				q.push(to);
			}
		}
	}
	bool flag=true;
	for(int i = 0; i < used.size(); i++)	//если за один обход в ширину посещены не все вершины, то граф несвязный
	{
		if (!used[i]) flag = false;
	}
	if (flag) fout << "Граф связный"; else fout << "Граф несвязный";
}