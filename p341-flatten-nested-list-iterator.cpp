/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
	/*20170717 1525*/
	NestedIterator(vector<NestedInteger> &nestedList) {
		int n = nestedList.size();
		if (!n) return;
		for(int i = n - 1; i >= 0; i--)
			s.push(nestedList[i]);
	}

	int next() {
		assert (hasNext() && s.top().isInteger());
		int res = s.top().getInteger();
		s.pop();
		return res;
	}

	bool hasNext() {
		while(!s.empty() && !s.top().isInteger()) {
			vector<NestedInteger> nestedList = s.top().getList();
			s.pop();
			int n = nestedList.size();
			for(int i = n - 1; i >= 0; i--)
				s.push(nestedList[i]);
		}
		return !s.empty();
	}
private:
	stack<NestedInteger> s;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
