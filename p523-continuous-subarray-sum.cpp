class Solution {
public:
	/*20171126 1537*/
	/*AC       1550*/
	bool checkSubarraySum(vector<int>& nums, int k) {
		vector<long> partial(1, 0);
		for(auto num:nums)
			partial.push_back(partial.back() + num);

		for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 2; j <= nums.size(); j++) {
				int sum = partial[j] - partial[i];
				if (!k) {
					if (!sum) return true;
					continue;
				}
				if (sum % k == 0)  return true;
			}
		}

		return false;
	}
};
