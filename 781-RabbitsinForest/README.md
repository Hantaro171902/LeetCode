```Medium```

There is a forest with an unknown number of rabbits. We asked n rabbits "How many rabbits have the same color as you?" and collected the answers in an integer array answers where answers[i] is the answer of the ith rabbit.

Given the array answers, return the minimum number of rabbits that could be in the forest.

 
Example 1:

Input: answers = [1,1,2]
Output: 5
Explanation:
The two rabbits that answered "1" could both be the same color, say red.
The rabbit that answered "2" can't be red or the answers would be inconsistent.
Say the rabbit that answered "2" was blue.
Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn't.


Example 2:

Input: answers = [10,10,10]
Output: 11


 
Constraints:


	1 <= answers.length <= 1000
	0 <= answers[i] < 1000
===
# 🐰 Rabbits in Forest – Explanation
## 🧩 Problem Summary:

Each rabbit in a forest is asked "how many rabbits have the same color as you?", and we are given a list of their answers.

An answer x means there are x other rabbits with the same color, so ```x + 1``` rabbits in that color group (including the one that answered).

Multiple rabbits may give the same answer, but that doesn’t mean they are in the same group — no group can have more than ```x + 1``` rabbits if they all answered x.

## 🧠 Algorithm Steps:
1. Sort the input to group identical answers together.
2. Use a loop to:

- Count how many times the same answer appears in a row.
- Compute the group size as ```x + 1```.
- Compute how many groups are needed using ```ceil(count / groupSize)```.
- Add ```groupCount * groupSize``` to the total.
- Skip over already-counted answers by updating the index.

## ✅ Solution

int numRabbits(vector<int>& answers) {
```c++
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

        total += groupCount * groupSize;
        i = j; // move to the next answer;
	}
	return total;
}
```
