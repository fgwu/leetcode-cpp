class Solution {
public:
	/*20170704 1355*/
	/*AC       1409*/
	void helper(string prefix, int left, int right, vector<string> & res){
		if (!left && !right) res.push_back(prefix);
		if (left < right)
			helper(prefix + ')', left, right - 1, res);
		if (left)
			helper(prefix + '(', left - 1, right, res);
	}

	vector<string> generateParenthesis(int n) {
		vector<string> res;
		string s  = "";
		helper(s, n, n, res);
		return res;
	}
};
