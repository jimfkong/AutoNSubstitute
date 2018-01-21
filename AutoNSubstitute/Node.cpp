#include "Node.h"

#include "Utilities.h"

Node::Node(const std::string& value) : m_value(value), m_parent(nullptr) {}

Node::~Node() {}

// TODO Get rid of a lot of those checks to keyInMap and throw exceptions instead

void Node::appendChild(std::shared_ptr<Node> newChild)
{
	m_children.insert(std::make_pair(newChild->getKey(), newChild));
}

std::shared_ptr<Node> Node::getChild(const std::string& key) const
{
	return m_children.at(key);
}

std::shared_ptr<Node> Node::getParent() const
{
	return m_parent;
}

bool Node::isLeaf() const
{
	return (m_children.size() > 0) ? false : true;
}

bool Node::isRoot() const
{
	return m_parent ? true : false;
}

std::shared_ptr<Node> Node::removeChild(const std::string& key)
{
	auto child = m_children.at(key);
	child->setParent(nullptr);
	m_children.erase(key);

	return child;
}

void Node::setParent(std::shared_ptr<Node> newParent)
{
	if (m_parent)
	{
		// TODO Check that this doesn't do weird unexpected shit
		m_parent->removeChild(getKey());
	}

	m_parent = newParent;
	newParent->appendChild(std::make_shared<Node>(shared_from_this()));
}

bool Node::isNull() const
{
	return (m_value.compare("null") == 0);
}

bool Node::isArray() const
{
	// TODO Should also check if it ends with ']'
	return Utilities::stringStartsWith(m_value, "[");
}

bool Node::isString() const
{
	// TODO Should also check ends with
	return Utilities::stringStartsWith(m_value, "\"");
}

bool Node::isBool() const
{
	return (m_value.compare("true") == 0) || 
		(m_value.compare("false") == 0);
}

bool Node::isInt() const
{
	return Utilities::isStringInt(m_value);
}

bool Node::isFloat() const
{
	return Utilities::isStringFloat(m_value) && 
		!Utilities::isStringInt(m_value);
}

std::string Node::getKey() const
{
	if (isString())
	{
		return getString();
	}
	else if (isBool() || isNull() || isInt() || isFloat())
	{
		return m_value;
	}
	else if (isArray())
	{
		// TODO WHAT IS THE ARRAY KEY?
		return "array";
	}

	throw std::exception("could not generate key");
}

std::string Node::getString() const
{
	if (isString())
	{
		return Utilities::trim(m_value, "\"");
	}

	throw std::logic_error("value is not string");
}

bool Node::getBool() const
{
	if (isBool())
	{
		return Utilities::stringToBool(m_value);
	}

	throw std::logic_error("value is not bool");
}

int Node::getInt() const
{
	if (isInt())
	{
		return strtol(m_value.c_str(), nullptr, 10);
	}

	throw std::logic_error("value is not int");
}

float Node::getFloat() const
{
	if (isFloat())
	{
		return std::stof(m_value, nullptr);
	}

	throw std::logic_error("value is not float");
}

std::vector<std::shared_ptr<Node>> Node::getArray() const
{
	if (isArray())
	{
		auto elements = Utilities::splitLine(
			Utilities::trim(
				Utilities::trim(m_value, "]"), "["), ',');
		std::vector<std::shared_ptr<Node>> nodes;

		for (auto it = elements.begin(); it != elements.end(); ++it)
		{
			nodes.push_back(std::make_shared<Node>(*it));
		}

		return nodes;
	}

	throw std::logic_error("value is not array");
}
