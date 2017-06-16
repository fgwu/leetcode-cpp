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
	/*20170615 1904: use double pointer (start, tmp) solution */
	/*AC       1911*/
	ListNode* reverseList(ListNode* head) {
		if (!head) return head;
		ListNode *start = head, *tmp = start->next;
		while (tmp) {
			start->next = tmp->next;
			tmp->next = head;
			head = tmp;
			tmp = start->next;
		}
		return head;
	}


	/*20170523 1958*/
	/*AC       2000*/
	// ListNode* reverseList(ListNode* head) {
	//     ListNode *p = head, *tmp;
	//     head = nullptr;
	//     while (p) {
	//         tmp = p;
	//         p = p->next;
	//         tmp->next = head;
	//         head = tmp;
	//     }

	//     return head;
	// }
};
