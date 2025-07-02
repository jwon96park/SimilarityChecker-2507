#include <string>
#include <set>

using std::string;

class SimilarityChecker {
public:
	int calculateScore(const string& input1, const string& input2) {
		if (input1 == input2) return 100;
		return getLengthScore(input1, input2) + getAlpha(input1, input2);
	}

	int getAlpha(const string& input1, const string& input2) {
		std::set<char> inputSet1, inputSet2, totalSet;

		makeSetFromString(input1, input2, inputSet1, inputSet2, totalSet);
		return 40 * calculateSameCount(inputSet1, inputSet2, totalSet) / totalSet.size();
	}

	int calculateSameCount(const std::set<char>& inputSet1, const std::set<char>& inputSet2, const std::set<char>& totalSet)
	{
		return inputSet1.size() + inputSet2.size() - totalSet.size();
	}

	void makeSetFromString(const std::string& input1, const std::string& input2, std::set<char>& inputSet1, std::set<char>& inputSet2, std::set<char>& totalSet)
	{
		for (char ch : input1) {
			inputSet1.insert(ch);
			totalSet.insert(ch);
		}
		for (char ch : input2) {
			inputSet2.insert(ch);
			totalSet.insert(ch);
		}
	}

	int getLengthScore(const string& input1, const string& input2) {
		int length1 = input1.length();
		int length2 = input2.length();
		if (length1 == length2) return 60;
		
		int shortLength, longLength;
		if (length1 > length2) {
			shortLength = length2;
			longLength = length1;
		}
		else {
			shortLength = length1;
			longLength = length2;
		}

		if (isLongerMoreThanTwice(longLength, shortLength)) return 0;
		return calculatePartialLengthScore(longLength, shortLength);
	}
	bool isLongerMoreThanTwice(const int length1, const int length2)
	{
		return length1 >= length2 * 2;
	}
	int calculatePartialLengthScore(const int length1, const int length2)
	{
		int gap = length1 - length2;
		return 60 - ((60 * gap) / length2);
	}
};