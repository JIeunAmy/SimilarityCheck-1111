#include<string>

using std::string;

class SimilarityChecker {
public:
	int getLengthPoint(string input1, string input2) {
		int size1 = input1.size();
		int size2 = input2.size();

		if (size1 == size2) { return MAX_LENGTH_POINT; }
		if ((size1 * 2 == size2) || (size2 * 2 == size1)) { return 0; }
	}

private:
	static const int MAX_LENGTH_POINT = 60;
};