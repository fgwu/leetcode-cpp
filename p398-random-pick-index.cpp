class Solution {
	vector<int> nums;
public:
	Solution(vector<int> nums) {
		swap(this->nums, nums);
	}

	int pick(int target) {
		int cnt = 0;
		int idx;
		for (int i = 0; i < nums.size(); i++){
			if (nums[i] != target) continue;
			if (!cnt) {
				cnt = 1;
				idx = i;
				continue;
			}
			if (!(rand() % ++cnt))
				idx = i;
		}
		return idx;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
