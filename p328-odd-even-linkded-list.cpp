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
	/*3rd, learn from sln*/
	/*AC  1116*/
	ListNode* oddEvenList(ListNode* head) {
		if (!head) return head;
		ListNode *odd = head, *evenhead = head->next, *even = evenhead;
		// odd points to last odd node, even points to last even node
		// even->next is the first unprocessed node.
		while (even && even->next) {
			odd->next = odd->next->next;
			even->next = even->next->next;
			odd = odd->next;
			even = even->next;
		}
		odd->next = evenhead;
		return head;
	}

	/*more practice. try use head as the oddlist*/
	/*AC  1103*/
	// ListNode* oddEvenList(ListNode* head) {
	//     ListNode ehead(0), *even = &ehead, *ptr = head, *tmp;
	//     while (ptr && ptr->next) {
	//         tmp = ptr->next;
	//         ptr->next = tmp->next;
	//         tmp->next = even->next;
	//         even->next = tmp;
	//         even = even->next;
	//         if (ptr->next) ptr = ptr->next;
	//     }
	//     if (ptr) ptr->next = ehead.next;
	//     return head;
	// }

	/*20170616 1022*/
	/*         1033*/
	/*AC       1043*/
	// ListNode* oddEvenList(ListNode* head) {
	//     int cnt = 1;
	//     ListNode oddhead(0), evenhead(0), *odd = &oddhead, *even = &evenhead, *tmp;
	//     while (head) {
	//         tmp = head->next;
	//         if (cnt++%2) {
	//             head->next = odd->next;
	//             odd->next = head;
	//             odd = odd->next;
	//         } else {
	//             head->next = even->next;
	//             even->next = head;
	//             even = even->next;
	//         }
	//         head = tmp;
	//     }
	//     odd->next = evenhead.next;
	//     return oddhead.next;
	// }
};
