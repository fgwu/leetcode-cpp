class Solution {
public:
	/*20170519 22:31*/
	/*         22:36*/
	/*AC       22:36 bug free*/
	int minMoves(vector<int>& nums) {
		int minNum = INT_MAX, rv = 0;
		for (const auto & n: nums) minNum = min(minNum, n);
		for (const auto & n: nums) rv += (n - minNum);
		return rv;
	}
};
