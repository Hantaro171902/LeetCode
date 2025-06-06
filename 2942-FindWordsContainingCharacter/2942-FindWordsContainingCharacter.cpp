// Last updated: 6/6/2025, 11:47:35 PM
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