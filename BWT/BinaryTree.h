#pragma once
#include "Node.h"
#include "Branch.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "Color.h"

class Node;
class Branch;
enum class Color;

class BinaryTree {
public:
	std::vector<std::string> vec;
	Node* root;
	BinaryTree(int _deep, int colors_count) : deep(_deep), colors_count(colors_count) {
		this->root = new Node(nullptr, nullptr, nullptr);
		create_tree(root, 0);
		choose_colors(this->tree_colors, colors_count);
		color_tree(this->root, colors_count);
	};

	void tree_seach(Node* node);

	void tree_print(std::vector<std::string>& vec, int nodes, int deep = 2);

	void show_colors(Node* node);
private:

	int deep;
	int colors_count;
	std::vector<Color> tree_colors;

	void create_tree(Node* node,int current_deep);

	void add_left_node(Node* parent, int current_deep);
	
	void add_right_node(Node* parent, int current_deep);

	void get_spaces(int& spaces, int& deep);

	void print_node(std::vector<std::string>& vec, int& spaces, int& nodes);

	void print_branches(std::vector<std::string>& vec, int& spaces, int& nodes);

	void color_tree(Node* node, int& colors_count);

	void choose_colors(std::vector<Color>& vec, int colors_count);

	Color random_color(std::vector<Color>& vec);

};