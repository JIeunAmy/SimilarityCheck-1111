#include<string>

using std::string;

class SimilarityChecker {
public:
	double getLengthPoint(string input1, string input2) {
		int size1 = input1.size();
		int size2 = input2.size();

		if (size1 == size2) { return MAX_LENGTH_POINT; }
		if (IsLengthZeroPoint(size1, size2)) { return 0; }
		
		int temp = size1;
		if (size1 < size2) {
			size1 = size2;
			size2 = temp;
		}

		double gap = (size1 - size2)/double(size2);
		return (1 - gap) * MAX_LENGTH_POINT;
	}


private:
	static const int MAX_LENGTH_POINT = 60;

	bool IsLengthZeroPoint(int size1, int size2)
	{
		return (size1 * 2 == size2) || (size2 * 2 == size1);
	}
};