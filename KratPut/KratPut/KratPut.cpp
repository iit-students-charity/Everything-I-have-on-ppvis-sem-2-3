// KratPut.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <set>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	const int INF = INT32_MAX;
	int n, m;
	ofstream fout;
	ifstream fin;
	fin.open("path.in");
	fout.open("path.out", ios_base::trunc);
	fin >> n >> m;
	vector < vector < pair<int, int> > > g(n);	//сам граф представляет собой список смежности, где в списках хранятся пары, где 1 элемент пары - вершина, в которую ведет ребро, а 2 пара - вес ребра
	//*******чтение графа***************
	for (int i = 0; i < m; i++) {
		int t, v, w;
		fin >> t >> v >> w;
		t--, v--;
		g[t].push_back(make_pair(v, w));
		g[v].push_back(make_pair(t, w));
	}
	//*************************************
	int s = 0; // стартовая вершина

	vector<int> d(n, INF), p(n);
	d[s] = 0;
	priority_queue < pair<int, int> > q;
	q.push(make_pair(0, s));
	while (!q.empty()) {
		int v = q.top().second, cur_d = -q.top().first;
		q.pop();
		if (cur_d > d[v])  continue;

		for (size_t j = 0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
				q.push(make_pair(-d[to], to));
			}
		}
	}
	for (int i = 0; i < d.size(); i++)
	{
		fout << d[i] << " ";
	}
	fin.close();
	fout.close();
    return 0;
}

