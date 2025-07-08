// Last updated: 7/8/2025, 11:58:06 PM
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int d : digits) freq[d]++;

        vector<int> result;

        for (int num = 100; num <= 999; num += 2) { // only even numbers
            int d1 = num / 100;
            int d2 = (num / 10) % 10;
            int d3 = num % 10;

            vector<int> tempFreq(10, 0);
            tempFreq[d1]++;
            tempFreq[d2]++;
            tempFreq[d3]++;

            bool valid = true;
            for (int i = 0; i < 10; ++i) {
                if (tempFreq[i] > freq[i]) {
                    valid = false;
                    break;
                }
            }

            if (valid) result.push_back(num);
        }

        return result;
    }
};