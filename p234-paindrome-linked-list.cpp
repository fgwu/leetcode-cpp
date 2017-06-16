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
	/*with restore*/
	bool isPalindrome(ListNode* head) {
		if (!head) return true;
		ListNode *fast = head, *slow = head, *ptr, *tmp;
		while(fast->next && fast->next->next) {
			fast = fast->next->next;
			slow = slow->next;
		}

		for(ptr = slow->next, slow->next = nullptr; ptr;) {
			tmp = ptr;
			ptr = ptr->next;
			tmp->next = slow->next;
			slow->next = tmp;
		}

		bool res = true;
		for(ptr = slow->next, slow->next = nullptr; ptr; head = head->next) {
			cout << slow->val << " " << head->val << "\n";
			if (res && ptr->val != head->val) res = false;
			tmp = ptr;
			ptr = ptr->next;
			tmp->next = slow->next;
			slow->next = tmp;
		}

		return res;
	}






	/*Now O(1) space*/
	/*AC   201706015 1721*/
	// bool isPalindrome(ListNode* head) {
	//     if (!head) return true;
	//     ListNode *fast = head, *slow = head, *ptr, *tmp;
	//     while(fast->next && fast->next->next) {
	//         fast = fast->next->next;
	//         slow = slow->next;
	//     }

	//     for(ptr = slow->next, slow->next = nullptr; ptr;) {
	//         tmp = ptr;
	//         ptr = ptr->next;
	//         tmp->next = slow->next;
	//         slow->next = tmp;
	//     }

	//     for(slow = slow->next; slow; slow = slow->next, head = head->next) {
	//         cout << slow->val << " " << head->val << "\n";
	//         if (slow->val != head->val) return false;
	//     }

	//     return true;
	// }


	/*20170615 1639*/
	/*AC       1642*/
	// bool isPalindrome(ListNode* head) {
	//     vector<int> vec;
	//     for(; head; head=head->next) vec.push_back(head->val);
	//     for(int i = 0; i < vec.size()/2; i++) if (vec[i] != vec[vec.size() - 1 - i]) return false;
	//     return true;
	// }
};
