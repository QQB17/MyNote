#include <iostream>
#include <fstream>

#include "pch.h"

// EXPECT = nonfatal assertion, continue function while failure
// ASSERT = fatal assertion, abort the current function while failure

TEST(Sum, Add) {
	Sum s;
	EXPECT_EQ(10, s.Add(5, 5)); // equal
	EXPECT_NE(1, s.Add(5, 3)); // not equal
	EXPECT_LT(5, s.Add(4, 5)); // lower than
	EXPECT_LE(5, s.Add(5, 3)); // lower than or equal
	EXPECT_GT(12, s.Add(5, 3)); // greater than
	EXPECT_GE(10, s.Add(5, 3)); // greater than or equal
}

TEST(Sum, Addchar) {
	Sum s;
	// Use normal assertion to compare two string object
	EXPECT_EQ("Hi", s.AddChar("H", "i"));
	EXPECT_NE("hello", s.AddChar("H", "i"));

}

TEST(C_String, STR) {
	//C string = array of char
	char* c1 = "hi", * c2 = "HI", * c3 = "Hello";
	EXPECT_STRCASEEQ(c1, c2); // C_string, case ignore, equal
	EXPECT_STRCASENE(c1, c3); // C_String, case ignore, not equal
	EXPECT_STREQ("hi",c1); // C_String, equal
	EXPECT_STRNE(c1, c3); // C_String, not equal
}

int main(int argc, char* argv[]) {
	//std::ofstream Log("Google_Test_Log.txt");
	
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}