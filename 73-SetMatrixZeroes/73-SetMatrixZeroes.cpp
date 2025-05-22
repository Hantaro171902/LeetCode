// Last updated: 5/22/2025, 10:56:25 PM
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        for (int val = 1; val <= 6; val++) {
            bool valid = true;
            int rotTop = 0, rotBottom = 0;
            for (int i = 0; i < n; i++) {
                if (tops[i] != val && bottoms[i] != val) {
                    valid = false;
                    break;
                }
                if (tops[i] != val) rotTop++;      // needs rotation to top
                if (bottoms[i] != val) rotBottom++; // needs rotation to bottom
            }
            if (valid) {
                return min(rotTop, rotBottom);
            }
        }
        return -1;
    }
};