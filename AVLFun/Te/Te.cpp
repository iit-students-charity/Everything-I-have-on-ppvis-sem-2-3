// Te.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <AVLFun\AVLFun.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void testr(AVLFuncs::AVLFunctions::AVLNode *d)
{
	AVLFuncs::AVLFunctions::AVLNode *t = d;
	while (t)
	{
		cout << (t->key);
		t = t->right;
	}
}
void testl(AVLFuncs::AVLFunctions::AVLNode *d)
{
	AVLFuncs::AVLFunctions::AVLNode *t = d;
	while (t)
	{
		cout << (t->key);
		t = t->left;
	}
}

int main()
{
	vector<int> r;
	for (int i = 0; i < 101; i++)
	{
		r.push_back(i);
		
	}
	/*random_shuffle(r.begin(), r.end());*/
	AVLFuncs::AVLFunctions::AVLNode *Epoint=NULL;
	for (int i = 0; i < 100; i++)
	{
		Epoint = AVLFuncs::AVLFunctions::insert(Epoint, r[i]);
		/*cout << Epoint->key << endl;*/
	}
	for (int i = 0; i < 100; i++)
	{
		cout << /*AVLFuncs::AVLFunctions::search(Epoint, i)->key*/r[i] << endl;

	}
	/*cout << AVLFuncs::AVLFunctions::findmax(Epoint)->key << endl << AVLFuncs::AVLFunctions::findmax(Epoint)->key<<endl<<Epoint->key;*/
	cout << Epoint->key << endl << Epoint->left->key << endl << Epoint->right->key;
    return 0;
}

