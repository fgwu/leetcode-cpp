class Solution {
public:
	/*20170921 0028*/
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		set<vector<int>> s;
		s.insert(nums);
		for (int i = 0; i < nums.size(); i++) {
			set<vector<int>> tmps;
			for (auto v: s) {
				for (int j = i; j < nums.size(); j++) {
					swap(v[i], v[j]);
					tmps.insert(v);
					swap(v[i], v[j]);
				}
			}
			swap(tmps, s);
		}
		vector<vector<int>> res;
		for (auto & v: s)
			res.push_back(v);
		return res;
	}
};
