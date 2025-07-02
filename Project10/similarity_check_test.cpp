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
	void checkSimilarity(string input1, string input2, int expected)
	{
		EXPECT_EQ(expected, similarityChecker.getLengthPoint(input1, input2));
	}
};

TEST_F(SimilarityCheckerFixture, LengthCheckMaxPoint) {
	checkSimilarity("ABDC", "ABCD", 60);
}

TEST_F(SimilarityCheckerFixture, LengthCheckZeroPoint) {
	checkSimilarity("ABDC", "ABCDABCDdfsdsfs", 0);
}

TEST_F(SimilarityCheckerFixture, LengthCheckPartialPoint) {
	checkSimilarity("ABCDEFGHIJ", "ABCDEFGHIJwoej", 36);
}