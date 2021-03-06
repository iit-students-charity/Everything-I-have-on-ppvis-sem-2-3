// AVLFun.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "AVLFun.h"
#include <stdexcept>


namespace AVLFuncs
{
	/*struct AVLNode
	{
		int key;
		char height;
		AVLNode* left;
		AVLNode* right;
		AVLNode(int k) { key = k; left = 0; right = 0; height = 1; }

	};*/
	char AVLFuncs::AVLFunctions::height(AVLNode *d)
	{
		return d ? d->height : 0;
	}
	int AVLFunctions::bfactor(AVLNode * d)
	{
		return height(d->right)-height(d->left);
	}
	void AVLFunctions::fixheight(AVLNode * d)
	{
		unsigned char hl = height(d->left);
		unsigned char hr = height(d->right);
		d->height = (hl > hr ? hl : hr) + 1;
	}
	AVLFunctions::AVLNode* AVLFunctions::rotateleft(AVLNode* q)
	{
		AVLNode* p = q->right;
		q->right = p->left;
		p->left = q;
		fixheight(q);
		fixheight(p);
		return p;
	}
	AVLFunctions::AVLNode* AVLFunctions::rotateright(AVLNode * p)
	{
		AVLNode* q = p->left;
		p->left = q->right;
		q->right = p;
		fixheight(p);
		fixheight(q);
		return q;
	}
	AVLFunctions::AVLNode* AVLFunctions::balance(AVLNode * d)
	{
		fixheight(d);
		if (bfactor(d) == 2)
		{
			if (bfactor(d->right) < 0)
				d->right = rotateright(d->right);
			return rotateleft(d);
		}
		if (bfactor(d) == -2)
		{
			if (bfactor(d->left) > 0)
				d->left = rotateleft(d->left);
			return rotateright(d);
		}
		return d;
	}
	AVLFunctions::AVLNode* AVLFunctions::insert(AVLNode* d, int k)
	{
		if (!d) return new AVLNode(k);
		if (k<d->key)
			d->left = insert(d->left, k);
		else
			d->right = insert(d->right, k);
		return balance(d);
	}
	AVLFunctions::AVLNode* AVLFunctions::search(AVLNode * d, int k)
	{
		while (d!=NULL)
		{
			if (d->key == k) return(d);
			return d->key < k ? search(d->right, k) : search(d->left, k);
		}
		return NULL;
	}
	AVLFunctions::AVLNode* AVLFunctions::findmin(AVLNode * d)
	{
		return d->left ? findmin(d->left) : d;
	}
	AVLFunctions::AVLNode* AVLFunctions::findmax(AVLNode * d)
	{
		return d->right ? findmax(d->right) : d;
	}
	AVLFunctions::AVLNode* AVLFunctions::findclosemin(AVLNode * d, int k)
	{
		for (int i = k-1; i >= findmin(d)->key; i--)
		{
			AVLNode *t = search(d, i);
			if (t != NULL) return t;
		}
		return NULL;
	}
	AVLFunctions::AVLNode* AVLFunctions::findclosemax(AVLNode * d, int k)
	{
		for (int i = k+1; i <= findmax(d)->key; i++)
		{
			AVLNode *t = search(d, i);
			if (t != NULL) return t;
		}
		return NULL;
	}
	AVLFunctions::AVLNode* AVLFunctions::removemin(AVLNode * d)
	{
		if (d->left == 0)
			return d->right;
		d->left = removemin(d->left);
		return balance(d);
	}
	AVLFunctions::AVLNode* AVLFunctions::remove(AVLNode * d, int k)
	{
		if (!d) return 0;
		if (k < d->key)
			d->left = remove(d->left, k);
		else if (k > d->key)
			d->right = remove(d->right, k);
		else
		{
			AVLNode* q = d->left;
			AVLNode* r = d->right;
			delete d;
			if (!r) return q;
			AVLNode* min = findmin(r);
			min->right = removemin(r);
			min->left = q;
			return balance(min);
		}
		return balance(d);
	}
}
