class Solution {
public:
	/*20170920 1206 second pass*/
	vector<vector<int>> permute(vector<int>& nums) {
		queue<vector<int>> q;
		q.push(nums);
		for (int i = 0; i < nums.size(); i++) {
			int N = q.size();
			for (int k = 0; k < N; k++) {
				vector<int> tmp = q.front();
				q.pop();
				for (int j = i; j < nums.size(); j++) {
					swap(tmp[i], tmp[j]);
					q.push(tmp);
					swap(tmp[i], tmp[j]);
				}
			}
		}
		vector<vector<int>> res;
		while(!q.empty()) {
			res.push_back(q.front());
			q.pop();
		}
		return res;
	}


	/*FIFO iterative, BFS, like p017*/
	/*20170803 1348*/
	/*AC       1359*/
	// vector<vector<int>> permute(vector<int>& nums) {
	//     vector<vector<int>> res;
	//     if (!nums.size()) return res;
	//     res.push_back(vector<int>());
	//     for (int n: nums) {
	//         vector<vector<int>> tmpres;
	//         for (auto& v: res) {
	//             for (int i = 0; i <= v.size(); i++ ) {
	//                 tmpres.push_back(v);
	//                 tmpres.back().push_back(n);
	//                 swap(tmpres.back().back(), tmpres.back()[i]);
	//             }
	//         }
	//         swap(res, tmpres);
	//     }
	//     return res;
	// }


	/* iterative backtracking */
	/* FAILED SOLUTION.......*/
	// vector<vector<int>> permute(vector<int>& nums) {
	//     int from = 0, to = 0, s = nums.size();
	//     int empty = 1 + *max_elememt(nums.begin(), nums.end());
	//     vector<vector<int>> res;
	//     vector<int>tmp(s, empty);
	//     while(true) {
	//         if (from >= nums.size()) break;
	//         if (to >= nums.size()) {
	//             from++;
	//             to = 0;
	//             continue;
	//         }
	//         if (tmp[to] != empty) {
	//             to++;
	//             continue;
	//         }
	//         tmp[to] = nums[from]; // go one more level;
	//     }
	// }

	/*20170705 1553*/
	/*AC       1615*/
	//     void helper(vector<vector<int>>& res, vector<int>& nums, int start, vector<int>& tmp){
	//         if (start >= nums.size()) res.push_back(tmp);
	//         int empty = *max_element(nums.begin(), nums.end()) + 1;
	//         for (int i = 0; i < tmp.size(); i++) {
	//             if (tmp[i] != empty) continue;
	//             tmp[i] = nums[start];
	//             helper(res, nums, start + 1, tmp);
	//             tmp[i] = empty;
	//         }
	//     }

	//     vector<vector<int>> permute(vector<int>& nums) {
	//         vector<vector<int>> res;
	//         int empty = *max_element(nums.begin(), nums.end()) + 1;
	//         vector<int> tmp(nums.size(), empty);
	//         helper(res, nums, 0, tmp);
	//         return res;
	//     }
};
