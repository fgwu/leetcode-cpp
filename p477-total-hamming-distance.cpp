class Solution {
public:
	/*20170523 1429*/
	/*AC       1435*/
	int totalHammingDistance(vector<int>& nums) {
		int mask, cnt, rv = 0;
		for (int i = 0; i < 32; i++) {
			mask = 1 << i;
			cnt = 0;
			for (const auto & n: nums) if (n&mask) cnt++;
			rv += cnt * (nums.size() - cnt);
		}
		return rv;
	}
};
