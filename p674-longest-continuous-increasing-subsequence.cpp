class Solution {
public:
	/*20171122 1020*/
	/*AC       1027*/
	int findLengthOfLCIS(vector<int>& nums) {
		int rv = 0, cnt = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (!i) {
				cnt++;
			} else {
				if (nums[i] <= nums[i - 1])
					cnt = 1;
				else
					cnt++;
			}
			rv = max(rv, cnt);
		}
		return rv;
	}
};
