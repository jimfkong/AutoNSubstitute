#pragma once

#ifndef TREE_H
#define TREE_H

#include "Node.h"

class Tree
{
public:
	Tree(std::shared_ptr<Node> root) {}
	~Tree() {}
	
	std::shared_ptr<Node> getRoot() const;

private:
	std::shared_ptr<Node> m_root;

};

#endif