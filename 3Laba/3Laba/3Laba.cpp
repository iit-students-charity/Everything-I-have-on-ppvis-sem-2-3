// 3Laba.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <io.h>
#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;



vector<string> parse(string in1)
{
	int c = 0;	//чтобы считать вложенные множества
	int d = 0;	//чтобы считать вложенные кортежи
	vector <unsigned int> pos;
	vector<string> to;
	pos.push_back(0);
	for (size_t i = 0; i < in1.length(); i++)	//находим позиции запятых, за элемент считаем только при условии, что запятая не находится во вложенном множестве или кортеже
	{
		if (in1[i] == '{') c++;
		if (in1[i] == '}') c--;
		if (in1[i] == '<') d++;
		if (in1[i] == '>') d--;
		if (in1[i] == ',' && c == 1 && d == 0)
		{
			pos.push_back(i);
		}
	}
	pos.push_back(in1.length() - 1);	//найденные элементы кидаем в вектор
	for (size_t i = 0; i < pos.size() - 1; i++)
	{
		to.push_back(in1.substr(pos[i] + 1, pos[i + 1] - pos[i] - 1));
	}
	return to;
}

string rsort(string in)
{
	int c = 0;
	int d = 0;
	vector <unsigned int> pos;
	vector <string> subs;
	pos.push_back(0);
	for (size_t i = 0; i < in.length(); i++)	//аналогично находим элементы
	{
		if (in[i] == '{') c++;
		if (in[i] == '}') c--;
		if (in[i] == '<') d++;
		if (in[i] == '>') d--;
		if (in[i] == ',' && c == 1 && d == 0)
		{
			pos.push_back(i);
		}
	}
	pos.push_back(in.length() - 1);
	string out;
	for (size_t i = 0; i < pos.size() - 1; i++)
	{
		subs.push_back(in.substr(pos[i] + 1, pos[i + 1] - pos[i] - 1));
	}
	sort(subs.begin(), subs.end());	//сортируем элементы
	out += '{';
	for (size_t i = 0; i < subs.size(); i++)	//рекурсивно сортируем любые вложенные множества
	{
		if (subs[i][0] == '{')
		{
			subs[i] = rsort(subs[i]) + '}';
		}
	}
	for (size_t i = 0; i < pos.size() - 1; i++)
	{
		out += subs[i];
		out += ',';
	}
	out.erase(out.length() - 1, 1);
	return out;
}

vector<pair<int, string>> parse2(vector<string> els)
{
	vector <pair<int, string>> to;
	set<string> control;
	for (size_t i = 0; i < els.size(); i++)
	{
		int counter = 0;
		for (size_t j = i; j < els.size(); j++)
		{
			if (els[i] == els[j] && find(control.begin(),control.end(),els[i])==control.end())	//разбиваем строку на вектор с кратными вхождениями, 1 пара - количество вхождений, 2 пара - сам элемент
			{
				counter++;
			}
		}
		if (counter)
		{
			to.push_back(make_pair(counter, els[i]));
			control.insert(els[i]);
		}
	}
	return to;
}

vector<pair<int, string>> intersect(vector<pair<int, string>> in1, vector<pair<int, string>> in2)	//ну короче типа смотрим есть ли элемент в обоих множествах, если есть, то выбираем минимальную кратность вхождения и записываем вместе с элементом
{
	vector<pair<int, string>> out;
	for (size_t i = 0; i < in1.size(); i++)
	{
		for (size_t j = 0; j < in2.size(); j++)
		{
			if (in1[i].second == in2[j].second)
			{
				out.push_back(make_pair(min(in1[i].first, in2[j].first), in1[i].second));	
			}
		}
	}
	return out;
}

int main()
{
	ifstream fin;
	fin.open("test.txt");
	string in1, in2;
	fin >> in1;
	vector<pair<int, string>> set1 = parse2(parse(rsort(in1) + '}'));	//парсим
	while (!fin.eof())	//читаем до конца файла, чтобы сколько угодно множеств было
	{
		fin >> in2;
		vector<pair<int, string>> set2 = parse2(parse(rsort(in2) + '}'));	//еще парсим
		set1 = intersect(set1, set2);	//интерсект
	}
	cout << '{';
	for (size_t i = 0; i < set1.size(); i++)	//вывод результатов
	{
		cout << set1[i].first << '*' << set1[i].second;
		if (i != set1.size() - 1) cout << ',';
	}
	cout << '}' << endl;
	return 0;
}