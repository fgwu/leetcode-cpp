class Solution {
public:
	/*20170518 15:35*/
	/*         15:48*/
	/*AC       15:51*/
	void moveZeroes(vector<int>& nums) {
		int i = 0, j = 0;
		while (i<nums.size() && nums[i]) i++;
		if (i == nums.size()) return;
		j = i + 1;
		while (1){
			while (j < nums.size() && !nums[j] ) j++;
			if (j==nums.size()) break;
			nums[i++] = nums[j++];
		}
		while(i < nums.size()) nums[i++] = 0;
		return;
	}
};
