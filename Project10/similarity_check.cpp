#include<string>

using std::string;

class SimilarityChecker {
public:
	double getLengthPoint(string input1, string input2) {
		int length1 = input1.size();
		int length2 = input2.size();
		if (IsLengthZeroPoint(length1, length2)) { return 0; }

		int temp = length1;
		if (length1 < length2) {
			length1 = length2;
			length2 = temp;
		}

		double gap = double(length1 - length2)/double(length2);
		return (1 - gap) * MAX_LENGTH_POINT;
	}


private:
	static const int MAX_LENGTH_POINT = 60;

	bool IsLengthZeroPoint(int length1, int length2)
	{
		return (length1 * 2 <= length2) || (length2 * 2 <= length1);
	}

};