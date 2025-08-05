// Last updated: 8/5/2025, 11:16:59 PM
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> used(baskets.size(), false); // Track used baskets
        int unplaced = 0;

        for (int i = 0; i < n; i++) {
            bool placed = false;
            for (int j = 0; j < baskets.size(); j++) {
                if (!used[j] && baskets[j] >= fruits[i]) {
                    used[j] = true;
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                unplaced++;
            }
        }

        return unplaced;

    }
};