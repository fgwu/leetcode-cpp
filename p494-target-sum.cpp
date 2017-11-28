class Solution {
public:
	/*20171125 0754*/
	/*AC       0803*/
	int findTargetSumWays(vector<int>& nums, int S) {
		unordered_map<int, int> m; // sum, cnt;
		m[0] = 1;
		for (int e: nums) {
			unordered_map<int, int> next;
			for(auto &p: m) {
				int sum = p.first;
				int cnt = p.second;
				if (!next.count(sum + e))
					next[sum + e] = 0;
				next[sum + e] += cnt;
				if (!next.count(sum - e))
					next[sum - e] = 0;
				next[sum - e] += cnt;
			}
			swap(next, m);
		}
		if (m.count(S)) return m[S];
		return 0;
	}
};
