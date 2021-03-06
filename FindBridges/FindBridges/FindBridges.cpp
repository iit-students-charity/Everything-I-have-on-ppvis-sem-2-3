// FindBridges.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <set>

using namespace std;

vector<vector<int>> g(50);
vector<bool> used;
vector<int> tin(50), fup(50);
set<int> res;
int timer;

void dfs(int v, int p = -1)	//поиск в глубину
{
	used[v] = true;	//текущая вершина посещена
	tin[v] = fup[v] = timer++;	//увеличиваем время входа и минимальное время захода
	for (size_t i = 0; i<g[v].size(); ++i) 
	{
		int to = g[v][i];	//просматриваем следующую вершину
		if (to == p)  continue;	// если не первый заход в вершину, то нормально
		if (used[to])
			fup[v] = min(fup[v], tin[to]);	//иначе если вершина уже была посещена, меняем минимальное время захода
		else {
			dfs(to, v);	//если не была посещена, то еще и поиск в глубину в нее делаем
			fup[v] = min(fup[v], fup[to]);
			if (fup[to] > tin[v])	//если найден мост, то добавляем вершины в множество найденных вершин
			{
				if (g[to].size() > 1)
				res.insert(to+1);
				if (g[v].size() > 1)
				res.insert(v+1);
			}
		}
	}
}


int main()
{
	int n, m;
	ifstream fin;
	fin.open("graphin.txt");
	ofstream fout;
	fout.open("graphout.txt", ios_base::trunc);
	fin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		fin >> u >> v;
		u--, v--;

		g[u].push_back(v);
		g[v].push_back(u);
	}
	timer = 0;
	used.assign(n, false);
	for (size_t i = 0; i < used.size(); ++i)
	{
		if (!used[i])
			dfs(i);
	}
	set<int>::iterator iter;
	for (iter = res.begin(); iter != res.end(); ++iter)
	{
		fout << (*iter) << endl;
	}
	fin.close();
	fout.close();
    return 0;
}

