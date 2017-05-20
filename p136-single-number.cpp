class Solution {
public:
	/*20170517 17:04*/
	/*         17:15*/
	/*AC       17:25*/
	/*Note: initialize the return variable at the first time...*/
	int singleNumber(vector<int>& nums) {
		int rv = 0;
		for(const auto & n: nums){
			rv ^= n;
		}
		return rv;

	}
};
