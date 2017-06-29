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
	/*20170619 1208*/
	/*AC       1245*/
	ListNode *detectCycle(ListNode *head) {
		ListNode *fast = head, *slow = head;
		while(fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) break;
		}
		if (!fast || !fast->next) return NULL;
		for(fast = head; fast != slow; fast = fast->next, slow = slow->next);
		return fast;
	}
};
