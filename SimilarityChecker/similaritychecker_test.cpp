#include <iostream>
#include "gmock/gmock.h"
#include "similaritychecker.cpp"

using namespace testing;

TEST(TS, TC1) {
	SimilarityChecker checker;
	int expected = 100;
	int score = checker.calculateScore("abcd", "abcd");
	EXPECT_EQ(expected, score);
}

TEST(TS, TC2) {
	SimilarityChecker checker;
	int expected = 40;
	int score = checker.getLengthScore("abcd", "abc");
	EXPECT_EQ(expected, score);
}

int main() {
	InitGoogleMock();
	return RUN_ALL_TESTS();
}