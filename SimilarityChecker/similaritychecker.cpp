#include <string>
#include <set>

using std::string;

class SimilarityChecker {
public:
	int calculateScore(const string& input1, const string& input2) {
		int score = 0;
		if (input1 == input2) return 100;
		return score;
	}

	int getAlpha(const string& input1, const string& input2) {
		std::set<char> set1, set2, totalSet;

		for (char ch : input1) {
			set1.insert(ch);
			totalSet.insert(ch);
		}
		for (char ch : input2) {
			set2.insert(ch);
			totalSet.insert(ch);
		}
		int sameCount = set1.size() + set2.size() - totalSet.size();
		return 40 * sameCount / totalSet.size();
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