class Solution {
public:
	/*20171109 2149*/
	/*AC       2200*/
	int findMin(vector<int>& nums) {
		int l = 0, r = nums.size() - 1, mid;
		while (l < r) {
			// normal
			if (nums[l] < nums[r]) {
				return nums[l];
			} else { // rotate
				mid = l + (r - l) / 2;
				if (nums[mid] >= nums[l]) {
					l = mid + 1;
				} else {
					r = mid;
				}
			}
		}
		return nums[l];
	}
};
