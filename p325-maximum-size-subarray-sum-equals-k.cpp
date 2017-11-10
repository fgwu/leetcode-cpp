class Solution {
public:
	/*20171109 1142*/
	/*AC       1555*/
	int maxSubArrayLen(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		int rv = 0;
		m[0] = -1;
		for(int i = 0, sum = 0; i < nums.size(); i++) {
			sum += nums[i];
			if (m.count(sum - k))
				rv = max(rv, i - m[sum - k]);

			if (!m.count(sum))
				m[sum] = i;
		}
		return rv;
	}
};
