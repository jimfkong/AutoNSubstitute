#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../AutoNSubstitute/Node.h"

TEST(NodeTests, Constructor)
{
	Node node("\"foo\"");

	ASSERT_EQ(node.getString(), "foo");
}

TEST(NodeTests, AddChild)
{
	auto parent = std::make_shared<Node>("\"parent\"");
	auto child = std::make_shared<Node>("\"child\"");

	child->setParent(parent);

	ASSERT_EQ(parent->getChild("\"child\"")->getString(), "child");
	ASSERT_EQ(child->getParent()->getString(), "parent");
}