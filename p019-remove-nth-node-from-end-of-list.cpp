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
	/*20170804 2339*/
	/*AC       2351*/
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode newhead(0), *faster = &newhead, *slower = faster;
		newhead.next = head;

		while (n-- > 0) {
			if (!faster->next) return newhead.next;
			faster = faster->next;
		}

		while (faster->next) {
			faster = faster->next;
			slower = slower->next;
		}

		ListNode* tmp = slower->next;
		slower->next = tmp->next;
		delete tmp;

		return newhead.next;
	}
};
