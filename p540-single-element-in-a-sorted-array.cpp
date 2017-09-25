class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int l = 0, r = nums.size(), mid;
		while (l != r - 1) {
			mid = l + (r - l) / 2;
			if (mid % 2) {
				if (nums[mid] == nums[mid - 1]) {
					l = mid + 1;
				} else {
					r = mid;
				}
			} else { // 1, 1, 2, 4, 4
				if (nums[mid] == nums[mid - 1]) {
					r = mid + 1;
				} else {
					l = mid;
				}
			}
		}
		return nums[l];
	}


	/*20170920 0146 rec*/
	/*AC       0216*/
	//     int helper(vector<int>& nums, int l, int r) {
	//         if (l == r - 1) return nums[l];
	//         int mid = l + (r - l) / 2;
	//         if (mid % 2) {
	//             if (nums[mid] == nums[mid - 1]) {
	//                 return helper(nums, mid + 1, r);
	//             } else {
	//                 return helper(nums, l, mid);
	//             }
	//         } else { // 1, 1, 2, 4, 4
	//             if (nums[mid] == nums[mid - 1]) {
	//                 return helper(nums, l, mid + 1);
	//             } else {
	//                 return helper(nums, mid, r);
	//             }
	//         }
	//     }

	//     int singleNonDuplicate(vector<int>& nums) {
	//         return helper(nums, 0, nums.size());
	//     }
};
