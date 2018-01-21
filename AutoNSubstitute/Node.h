#pragma once

#ifndef NODE_H
#define NODE_H

#include <memory>
#include <unordered_map>
#include <string>
#include <vector>

class Node : std::enable_shared_from_this<Node>
{
public:
	Node(const std::string& value = "");
	~Node();

	void appendChild(std::shared_ptr<Node> newChild);
	std::shared_ptr<Node> getChild(const std::string& key) const;
	std::shared_ptr<Node> getParent() const;
	bool isLeaf() const;
	bool isRoot() const;
	std::shared_ptr<Node> removeChild(const std::string& key);
	void setParent(std::shared_ptr<Node> newParent);

	bool isNull() const;
	bool isArray() const;
	bool isString() const;
	bool isBool() const;
	bool isInt() const;
	bool isFloat() const;

	std::string getKey() const;
	std::vector<std::shared_ptr<Node>> getArray() const;
	std::string getString() const;
	bool getBool() const;
	int getInt() const;
	float getFloat() const;

private:
	std::string m_value;
	std::unordered_map<std::string, std::shared_ptr<Node>> m_children;
	std::shared_ptr<Node> m_parent;
};

#endif