class Solution {
public:
	/* all elem before low are 0's. all elem after hi are 2's.
	   index i is among a lot of 1's. encounter 0 or 2, swap accordingly. */
	void sortColors(vector<int>& nums) {
		int n = nums.size();
		for (int lo = 0, hi = n - 1, i = lo; i <= hi; ) {
			switch (nums[i]) {
			case 0:
				swap(nums[i++], nums[lo++]);
				break;
			case 1:
				i++;
				break;
			case 2:
				swap(nums[i], nums[hi--]);
			}
		}
	}

	/* one pass, const space */
	// learn lomuto partition.
	// void sortColors(vector<int>& nums) {
	//     for (int i = 0, j = 0, k = 0; k < nums.size(); k++) {
	//         if (nums[k] == 2) continue;
	//         if (nums[k] == 1) {
	//             nums[k] = 2;
	//             nums[j++] = 1;
	//         } else {
	//             nums[k] = 2;
	//             nums[j++] = 1;
	//             nums[i++] = 0;
	//         }
	//     }
	// }

	/*20170724 1521*/
	/*AC       1525*/
	// void sortColors(vector<int>& nums) {
	//     vector<int> cnt(3, 0);
	//     for (auto num: nums) cnt[num]++;
	//     int i = 0;
	//     while (cnt[0]--) nums[i++] = 0;
	//     while (cnt[1]--) nums[i++] = 1;
	//     while (cnt[2]--) nums[i++] = 2;
	// }
};
