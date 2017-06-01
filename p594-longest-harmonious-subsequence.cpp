class Solution {
public:
	/*AC 20170529 2312*/
	int findLHS(vector<int>& nums) {
		unordered_map<int, int>m;
		int res = 0;
		for (const auto & n:nums) m[n]++;
		for (const auto & p:m)
			if (m.find(p.first + 1) != m.end())
				res = max(res, m[p.first + 1] + p.second);
		return res;
	}
};
