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
	/*more concise solusion*/
	/*AC 1757*/
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *pa, *pb;
		for (pa = headA, pb = headB; pa != pb; pa = pa?pa->next: headB, pb = pb? pb->next: headA);
		return pa;
	}

	/*20170523 1109*/
	/*20170614 2347*/
	/*20170615 1733*/
	/*AC       1748*/
	// ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	//     ListNode *pa, *pb;
	//     for(pa = headA, pb = headB; pa && pb; pa = pa->next, pb = pb->next);

	//     if (pa) for(;pa; headA = headA->next, pa = pa->next);
	//     else for(;pb; headB = headB->next, pb = pb->next);

	//     for (; headA && headB; headA = headA->next, headB = headB->next)
	//         if (headA == headB) return headA;
	//     return nullptr;
	// }
};
