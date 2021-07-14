#pragma once
#include "Node.h"


class Node;
enum class Color;

class Branch
{
public:
	Node* parent_node;
	Node* child_node;
	Color* color;
	Branch(Node* parent, Node* child) : parent_node(parent), child_node(child) {
		this->color = 0;
	};
};
