class Solution {
public:
	/*20171109 2045*/
	/*AC       2101*/
	int minSubArrayLen(int s, vector<int>& nums) {
		int rv = 0, i = 0, j = 0, sum = 0;
		while (j < nums.size()) {
			sum += nums[j++];
			if (sum < s) continue;


			while (i <= j && sum - nums[i] >= s) {
				sum -= nums[i++];
			}

			rv = rv ? min(rv, j - i) : (j - i);
		}
		return rv;
	}
};
