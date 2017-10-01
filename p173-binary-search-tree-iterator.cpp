/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
	/*20170930 2238*/
	/*AC       2326*/
	stack<TreeNode*> s;
	TreeNode* nextptr;

	BSTIterator(TreeNode *root) {
		s.push(root);
		nextptr = nullptr;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		if (s.empty()) return false;
		TreeNode *curr = s.top();
		s.pop();
		if (!curr) return hasNext();
		if (!s.empty() && s.top() == curr->right) {
			nextptr = curr;
			return true;
		}
		s.push(curr->right);
		s.push(curr);
		s.push(curr->left);
		return hasNext();
	}

	/** @return the next smallest number */
	int next() {
		if (!nextptr && !hasNext()) return -1;
		return nextptr->val;
	}
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
