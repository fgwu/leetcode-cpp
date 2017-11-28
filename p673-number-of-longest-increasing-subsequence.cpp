class Solution {
public:
	/*20171126 1058*/
	/*AC       1124*/
	int findNumberOfLIS(vector<int>& nums) {
		if (!nums.size()) return 0;
		nums.push_back(INT_MAX);
		int n = nums.size();
		if (!n) return 0;
		vector<int> len(n);
		vector<int> cnt(n);

		for (int i = 0; i < n; i++) {
			len[i] = 1;
			cnt[i] = 1;
			for (int j = 0; j < i; j++) {
				if (nums[j] >= nums[i])
					continue;
				if (len[i] < len[j] + 1) {
					len[i] = len[j] + 1;
					cnt[i] = cnt[j];
				} else if (len[i] == len[j] + 1){
					cnt[i] += cnt[j];
				}
			}
		}
		return cnt[n - 1];
	}
};
