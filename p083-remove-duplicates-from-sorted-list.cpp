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
	/*as the list is sorted, the map is not necessary*/
	/*AC 20170524 1504*/
	headnode.next = head;
	bool first = true;
	int prev;
	while (p->next) {
		if (first || p->next->val != prev) {
			prev = p->next->val;
			first = false;
			p = p->next;
			continue;
		}
		ListNode *tmp = p->next;
		p->next = tmp->next;
		delete tmp;
	}
	return headnode.next;
}



/*AC 20170524 1455*/
// ListNode* deleteDuplicates(ListNode* head) {
//     ListNode headnode(0), *p = &headnode;
//     headnode.next = head;
//     unordered_set<int> s;
//     while(p->next) {
//         if (!s.count(p->next->val)) {
//             s.insert(p->next->val);
//             p = p->next;
//             continue;
//         }
//         ListNode* tmp = p->next;
//         p->next = tmp->next;
//         delete tmp;
//     }
//     return headnode.next;
// }
	};
