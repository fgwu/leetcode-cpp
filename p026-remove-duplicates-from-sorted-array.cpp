class Solution {
public:
	/*nicer loop*/
	/*AC 20170607 1337*/
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();
		int j = 1, i = 1;
		for (; i < nums.size(); i++)
			if (nums[i] != nums[j - 1]) nums[j++] = nums[i];
		return j;
	}


	/*AC 20170607 1332*/
	// int removeDuplicates(vector<int>& nums) {
	//     if (!nums.size()) return 0;
	//     int i = 1, j = 1;
	//     while (j < nums.size()) {
	//         while (j < nums.size() && nums[j] == nums[i - 1]) j++;
	//         if (j == nums.size()) break;
	//         nums[i++] = nums[j++];
	//     }
	//     return i;
	// }
};
