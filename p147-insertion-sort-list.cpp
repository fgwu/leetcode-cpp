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
	/*20170616 1150*/
	/*AC       1201*/
	ListNode* insertionSortList(ListNode* head) {
		ListNode dummy(0), *ptr, *tmp;
		while(head) {
			tmp = head->next;
			// insert tmp into dummy
			for (ptr = &dummy; ptr->next; ptr = ptr->next)
				if (ptr->next->val > head->val) break;

			head->next = ptr->next;
			ptr->next = head;
			head = tmp;
		}
		return dummy.next;
	}
};
