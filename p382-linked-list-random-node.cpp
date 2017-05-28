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
	/*20170523 1342*/
	/*AC       1425*/
	ListNode* head;
	/** @param head The linked list's head.
	    Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(ListNode* h) {
		head = h;
	}

	vector<int> selectK (ListNode* h, int k) {
		vector<int> res(k, 0);
		if (!h || k <= 0) return res;
		int cnt, i;
		ListNode* p = h;
		for (i = 0; i < k && p; i++, p = p->next) res[i] = p->val;
		if (i < k) return res;

		for (cnt = k; p; cnt++, p = p->next) {
			int r = rand()%(cnt + 1);
			if (r > 0) continue;
			r = rand()%k;
			res[r] = p->val;
		}
		return res;
	}

	/** Returns a random node's value. */
	int getRandom() {
		return selectK(head, 1)[0];
	}
};

// class Solution {
// public:
// /*20170523 1131*/
// /*AC       1145*/
//     int cnt = 0;
//     ListNode* head;
//     /** @param head The linked list's head.
//         Note that the head is guaranteed to be not null, so it contains at least one node. */
//     Solution(ListNode* h) {
//         head = h;
//         ListNode* p = head;
//         while(p) {
//             cnt++;
//             p = p->next;
//         }
//     }

//     /** Returns a random node's value. */
//     int getRandom() {
//         int r = rand()%cnt;
//         //cout << r << endl;
//         ListNode* p = head;
//         while (r--) p = p->next;
//         return p->val;
//     }
// };

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
