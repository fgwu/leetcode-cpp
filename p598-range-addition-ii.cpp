class Solution {
public:
	/*20170713 Thu 1257*/
	/*AC           1304*/
	int maxCount(int m, int n, vector<vector<int>>& ops) {
		for (const auto v:ops) {
			m = min(m, v[0]);
			n = min(n, v[1]);
		}
		return m * n;
	}
};
