class Solution {
public:
	/*itr version */
	/*AC 20170526 2300*/
	int searchInsert(vector<int>& nums, int target) {
		int left = 0, right = nums.size();
		while(left < right) {
			int mid = (left + right) / 2;
			if (nums[mid] == target) return mid;
			if (nums[mid] > target)
				right = mid;
			else
				left = mid + 1;
		}
		return left;
	}



	/*AC 20170526 2254*/
	// int helper(vector<int>& nums, int left, int right, int target) {
	//     if (left == right) return left;
	//     int middle = (left + right) / 2;
	//     if (nums[middle] == target) return middle;
	//     if (nums[middle] > target) return helper(nums, left, middle, target);
	//     return helper(nums, middle + 1, right, target);
	// }
	// int searchInsert(vector<int>& nums, int target) {
	//     if (!nums.size()) return 0;
	//     return helper(nums, 0, nums.size(), target);
	// }
};
