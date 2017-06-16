/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	/*20170615 1840 try not using a tailing pointer */
	/*AC       1901 important: double pointer (start, temp) to reverse a linked list.*/
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode dummy(0), *pre = &dummy, *start, *tmp;
		dummy.next = head;
		for (int i = 0; i < m - 1; i++) pre = pre->next;
		for (start = pre->next, tmp = start->next, n -= m; n--; ){
			start->next = tmp->next;
			tmp->next = pre->next;
			pre->next = tmp;
			tmp = start->next;
		}
		cout << dummy.next->val;
		return dummy.next;
	}




	/*20170522 2138*/
	/*20170615 1759*/
	/*AC       1828*/
	// ListNode* reverseBetween(ListNode* head, int m, int n) {
	//     ListNode dummy(0), *start, *ptr, *tmp, *last;
	//     dummy.next = head;
	//     for (start = &dummy; start->next && --m && --n; start = start->next);

	//     for (last = ptr = start->next; ptr && n--;){
	//         tmp = ptr->next;
	//         ptr->next = start->next;
	//         start->next = ptr;
	//         ptr = tmp;
	//     }

	//     last->next = ptr;
	//     return dummy.next;
	// }
};
