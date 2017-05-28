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
	/*20170523 1958*/
	/*AC       2000*/
	ListNode* reverseList(ListNode* head) {
		ListNode *p = head, *tmp;
		head = nullptr;
		while (p) {
			tmp = p;
			p = p->next;
			tmp->next = head;
			head = tmp;
		}

		return head;
	}
};
