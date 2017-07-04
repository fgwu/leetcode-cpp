class Solution {
public:
	/*20170703 1327 loop in linked list per solution */
	/*AC       1331*/
	int findDuplicate(vector<int>& nums) {
		int slow = 0, fast = 0;
		while(!fast || fast != slow){
			fast = nums[nums[fast]];
			slow = nums[slow];
		}

		fast = 0;
		while(fast != slow) {
			fast = nums[fast];
			slow = nums[slow];
		}

		return fast;
	}

	/*20170702 1100*/
	/*20170703 1251 restart*/
	/*AC       1318*/
	// int findDuplicate(vector<int>& nums) {
	//     int res, hi = nums.size() - 1, lo = 1;
	//     // loop invariant: target within [lo, hi) inclusive
	//     while (lo < hi) {
	//         int mid = lo + (hi - lo) / 2;
	//         int cnt = 0;
	//         for (const auto n: nums)
	//             if (n >= lo && n <= mid ) cnt++;
	//         printf("[%d, %d, %d], cnt=%d\n", lo, mid, hi, cnt);
	//         if (cnt > mid - lo + 1)
	//             hi = mid;
	//         else
	//             lo = mid + 1;
	//     }
	//     return lo;
	// }
};
