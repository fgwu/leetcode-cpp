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
	/*20170616 1119*/
	/*AC       1147*/
	ListNode* merge(ListNode* left, ListNode* right) {
		ListNode dummy(0), *ptr = &dummy, *tmp;
		while (left || right) {
			if ((left && right && left->val > right->val) || !left) {
				tmp = right->next;
				right->next = ptr->next;
				ptr->next = right;
				ptr = ptr->next;
				right = tmp;
				continue;
			}
			if ((left && right && left->val <= right->val) || !right) {
				tmp = left->next;
				left->next = ptr->next;
				ptr->next = left;
				ptr = ptr->next;
				left = tmp;
				continue;
			}
		}
		return dummy.next;
	}


	ListNode* sortList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *fast = head->next,  *slow = head, *left = head, *right;
		while(fast && fast->next) { fast = fast->next->next; slow = slow->next;}
		right = slow->next;
		slow->next = nullptr;
		return merge(sortList(left), sortList(right));
	}
};
