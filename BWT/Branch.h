#pragma once
#include "Node.h"
#include <string>

class Node;

class Branch
{
public:
	Node* parent_node;
	Node* child_node;

	Node* up_left_node;
	Node* up_right_node;


	std::string color;
	Branch(Node* parent, Node* child) : parent_node(parent), child_node(child) { 
		this->color = "";
	};

	
};
