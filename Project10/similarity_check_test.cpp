#include "gmock/gmock.h"
#include <string>
#include "similarity_check.cpp"

using namespace std;
using namespace testing;

TEST(SimilarStingTest, LengthCheck) {
	SimilarityChecker similarityChecker;

	string input1 = "ABCD";
	string input2 = "ABCD";
	int expected = 60;

	EXPECT_EQ(expected, similarityChecker.getLengthPoint(input1, input2));
}