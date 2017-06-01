class Solution {
public:
	/*opt version*/
	vector<int> singleNumber(vector<int>& nums) {
		vector<int> res(2,0);
		int diff = 0;
		for (const auto & n:nums) diff ^= n;
		diff &= (-diff);
		for (const auto & n:nums) {
			if (n & diff) res[1] ^= n;
			else res[0] ^=n;
		}
		return res;
	}

	/*seen the sln, implement it*/
	/*20170601 0048*/
	/*AC       0052*/
	// vector<int> singleNumber(vector<int>& nums) {
	//     vector<int> res(2,0);
	//     int tmp = 0;
	//     for (const auto & n:nums) tmp ^= n;
	//     int mask = tmp & (tmp - 1) ^ tmp;
	//     for (const auto & n:nums) {
	//         if (n & mask) res[1] ^= n;
	//         else res[0] ^=n;
	//     }
	//     return res;
	// }


	/*20170531 2303*/
	/*AC       0046*/
	// vector<int> singleNumber(vector<int>& nums) {
	//     vector<int> res;
	//     int start = 0, end = nums.size() - 1;
	//     for (int d = 31; d >= 0; d--) {
	//         cout << "d=" << d << " start=" << start << " end=" << end;
	//         if (start == end - 1) {
	//             res.push_back(nums[start]);
	//             res.push_back(nums[end]);
	//             break;
	//         }
	//         int mask = 1 << d;
	//         int i = start, j = end, k;
	//         int set = 0, unset = 0;
	//         // loop invariant: any idx < i, unset; any idx > j, set
	//         while (i <= j) {
	//             while (i <= j && !(nums[i] & mask)) i++;
	//             if (i > j) break;
	//             while (j >= i && (nums[j] & mask)) j--;
	//             if (j < i) break;
	//             swap(nums[i++], nums[j--]);
	//         } // i (first set) > j (first unset)

	//         cout << " i=" << i << " j=" << j << "\n";

	//         cout << " unset:" ;
	//         for (k = start; k < i; k++) {
	//             unset^=nums[k];
	//             cout << " " << nums[k];
	//         }
	//         cout << " xor=" << unset << "\n";

	//         cout << " set:" ;
	//         for (k = end; k > j; k--) {
	//             set^=nums[k];
	//             cout << " " << nums[k];
	//         }
	//         cout << " xor=" << set << "\n";


	//         // if (set && unset) {
	//         if ((i - start)%2){
	//             res.push_back(set);
	//             res.push_back(unset);
	//             break;
	//         }
	//         if (set) start = i;
	//         else end = j;
	//     }
	//     return res;
	// }
};
