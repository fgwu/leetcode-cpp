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
	/*20170520 0332*/
	/*20170520 1205 after seen the solutions...*/
	/*AC       1207*/
	void deleteNode(ListNode* node) {
		node->val = node->next->val;
		ListNode *tmp = node->next;
		node->next = tmp->next;
		delete tmp;
	}
};
