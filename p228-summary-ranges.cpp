class Solution {
public:
	/*20170930 2333*/
	/*AC       2345*/
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> res;
		int left = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (i + 1 >= nums.size() || nums[i] + 1 != nums[i + 1]) {
				string s;
				if (i != left)
					s = to_string(nums[left]) + "->" + to_string(nums[i]);
				else
					s = to_string(nums[left]);
				res.push_back(s);
				left = i + 1;
			}
		}
		return res;
	}
};
