// KoroviyTanci.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <io.h>
#include <vector>
#include <fstream>

using namespace std;

int n, m, counter = 0;
int ncycle = 0;
vector<vector<int>> g(100000); 
vector<char> color(100000);
vector<int> p;
vector <int> cycle;

bool dfs(int v)
{
	color[v] = 1;
	for (size_t i = 0; i < g[v].size(); ++i)
	{
		int to = g[v][i];
		if ((color[to] == 0) && g[v].size() <= 2 && g[to].size() <= 2)
		{
			if (dfs(to)) return true;
		}
		else if (color[to] == 1)
		{	
			return true;
		}
	}
	color[v] = 2;
	return false;
}

int main()
{
	ofstream fout;
	ifstream fin;
	fin.open("prom.in");
	fout.open("prom.out", ios_base::trunc);
	fin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		fin >> u >> v;
		u--, v--;

		g[u].push_back(v);
		//g[v].push_back(u);
	}
	p.assign(n, -1);
	color.assign(n, 0);
	for (int g = 0; g < n; g++)
		if (color[g] == 0)
			if(dfs(g)) counter++;
	if (counter != 1 || m>n) counter++;
	fout << counter;
	fin.close();
	fout.close();
    return 0;
}

