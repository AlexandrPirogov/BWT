#pragma once
#include "BinaryTree.h"
#include "tree_linker.h"
#include <vector>
#include "Node.h"

class Node;
class Branch;
class BinaryTree;

class BWT {
public:
	BWT(int deep, int colors_count) 
	{
		up_tree = new BinaryTree(deep, colors_count);
		down_tree = new BinaryTree(deep, colors_count);
		get_leafs(down_tree_leafs, *down_tree);
		get_leafs(up_tree_leafs, *up_tree);
		link_trees(this->up_tree_leafs, this->down_tree_leafs);
	};

private:
	BinaryTree* up_tree;
	BinaryTree* down_tree;

	std::vector<Node*> down_tree_leafs;
	std::vector<Node*> up_tree_leafs;
	std::vector<Node*> linked_leafs;

	void get_leafs(std::vector<Node*>& nodes, BinaryTree& b_tree);

	void leafs_search(std::vector <Node*>& nodes, Node* node);

	void link_trees(std::vector<Node*> up_tree, std::vector<Node*> down_tree);

	void link_up_leafs(Node* one_node, Node* left_down_node);
	
	void link_down_leafs (Node* one_node,  Node* right_up_node);

	bool are_leafs_connected(std::vector<Node*>& leafs);

	void link_nodes(Node* up_tree, Node* down_tree);

	void link_up_to_left(Node* up_node, Node* left_down_node);

	void link_up_to_right(Node* up_node, Node* right_down_node);

	void link_down_to_left(Node* down_node, Node* left_up_node);

	void link_down_to_right(Node* down_node, Node* left_up_node);
};