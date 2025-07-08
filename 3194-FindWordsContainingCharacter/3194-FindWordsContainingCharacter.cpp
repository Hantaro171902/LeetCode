// Last updated: 7/8/2025, 11:57:38 PM
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;
	for (int i = 0; i < words.size(); ++i) {
		if (words[i].find(x) != string::npos) {
			result.push_back(i);
		}
	}
	return result;
    }
};