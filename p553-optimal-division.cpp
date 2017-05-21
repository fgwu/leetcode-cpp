class Solution {
public:
	/*20170520 1502*/
	/*         1513*/
	/*AC       1513 bug free*/
	string optimalDivision(vector<int>& nums) {
		string s = "";
		if (!nums.size()) return s;
		s += to_string(nums[0]);
		if (nums.size() == 1) return s;
		s += "/";
		if (nums.size() == 2) return s + to_string(nums[1]);
		s += "(" + to_string(nums[1]);
		for (int i = 2; i < nums.size(); i++){
			s += "/" + to_string(nums[i]);
		}

		s += ")";
		return s;
	}
};
