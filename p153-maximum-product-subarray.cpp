class Solution {
public:
	/*20171109 2201*/
	/*AC       2227*/
	int maxProduct(vector<int>& nums) {
		int rv = INT_MIN, neg = 1, tmp = 1;
		for (int i = 0; i < nums.size(); i++) {
			tmp *= nums[i];
			rv = max(rv, tmp);

			if (!tmp) {
				neg = 1, tmp = 1;
				continue;
			}

			if (tmp > 0)
				continue;

			if (neg < 0)
				rv = max(rv, tmp / neg);
			else
				neg = tmp;
		}

		return rv;
	}
};
