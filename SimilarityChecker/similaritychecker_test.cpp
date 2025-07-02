#include <iostream>
#include "gmock/gmock.h"
#include "similaritychecker.cpp"

using namespace testing;

class SimilarityCheckerFixture : public Test {
public:
	SimilarityChecker checker;
	void checkTotalScore(const int expected, const string& input1, const string& input2) {
		EXPECT_EQ(expected, checker.calculateScore(input1, input2));
	}
	void checkLengthScore(const int expected, const string& input1, const string& input2) {
		EXPECT_EQ(expected, checker.getLengthScore(input1, input2));
	}
	void checkAlphaScore(const int expected, const string& input1, const string& input2) {
		EXPECT_EQ(expected, checker.getAlpha(input1, input2));
	}
};

TEST_F(SimilarityCheckerFixture, AllSame) {
	checkTotalScore(100, "abcd", "abcd");
}

TEST_F(SimilarityCheckerFixture, PartialLengthScore) {
	checkLengthScore(40, "abcd", "abc");
}

TEST_F(SimilarityCheckerFixture, PartialalphaScore) {
	checkAlphaScore(16, "aadefe", "aer");
}

TEST_F(SimilarityCheckerFixture, PartialTotalcore1) {
	checkTotalScore(70, "abcd", "abc");
}

TEST_F(SimilarityCheckerFixture, PartialTotalcore2) {
	checkTotalScore(16, "aadefe", "aer");
}

int main() {
	InitGoogleMock();
	return RUN_ALL_TESTS();
}