class Solution {
public:
	/* clean binary search */
	int findPeakElement(vector<int>& nums) {
		assert(nums.size());
		int lo = 0, hi = nums.size() - 1;
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if (nums[mid] > nums[mid + 1])
				hi = mid;
			else
				lo = mid + 1;
		}
		return lo;
	}

	/*logarithmic AC 1234*/
	// int findPeakElement(vector<int>& nums) {
	//     assert(nums.size());
	//     int lo = 0, hi = nums.size() - 1;
	//     while(lo <= hi) {
	//         int mid = lo + (hi - lo) / 2;
	//         bool left = (mid == 0 || nums[mid] >= nums[mid - 1]);
	//         bool right = (mid == nums.size() - 1 || nums[mid] >= nums[mid + 1]);
	//         if (left && right) return mid;
	//         if (left)
	//             lo = mid + 1;
	//         else
	//             hi = mid - 1;
	//     }
	//     return lo;
	// }

	/*20170725 1205*/
	/*AC       1223 naive bruteforce*/
	// int findPeakElement(vector<int>& nums) {
	//     nums.push_back(INT_MIN);
	//     nums.insert(nums.begin(), INT_MIN);
	//     printf("%d\n", INT_MIN);
	//     for (int i = 0; i + 2 < nums.size(); i++) {
	//         if (nums[i] <= nums[i + 1] && nums[i + 1] >= nums[i + 2]) return i;
	//     }
	//     return -1;
	// }
};
