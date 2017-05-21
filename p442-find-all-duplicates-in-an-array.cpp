class Solution {
public:
	/*20160521 0016*/
	/*         0024*/
	/*         0026*/
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> rv;
		int i, n = nums.size();
		for (i = 0; i < n; i++) nums[(nums[i] - 1) % n]+=n;
		for (i = 0; i < n; i++) if (nums[i] > (2 * n)) rv.push_back(i + 1);
		return rv;
	}
};
