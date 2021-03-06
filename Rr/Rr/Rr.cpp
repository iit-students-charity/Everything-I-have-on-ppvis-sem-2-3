// Rr.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, vector<vector<int>> gr, vector<int> col, int path, int init, ofstream &fout)
{
	int r=path;
	col[v] = 1;
	for (size_t i = 0; i < gr[v].size(); i++)
	{
		if ((col[i] == 0 || col[i] == 1) && r >= gr[v][i] && gr[v][i] != 0 && r >= 0)
		{
			r -= gr[v][i];
			if (r == 0)
			{
				r += gr[v][i];
				fout << init + 1 << ' ' << i + 1 << endl;
				col[i] = 2;
				dfs(v, gr, col, r, init, fout);
				break;
			}
			/*if (col[i] == 1)
			{
				col.assign(gr[i].size(), 0);
			}*/
			dfs(i, gr, col, r, init, fout);
		}
		col[v] = 2;
	}
}

int main()
{
	ofstream fout;
	ifstream fin;
	fin.open("prom.in");
	fout.open("prom.out", ios_base::trunc);
	int n, p;
	fin >> n >> p;
	/*int **color = new int*[n];
	for (int i = 0; i < n; i++)
	{
		color[i] = new int[n];
	}
	int **graph = new int*[n];
	for (int i = 0; i < n; i++)
	{
		graph[i] = new int[n];
	}*/
	vector<vector<int>> graph(n);
	vector<int> color(n);
	color.assign(n, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int u;
			fin >> u;

			graph[i].push_back(u);
		}
	}
	for (int i = 0; i < n; i++)
	{
		int init = i;
		dfs(i, graph, color, p, init, fout);
		/*if (graph[i][i] != 0)
		{
			if(p%graph[i][i]==0) fout << i + 1 << ' ' << i + 1 << endl;
		}*/
		color.assign(n, 0);
	}
	fin.close();
	fout.close();
    return 0;
}

