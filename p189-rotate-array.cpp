class Solution {
public:


	void rotate(vector<int>& nums, int k) {
		if (nums.size() <= 1) return;
		k %= nums.size();
		for (int i = 0; i < nums.size() - 1 - i; i++) swap(nums[i], nums[nums.size() - 1 - i]);
		for (int i = 0; i < k - 1 - i; i++) swap(nums[i], nums[k - 1 - i]);
		for (int i = k; i < nums.size() + k - 1 - i; i++) swap(nums[i], nums[nums.size() + k - 1 - i]);
	}

	// void rotate(vector<int>& nums, int k) {
	//     if (!k || nums.size() <= 1) return;
	//     k %= nums.size();
	//     int n = nums.size();
	//     for (int i = 0; i < n - k; i++)
	//         nums.push_back(nums[i]);
	//     nums.erase(nums.begin(), nums.begin() + n - k);
	// }

	/*20170628 1528*/
	// void rotate(vector<int>& nums, int k) {
	//     if (!k || nums.size() <= 1) return;
	//     for (int i = 0; i < k % nums.size(); i++) {
	//         int tmp = nums.back();
	//         nums.pop_back();
	//         nums.insert(nums.begin(), tmp);
	//     }
	// }

	/*20170628 1235*/
	// void rotate(vector<int>& nums, int k) {
	//     if (!k || nums.size() <= 1) return;
	//     vector<int> tmp(nums);
	//     int n = nums.size();
	//     k %= n;
	//     for (int i = 0; i < n; i++)
	//         nums[i] = tmp[(i - k) >= 0? (i - k) : (i - k + n)];
	// }
};
