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
	/*rec version*/
	/*AC 0006*/
	ListNode* removeElements(ListNode* head, int val) {
		if (!head) return head;
		if (head->val == val) return removeElements(head->next, val);
		head->next = removeElements(head->next, val);
		return head;
	}


	/*20170609 2351*/
	/*AC       2357*/
	// ListNode* removeElements(ListNode* head, int val) {
	//     ListNode dummy(0), *ptr = &dummy;
	//     dummy.next = head;
	//     while ( ptr->next ) {
	//         if (ptr->next->val != val) { ptr = ptr->next; continue;}
	//         ListNode* tmp = ptr->next;
	//         ptr->next = tmp->next;
	//         delete tmp;
	//     }
	//     return dummy.next;
	// }
};
