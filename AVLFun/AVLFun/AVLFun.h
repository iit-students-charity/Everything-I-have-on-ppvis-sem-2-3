#pragma once
#include <string>
namespace AVLFuncs
{
	class AVLFunctions
	{
	public:

		struct AVLNode {
			int key;
			unsigned char height;
			AVLNode* left;
			AVLNode* right;
			AVLNode(int k) { key = k; left = 0; right = 0; height = 1; }
		};

		

		static AVLNode* insert(AVLNode* d, int k);

		static AVLFunctions::AVLNode * search(AVLNode * d, int k);

		static AVLNode* findmin(AVLNode* d);

		static AVLFunctions::AVLNode * findmax(AVLNode * d);

		static AVLFunctions::AVLNode * findclosemin(AVLNode * d, int k);

		static AVLFunctions::AVLNode * findclosemax(AVLNode * d, int k);

		static AVLNode* removemin(AVLNode* d);

		static AVLNode* remove(AVLNode* d, int k);
	private:
		static AVLNode* balance(AVLNode* d);

		static char height(AVLNode* d);

		static int bfactor(AVLNode* d);

		static void fixheight(AVLNode* d);

		static AVLNode* rotateleft(AVLNode* d);

		static AVLNode* rotateright(AVLNode* d);
	};
}