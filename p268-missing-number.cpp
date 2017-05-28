class Solution {
public:
	/*AC 20170523 2309*/
	int missingNumber(vector<int>& nums) {
		int rv;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			int idx = nums[i] % (n + 1);
			if (idx == n) continue;
			nums[idx] += n + 1;
		}

		for (int i = 0; i < n; i++) if (nums[i] < n + 1) return i;
		return n;
	}
};
