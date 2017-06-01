class Solution {
public:
	/*further optimization*/
	int rob(vector<int>& nums) {
		int a = 0, b = 0;
		for (int i = 0; i < nums.size(); i++) {
			int tmp = max(b, a + nums[i]);
			a = b;
			b = tmp;
		}
		return b;
	}


	/*seen solution, try O(1) space*/
	/*AC 1434*/
	// int rob(vector<int>& nums) {
	//     if (nums.size() == 0) return 0;
	//     if (nums.size() == 1) return nums[0];
	//     if (nums.size() == 2) return max(nums[0], nums[1]);
	//     int a = nums[0], b = max(nums[0], nums[1]);
	//     for (int i = 2; i < nums.size(); i++) {
	//         int tmp = max(b, nums[i] + a);
	//         a = b;
	//         b = tmp;
	//     }
	//     return b;
	// }


	/*AC 20170530 1428*/
	// int rob(vector<int>& nums) {
	//     if (nums.size() == 0) return 0;
	//     if (nums.size() == 1) return nums[0];
	//     if (nums.size() == 2) return max(nums[0], nums[1]);
	//     vector<int> v(nums.size(), 0);
	//     v[0] = nums[0];
	//     v[1] = max(nums[0], nums[1]);
	//     for (int i = 2; i < v.size(); i++) v[i] = max(nums[i] + v[i - 2], v[i - 1]);
	//     return v[v.size() - 1];
	// }
};
