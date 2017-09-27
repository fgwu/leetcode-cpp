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
	/*AC 1955 iterative*/
	ListNode* swapPairs(ListNode* head) {
		ListNode dummy(0);
		dummy.next = head;
		ListNode* pre = &dummy;
		while(head && head->next){
			ListNode* second = head->next;
			head->next = second->next;
			second->next = head;
			pre->next = second;
			pre = pre->next->next;
			head = pre->next;
		}
		return dummy.next;
	}


	/*20170925 1940*/
	/*AC       1946*/
	// ListNode* swapPairs(ListNode* head) {
	//     if (!head) return head;
	//     if (!head->next) return head;
	//     ListNode* second = head->next;
	//     second->next = swapPairs(second->next);
	//     head->next = second->next;
	//     second->next = head;
	//     return second;
	// }
};
