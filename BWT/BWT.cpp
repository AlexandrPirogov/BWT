#include "BWT.h"

void BWT::get_leafs(std::vector<Node*>& nodes, BinaryTree& b_tree)
{
	leafs_search(nodes, b_tree.root);
}

void BWT::leafs_search(std::vector<Node*>& nodes, Node* node)
{
	if (node != nullptr) {
		if (node->left_branch == nullptr && node->right_branch == nullptr) {
			nodes.push_back(node);
		}
		if (node->left_branch != nullptr) {
			leafs_search(nodes, node->left_branch->child_node);
		}
		if (node->right_branch != nullptr) {
			leafs_search(nodes, node->right_branch->child_node);
		}
	}
}

void BWT::link_trees(std::vector<Node*> up_tree, std::vector<Node*> down_tree)
{
	int end_point;
	int size = this->up_tree_leafs.size();
	for (int i = 0; i < size; i+=2) {
		this->up_tree_leafs[i]->left_branch->child_node = this->down_tree_leafs[i];
		this->down_tree_leafs[i]->parent_right_branch = this->up_tree_leafs[i];
		this->up_tree_leafs[i]->right_branch->child_node = this->down_tree_leafs[i + 1];
		this->down_tree_leafs[i]->left_branch->parent_node = this->up_tree_leafs[i];
		this->down_tree_leafs[i]->parent_branch = this->up_tree_leafs[i+1];
	}

}

void BWT::link_up_leafs(Node* one_node, Node* left_down_node)
{
	Branch* left_branch = new Branch(one_node, left_down_node);
	one_node->left_branch = left_branch;
	left_down_node->parent_branch = left_branch;

}

void BWT::link_down_leafs(Node* one_node, Node* right_up_node)
{
	Branch* left_branch = new Branch(one_node, right_up_node);
	one_node->left_branch = left_branch;
	right_up_node->right_branch = left_branch;
}


bool BWT::are_leafs_connected(std::vector<Node*>& leafs)
{
	int size = leafs.size();
	for (int i = 0; i < size; i++) {
		if (leafs[i] == false)return false;
	}
	return true;
}

void BWT::link_nodes(Node* up_tree, Node* down_tree)
{
	Branch* branch = new Branch(up_tree, down_tree);
	
}
