/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	/*20170615 1914*/
	/*AC       1929*/
	TreeNode* sortedListToBST(ListNode* head) {
		if (!head) return nullptr;
		if (!head->next) return new TreeNode(head->val);;
		ListNode *fast = head, *slow = head;
		while(fast && fast->next && fast->next->next && fast->next->next->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		TreeNode* root = new TreeNode(slow->next->val);
		root->right =  sortedListToBST(slow->next->next);
		delete slow->next;
		slow->next = nullptr;
		root->left = sortedListToBST(head);
		return root;
	}
};
