#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../AutoNSubstitute/Utilities.h"

TEST(TrimTests, TrimsSpace)
{
	ASSERT_EQ("foobar", Utilities::trim(" foobar "));
	ASSERT_EQ("foobar", Utilities::trim("    foobar  "));
}

TEST(TrimTests, TrimsChars)
{
	ASSERT_EQ("foobar", Utilities::trim("aaaaaafoobara", "a"));
}

TEST(TrimTests, TrimsEscapes)
{
	ASSERT_EQ("foobar", Utilities::trim("\n\n\nfoobar\n", "\n"));
	ASSERT_EQ("foobar", Utilities::trim("\"foobar\"", "\""));
}

TEST(TrimTests, TrimsStrings)
{
	ASSERT_EQ("bar", Utilities::trim("foofoofoobarfoo", "foo"));
}

TEST(IsStringIntTests, IsStringInt)
{
	ASSERT_TRUE(Utilities::isStringInt("1"));
	ASSERT_TRUE(Utilities::isStringInt("900"));
	ASSERT_TRUE(Utilities::isStringInt("4324"));
	ASSERT_TRUE(Utilities::isStringInt("-199"));

	ASSERT_FALSE(Utilities::isStringInt("1.232"));
	ASSERT_FALSE(Utilities::isStringInt("foobar"));
	ASSERT_FALSE(Utilities::isStringInt("false"));
	ASSERT_FALSE(Utilities::isStringInt(" "));
}

TEST(IsStringFloatTests, IsStringFloat)
{
	ASSERT_TRUE(Utilities::isStringFloat("0.0"));
	ASSERT_TRUE(Utilities::isStringFloat("109.21"));
	ASSERT_TRUE(Utilities::isStringFloat("-00.12"));

	ASSERT_FALSE(Utilities::isStringFloat("foobar"));	
	ASSERT_FALSE(Utilities::isStringFloat(" "));
	ASSERT_FALSE(Utilities::isStringFloat("true"));
}

TEST(IsStringFloatTests, IsStringIntFloat)
{
	ASSERT_FALSE(Utilities::isStringFloat("1"));
}

TEST(StringToBoolTests, ConvertStringToBool)
{
	ASSERT_TRUE(Utilities::stringToBool("true"));

	ASSERT_FALSE(Utilities::stringToBool("false"));

	ASSERT_FALSE(Utilities::stringToBool("1"));
	ASSERT_FALSE(Utilities::stringToBool("TRUE"));
}

TEST(SplitLineTests, SplitCSV)
{
	ASSERT_THAT(Utilities::splitLine("10,20,30,40,50", ','), 
		testing::ElementsAre("10", "20", "30", "40", "50"));
	ASSERT_TRUE(Utilities::splitLine("", ',').empty());
}