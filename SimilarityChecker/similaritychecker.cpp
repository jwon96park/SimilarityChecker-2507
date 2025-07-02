#include <string>

class SimilarityChecker {
public:
	int calculateScore(const std::string& input1, const std::string& input2) {
		int score = 0;
		if (input1 == input2) return 100;
		return score;
	}

	int getLengthScore(const std::string& input1, const std::string& input2) {
		int length1 = input1.length();
		int length2 = input2.length();
		if (length1 == length2) return 60;
		
		int gap = 0;
		if (length1 > length2) {
			if (length1 >= length2 * 2) return 0;
			gap = length1 - length2;
			return 60 - ((60 * gap) / length2);
		}
		else {
			if (length1 * 2 <= length2) return 0;
			gap = length2 - length1;
			return 60 - ((60 * gap) / length1);
		}
	}
};