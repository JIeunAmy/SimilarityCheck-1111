#include "gmock/gmock.h"
#include <string>
#include "similarity_check.cpp"

using namespace std;
using namespace testing;

class SimilarityCheckerFixture :public Test
{
private:
	SimilarityChecker similarityChecker;

public:
	void checkLength(string input1, string input2, int expected)
	{
		EXPECT_EQ(expected, similarityChecker.getLengthPoint(input1, input2));
	}
	void checkAlphabet(string input1, string input2, int expected)
	{
		EXPECT_EQ(expected, similarityChecker.getAlphabetPoint(input1, input2));
	}
};

TEST_F(SimilarityCheckerFixture, LengthCheckMaxPoint) {
	checkLength("ABDC", "ABCD", 60);
}

TEST_F(SimilarityCheckerFixture, LengthCheckZeroPoint) {
	checkLength("ABDC", "ABCDABCDdfsdsfs", 0);
}

TEST_F(SimilarityCheckerFixture, LengthCheckPartialPoint) {
	checkLength("ABCDEFGHIJ", "ABCDEFGHIJwoej", 36);
}

TEST_F(SimilarityCheckerFixture, AlphabetCheckMaxPoint) {
	checkAlphabet("ABDC", "ABCD", 40);
}

TEST_F(SimilarityCheckerFixture, AlphabetCheckZeroPoint) {
	checkAlphabet("ABDC", "QWER", 0);
}
