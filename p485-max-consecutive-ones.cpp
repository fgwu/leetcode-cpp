class Solution {
public:
	/*20170517 16:53*/
	/*         16:58*/
	/*AC       17:00*/
	/*Note: Loop ends, be careful with the elem left. */
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int max_cand = 0;
		int cand = 0;
		for(auto & n: nums){
			if (n == 1)
				cand++;
			else {
				max_cand = max(max_cand, cand);
				cand = 0;
			}
		}
		max_cand = max(max_cand, cand);
		return max_cand;
	}
};
