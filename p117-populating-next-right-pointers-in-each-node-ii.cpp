/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
	/*20171121 1553*/
	/*AC 1706*/
	void connect(TreeLinkNode *root) {
		TreeLinkNode *head = root, *nexthead, *curr, *nextcurr;

		while(head) {
			nexthead = nextcurr = nullptr;
			for (curr = head; curr; curr = curr->next){
				if (curr->left) {
					if (!nexthead)
						nexthead = nextcurr = curr->left;
					else {
						nextcurr->next = curr->left;
						nextcurr = nextcurr->next;
					}
				}
				if (curr->right) {
					if (!nexthead)
						nexthead = nextcurr = curr->right;
					else {
						nextcurr->next = curr->right;
						nextcurr = nextcurr->next;
					}
				}
			}
			head = nexthead;
		}
	}
};
