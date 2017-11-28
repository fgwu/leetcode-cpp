class Solution {
public:
	/*20171122 0705*/
	/*AC       0715*/
	int combinationSum4(vector<int>& nums, int target) {
		vector<int> memo(target + 1, 0);
		for (int i = 0; i <= target; i++) {
			if (!i) memo[i] = 1;
			for (auto e: nums)
				if (i - e >= 0) memo[i] += memo[i - e];
		}

		return memo[target];
	}
};


// 1,2,3  4
// 0 1 2 3 4
// 1 1 2 4 7
