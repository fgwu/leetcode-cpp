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
	/*restart*/
	/*20170618 1138*/  //
	/*AC       1214*/
	void reorderList(ListNode* head) {
		if (!head) return;
		ListNode *fast = head->next, *slow = head, *righthead, *tmp, *tail;
		while (fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		righthead = slow->next;
		slow->next = nullptr;

		if (!righthead) return;

		tail = righthead;
		while(tail->next) {
			tmp = tail->next;
			tail->next = tmp->next;
			tmp->next = righthead;
			righthead = tmp;
		}
		// 1 2
		// 4 3
		fast = head;
		while(righthead) {
			// cout << fast->val << " " << righthead->val << "\n";
			tmp = righthead->next;
			righthead->next = fast->next;
			fast->next = righthead;
			fast = righthead->next;
			righthead = tmp;
			// cout << fast << " " << righthead << "\n";
		}
	}



	/*20170616 1204*/
	/*pause... I am solving another problem....*/
	// void reorderList(ListNode* head) {
	//     if (!head || !head->next) return;
	//     // split
	//     ListNode *odd = head, *evenhead = nullptr, *even = evenhead;
	//     while (odd && odd->next) {
	//         even = odd->next;
	//         odd->next = even->next;
	//         odd = odd->next;   // delete the node first
	//         even->next = evenhead;
	//         evenhead = even;
	//     }

	//     // merge
	//     odd = head;
	//     while (evenhead) {
	//         even = evenhead->next;
	//         evenhead->next = odd->next;
	//         odd->next = evenhead;
	//         cout << odd->val << odd->next->val << "\n";
	//         odd = evenhead->next;
	//         evenhead = even;
	//     }
	// }
};
