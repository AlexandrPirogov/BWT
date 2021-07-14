#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main() {
	BinaryTree b_tree(3, 4);
	b_tree.tree_seach(b_tree.root);
	for (int i = 0; i < b_tree.vec.size(); i++)
		std::cout << b_tree.vec[i] << " ";
	cout << endl;
	//b_tree.tree_print(b_tree.vec, 1, 3);
	b_tree.show_colors(b_tree.root);
	return 0;
}