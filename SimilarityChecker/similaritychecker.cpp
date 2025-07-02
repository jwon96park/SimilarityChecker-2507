#include <string>

class SimilarityChecker {
public:
	int calculateScore(const std::string& input1, const std::string& input2) {
		int score = 0;
		if (input1 == input2) return 100;
		return score;
	}
};