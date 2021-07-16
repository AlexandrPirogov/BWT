#pragma once
#include "Branch.h"
#include <string>

class Branch;

class Node {
public:
	Branch* left_branch;
	Branch* right_branch;
	Branch* parent_branch;

	Branch* parent_left_branch;
	Branch* parent_right_branch;


	std::string value;
	Node() { left_branch = nullptr; right_branch = nullptr; parent_branch; };

	Node(Branch* left, Branch* right, Branch* parent) 
		: left_branch(left), right_branch(right), parent_branch(parent) {
		this->value = "O";
	};
};
