You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 
Example 1:

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]


Example 2:

Input: list1 = [], list2 = []
Output: []


Example 3:

Input: list1 = [], list2 = [0]
Output: [0]


 
Constraints:


	The number of nodes in both lists is in the range [0, 50].
	-100 <= Node.val <= 100
	Both list1 and list2 are sorted in non-decreasing order.


## ✅ Solutions
1. Define a structure of single-list
```c++
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int data1) {
		val = data1;
		next = NULL;
	}
	ListNode(int data1, ListNode *next1) {
		val = data1;
		next = next1;
	}
};
```
2. Function mergeTwoSortList

We use <strong>dummy</strong> as a placeholder node
```c++
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	ListNode dummy(0);
	ListNode* temp = &dummy;
	
	// when both list1 and list2 isn't empty
	while (list1 && list2) {
		if (list1->val <= list2->val) {
			temp->next = list1;
			list1 = list1->next;
		} else {
			temp->next = list2;
			list2 = list2->next;
		}
		temp = temp->next;
	}
	
	if (list1) temp->next = list1;
	if (list2) temp->next = list2;
	
	return dummy.next;
}
```
3. Funtion buildList

```c++
ListNode* buildList(vector<int>& val) {
	ListNode* head = NULL;
	ListNode* tail = NULL;
	
	for (int i=0; i < val.size(); i++) {
		int data = val[i];
		ListNode* newNode = new ListNode(data);
		if (!head) {
			head = newNode;
			tail = newNode;
		} else {
			tail->next = newNode;
			tail = tail->next;
		}
	}
	
	return head;
}
```




