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
	/*20171118 1705*/
	/*AC       1724*/
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode dummy(0), *last = &dummy;

		auto cmp = [](const ListNode* pa, const ListNode* pb){return pa->val > pb->val;};
		priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
		for (auto & p: lists)
			if(p) pq.push(p);

		while(!pq.empty()) {
			ListNode* p = pq.top();
			pq.pop();
			if (p->next) pq.push(p->next);
			last->next = p;
			last = last->next;
			last->next = nullptr;
		}

		return dummy.next;
	}
};
