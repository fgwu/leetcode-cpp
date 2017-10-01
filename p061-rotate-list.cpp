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
	/*20170929 2209*/
	/*AC       2225*/
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head) return head;
		ListNode *fast = head, *slow = head;

		int cnt = 0;

		while(k--) {
			if (!fast) {
				fast = head;
				k %= cnt;
			}
			fast = fast->next;
			cnt++;
		}

		if (!fast) return head; // no rotation

		while(fast->next) {
			slow = slow->next;
			fast = fast->next;
		}

		fast->next = head;
		head = slow->next;
		slow->next = nullptr;

		return head;
	}
};
