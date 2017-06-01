class Solution {
public:
	/*20170530 1732*/
	int removeElement(vector<int>& nums, int val) {
		int i,j;
		for (i = 0, j = nums.size() - 1; i <= j; ) {
			while (i < nums.size() && nums[i] != val) i++;
			if (i == nums.size()) break;
			while (j >= 0 && nums[j] == val) j--;
			if (j == 0) break;
			if (i > j) break;
			swap(nums[i++], nums[j--]);
		}

		return i;
	}
};
