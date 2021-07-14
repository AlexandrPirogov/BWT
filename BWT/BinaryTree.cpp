#include "BinaryTree.h"

void BinaryTree::tree_seach(Node* node)
{
	if (node != nullptr) {
		if (node->left_branch != nullptr) {
			tree_seach(node->left_branch->child_node);
			vec.push_back("/");
		}
		vec.push_back(node->value);
		if (node->right_branch != nullptr) {
			vec.push_back("\\");
			tree_seach(node->right_branch->child_node);
		}
	}
}

void BinaryTree::create_tree(Node* node, int current_deep)
{
	if (node->left_branch == nullptr && current_deep != this->deep) {
		this->add_left_node(node, current_deep);
	}
	if (node->right_branch == nullptr && current_deep != this->deep) {
		this->add_right_node(node, current_deep);
	}
}

void BinaryTree::add_left_node(Node	* parent, int current_deep)
{
	Node* child_left_br = new Node(nullptr, nullptr, nullptr);
	parent->left_branch = new Branch(parent, child_left_br);
	child_left_br->parent_branch = parent->left_branch;
	this->create_tree(parent->left_branch->child_node, ++current_deep);
}

void BinaryTree::add_right_node(Node* parent, int current_deep)
{
	Node* child_right_br = new Node(nullptr, nullptr, nullptr);;
	parent->right_branch = new Branch(parent, child_right_br);
	child_right_br->parent_branch = parent->right_branch;
	this->create_tree(parent->right_branch->child_node, ++current_deep);
}

void BinaryTree::get_spaces(int& spaces, int& deep)
{

	for (int i = 0; i < deep; i++)
		spaces += std::pow(2, i);
}

void BinaryTree::print_node(std::vector<std::string>& vec, int& spaces, int& nodes)
{
	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < spaces; j++) {
			std::cout << " ";
		}
		std::cout << "O";
	}
	for (int i = 0; i < nodes; i ++) {
		vec.erase(vec.begin(), vec.begin()+1);
	}
	std::cout << std::endl;
}

void BinaryTree::print_branches(std::vector<std::string>& vec, int& spaces, int& nodes)
{
	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j <= spaces; j++) {
			std::cout << " ";
		}
		std::cout << vec[i] << " ";
		std::cout << vec[i + 2] << " ";
		vec.erase(vec.begin() + i, vec.begin() + i + 1);
		vec.erase(vec.begin() + i + 1, vec.begin() + i + 2);
		i  += spaces;
	}

	std::cout << std::endl;
}

void BinaryTree::color_tree(Node* node, int& colors_count)
{
	if (node != nullptr	) {
		if (node->left_branch != nullptr) {
			if (node->left_branch->color == 0) {
				Color color = this->random_color(this->tree_colors);
				if (node != this->root) {
					while (color == *node->parent_branch->color) {
						color = this->random_color(this->tree_colors);
					}
					node->left_branch->color = &color;
				}
				else {
					node->left_branch->color = &color;
				}
			}
			color_tree(node->left_branch->child_node, colors_count);
		}
		if (node->right_branch != nullptr) {
			if (node->right_branch->color == 0) {
				Color color = this->random_color(this->tree_colors);
				if (node != this->root) {
					while (color == *node->parent_branch->color || color == *node->left_branch->color) {
						color = this->random_color(this->tree_colors);
					}
					node->right_branch->color = &color;
				}
				else {
					while (color == *node->left_branch->color ) {
						color = this->random_color(this->tree_colors);
					}
					node->right_branch->color = &color;
				}
				
			}
			color_tree(node->right_branch->child_node, colors_count);
		}
	}

}

void BinaryTree::choose_colors(std::vector<Color>& vec, int colors_count)
{
	Color colors;
	for (int i = 1; i < colors_count+1; i++) {
		colors = static_cast<Color>(i);
		vec.push_back(colors);
	}
}

Color BinaryTree::random_color(std::vector<Color>& vec)
{
	int ran = rand() % vec.size();
	return vec[ran];
}

void BinaryTree::show_colors(Node* node)
{
	if (node != nullptr) {
		if (node->left_branch != nullptr) {
			std::cout << node->left_branch->color << " ";
			show_colors(node->left_branch->child_node);
		}
		if (node->right_branch != nullptr) {
			std::cout << node->right_branch->color << " ";
			show_colors(node->right_branch->child_node);
		}
	}
}

void BinaryTree::tree_print( std::vector<std::string>& vec, int nodes, int deep)
{
	if (deep == 0)return;
	int spaces = 1;
	this->get_spaces(spaces, deep);


	this->print_node(vec, spaces, nodes);
	int n_spaces = spaces / 2;
	int n_nodes = nodes * 2;
	this->print_branches(vec, n_spaces, n_nodes);
	deep--;
	nodes *= 2;
	tree_print(this->vec, nodes, deep);
}
