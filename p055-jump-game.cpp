class Solution {
public:
	/*greedy   1507*/
	/*AC       1518*/
	bool canJump(vector<int>& nums) {
		if (!nums.size()) return false;
		for (int i = 0, boundary = 0; i <= boundary && i < nums.size(); i++) {
			if (boundary >= nums.size() - 1) return true;
			boundary = max(boundary, i + nums[i]);
		}
		return false;

	}

	/*20170810 1450*/
	/*TLE      1505*/
	// bool canJump(vector<int>& nums) {
	//     if (!nums.size()) return false;
	//     vector<bool> dp(nums.size(), false);
	//     dp[0] = true;
	//     for(int i = 0; i < nums.size(); i++) {
	//         if (!dp[i]) continue;
	//         for(int step = 1; i + step < nums.size() && step <= nums[i]; step++) {
	//             dp[i + step] = true;
	//             if (i + step == nums.size() - 1) return true;
	//         }
	//     }
	//     return dp[nums.size() - 1];
	// }
};
