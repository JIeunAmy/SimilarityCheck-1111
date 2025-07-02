#include<string>

using std::string;
struct IsAlphabetTouched {
	bool input1 = false;
	bool input2 = false;
};

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

	double getAlphabetPoint(string input1, string input2) {

		for (char ch : input1)
		{
			if (ch <ALPHABET_START || ch > ALPHABET_END) continue;
			int idx = ch - ALPHABET_START;
			alphabetTouchArr[idx].input1 = true;
		}

		for (char ch : input2)
		{
			if (ch <ALPHABET_START || ch > ALPHABET_END) continue;
			int idx = ch - ALPHABET_START;
			alphabetTouchArr[idx].input2 = true;
		}

		double point = 0;
		double total = 0;

		for (int idx = 0; idx < ALPHABET_COUNT; idx++)
		{
			if (alphabetTouchArr[idx].input1 && alphabetTouchArr[idx].input2) {
				point += 1;
			}
			if (alphabetTouchArr[idx].input1 || alphabetTouchArr[idx].input2) {
				total += 1;
			}
		}
		if (total == 0) return 0;

		return (point / total) * MAX_ALPHABET_POINT;
	}


private:
	static const int MAX_LENGTH_POINT = 60;
	static const int MAX_ALPHABET_POINT = 40;
	static const int ALPHABET_START = 'A';
	static const  int ALPHABET_END = 'Z';
	static const int ALPHABET_COUNT = 'Z' - 'A' + 1;

	IsAlphabetTouched alphabetTouchArr[ALPHABET_COUNT];

	bool IsLengthZeroPoint(int length1, int length2)
	{
		return (length1 * 2 <= length2) || (length2 * 2 <= length1);
	}

};