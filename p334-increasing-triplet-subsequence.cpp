class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		int n = nums.size();
		int seq1 = INT_MAX, seq2 = INT_MAX;
		for (int x: nums) {
			// printf("min_num=%d seq1=%d seq2=%d\n", min_num, seq1, seq2);
			if (x > seq2) return true;
			if (x > seq1) {
				seq2 = x;
				continue;
			}
			seq1 = x;
		}
		return false;
	}




	/*20170920 1624*/
	/*AC       1702*/
	// bool increasingTriplet(vector<int>& nums) {
	//     int n = nums.size();
	//     if (n < 3) return false;
	//     int seq1 = INT_MAX, seq2 = INT_MAX, i, min_num = nums[0];
	//     for (i = 1; i < n; i++) {
	//         // printf("min_num=%d seq1=%d seq2=%d\n", min_num, seq1, seq2);
	//         if (nums[i] > seq2) return true;
	//         if (nums[i] > min_num) {
	//             seq1 = min_num;
	//             seq2 = nums[i];
	//             continue;
	//         }
	//         min_num = nums[i];
	//     }
	//     return false;
	// }
};
