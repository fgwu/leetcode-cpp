class Solution {
public:
	/*20171120 2149*/
	/*AC       2211*/
	int removeDuplicates(vector<int>& nums) {
		int i = 0, j = 0, last = -1;
		while (j < nums.size()) {
			if (last < 0 || nums[j] != nums[last]) {
				last = i;
				nums[i++] = nums[j++];
				continue;
			}

			if (i - last >= 2) {
				j++;
				continue;
			}

			nums[i++] = nums[j++];
		}
		return i;
	}
};
