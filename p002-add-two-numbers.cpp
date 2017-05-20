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
	/*20170519 15:34 seen optimal sol, restart */
	/*         15:40*/
	/*AC       15:41*/
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode head(0), *p = &head;
		int n1, n2;
		for (int carry = 0; l1||l2||carry; l1 = l1?l1->next:l1, l2 = l2?l2->next:l2){
			n1 = l1?l1->val:0;
			n2 = l2?l2->val:0;
			p->next = new ListNode((n1 + n2 + carry)%10);
			p = p->next;
			carry = (n1 + n2 + carry)/10;
		}
		return head.next;
	}


	/*20170519 14:52*/
	/*20170519 15:04*/
	/*         15:14 read the problem wrong. try again*/
	/*         15:27*/
	/*AC       15:29*/
	/*Note: 1)pointer declarition must all with *
	 *      2) for loop next action must be safe.
	 */
	// ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	//     ListNode* rv = NULL, *p1, *p2, *tmp;
	//     int carry = 0, n1, n2;
	//     stack<int> s;
	//     for (p1 = l1, p2 = l2, carry = 0; p1 || p2 || carry; p1 = p1? p1->next:NULL, p2 = p2? p2->next:NULL){
	//         n1 = p1? p1->val: 0;
	//         n2 = p2? p2->val: 0;
	//         s.push((n1 + n2 + carry)%10);
	//         carry = (n1 + n2 + carry)/10;
	//     }
	//     while (!s.empty()) {
	//         tmp = new ListNode(s.top());
	//         tmp->next = rv;
	//         rv = tmp;
	//         s.pop();
	//     }
	//     return rv;
	// }
};
