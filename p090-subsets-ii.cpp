class Solution {
public:
	/*AC 2134*/
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		res.reserve(1 << nums.size());
		res.push_back(vector<int>());
		int len = 1;
		for(int i = 0; i < nums.size(); i++) {
			if (!i || nums[i] != nums[i - 1])
				len = res.size();
			int N = res.size();
			for(int j = N - len; j < N; j++) {
				res.push_back(res[j]);
				res.back().push_back(nums[i]);
			}
		}
		return res;
	}


	/*AC 2125*/
	//     void helper(vector<int>& nums, int idx, vector<int>& partial,
	//                 vector<vector<int>>& res){
	//         if (idx >= nums.size()) {
	//             res.push_back(partial);
	//             return;
	//         }
	//         int cnt = 1;
	//         while(idx + cnt < nums.size() && nums[idx + cnt] == nums[idx])
	//             cnt++;

	//         helper(nums, idx + cnt, partial, res);
	//         for (int i = 0; i < cnt; i++) {
	//             partial.push_back(nums[idx]);
	//             helper(nums, idx + cnt, partial, res);
	//         }

	//         for (int i = 0; i < cnt; i++) partial.pop_back();
	//     }

	//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	//         sort(nums.begin(), nums.end());
	//         vector<vector<int>> res;
	//         vector<int> partial;
	//         helper(nums, 0, partial, res);
	//         return res;
	//     }


	/*20170926 2049*/
	/*AC       2117*/
	//     void helper(vector<int>& nums, int idx, vector<int>& partial,
	//                 vector<vector<int>>& res){
	//         if (idx >= nums.size()) {
	//             res.push_back(partial);
	//             return;
	//         }
	//         int cnt = 1;
	//         while(idx + cnt < nums.size() && nums[idx + cnt] == nums[idx])
	//             cnt++;

	//         for (int i = 0; i <= cnt; i++, partial.push_back(nums[idx])) {
	//             helper(nums, idx + cnt, partial, res);
	//         }

	//         for (int i = 0; i <= cnt; i++) partial.pop_back();
	//     }

	//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	//         sort(nums.begin(), nums.end());
	//         vector<vector<int>> res;
	//         vector<int> partial;
	//         helper(nums, 0, partial, res);
	//         return res;
	//     }
};
