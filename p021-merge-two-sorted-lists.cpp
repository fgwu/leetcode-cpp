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
	/*rec version*/
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1) return l2;
		if (!l2) return l1;
		if (l1->val < l2->val) {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		l2->next = mergeTwoLists(l2->next, l1);
		return l2;
	}


	/*clean version */
	// ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	//     ListNode headnode(0), *l = &headnode;
	//     while(l1 && l2) {
	//         if (l1 -> val < l2 -> val) {
	//             l->next = l1;
	//             l1 = l1->next;
	//         } else {
	//             l->next = l2;
	//             l2 = l2->next;
	//         }
	//         l = l->next;
	//     }
	//     l->next = l1? l1: l2;
	//     return headnode.next;
	// }


	/*20170529 0016*/
	/*AC       0029*/
	// ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	//     ListNode headnode(0), *p1 = l1, *p2 = l2, *p = &headnode;
	//     for (; p1 || p2; p = p->next, p->next = nullptr) {
	//         if (p1 && p2) {
	//             if (p1->val < p2->val) {
	//                 p->next = p1;
	//                 p1 = p1->next;
	//             } else {
	//                 p->next = p2;
	//                 p2 = p2->next;
	//             }
	//             continue;
	//         }

	//         if (p1) {
	//             p->next = p1; break;
	//         }

	//         p->next = p2; break;
	//     }
	//     return headnode.next;
	// }
};
