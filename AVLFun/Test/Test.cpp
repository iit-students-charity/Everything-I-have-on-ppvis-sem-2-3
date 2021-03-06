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
	random_shuffle(r.begin(), r.end());
	AVLFuncs::AVLFunctions::AVLNode *Epoint = NULL;
	cout << "Inserting numbers from 0 to 100 in random order into the tree" << endl;
	for (int i = 0; i < 100; i++)
	{
		Epoint = AVLFuncs::AVLFunctions::insert(Epoint, r[i]);
	}
	cout << "Searching for an adress of the node with key value 13:" << endl;
	cout << AVLFuncs::AVLFunctions::search(Epoint, 13) << endl;
	cout << "Removing the node with key value 13:" << endl;
	Epoint = AVLFuncs::AVLFunctions::remove(Epoint, 13);
	cout << AVLFuncs::AVLFunctions::search(Epoint, 13) << endl;
	cout << "Searching for the minimum and maximum key:" << endl;
	cout << AVLFuncs::AVLFunctions::findmin(Epoint)->key << " " << AVLFuncs::AVLFunctions::findmax(Epoint)->key << endl;
	cout << "Searhing for the closest minimum and maximum keys for 14:" << endl;
	cout << AVLFuncs::AVLFunctions::findclosemin(Epoint, 14)->key << " " << AVLFuncs::AVLFunctions::findclosemax(Epoint, 14)->key << endl;
	return 0;
}