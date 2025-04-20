// Last updated: 4/20/2025, 3:58:06 PM
class Solution {
public:
    int numRabbits(vector<int>& answers) {
            
        int total = 0;
        
        sort (answers.begin(), answers.end());
        
        for (int i=0; i < answers.size();) {
            int x = answers[i];
            int count = 1;	// count the number of  answer
            
            // count how many times this answer appears in a row
        
            int j = i + 1;
            while (j < answers.size() && answers[j] == x) {
                count++;
                j++;
            }
            
            int groupSize = x + 1;
        
            int groupCount = ceil((double)count / groupSize);
    //		cout << groupCount;
            total += groupCount * groupSize;
    //        cout << groupSize;
            i = j; // move to the next answer;

        }
        
        return total;
    }
};