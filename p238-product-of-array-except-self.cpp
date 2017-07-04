class Solution {
public:
	/*20170701 1219 AC*/
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> res(nums.size(), 1);
		int pre = 1, post = 1;
		for (int i = 0; i < nums.size(); i++) {
			res[i] *= pre;
			res[nums.size() - i - 1] *= post;
			pre *= nums[i];
			post *= nums[nums.size() - 1 - i];
			//printf("pre=%d, post=%d, res[%d]=%d, res[%d]=%d\n",
			//      pre, post, i, res[i],
			//       nums.size() - 1 - i, res[nums.size() - 1 - i]);
		}
		return res;
	}
};
