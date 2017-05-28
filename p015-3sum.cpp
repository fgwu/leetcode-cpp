class Solution {
public:
	/* 3rd try */
	/*20170525 1950*/
	/*AC       2027*/
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		int n = nums.size();
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n; ) {
			int j = i + 1;
			int k = n - 1;
			while (j < k) {
				// cout << "[" << i << "]=" << nums[i] << " [" << j << "]="<< nums[j] << " [" << k << "]=" << nums[k] << "\n";
				if (nums[j] + nums[k] > - nums[i]) { k--; continue; }
				if (nums[j] + nums[k] < - nums[i]) { j++; continue; }
				vector<int> tmp = {nums[i], nums[j], nums[k]};
				// cout << "push\n";
				res.push_back(tmp);
				do j++; while (j + 1 < k && nums[j] == nums[j - 1]);
				do k--; while (k - 1 > j && nums[k] == nums[k + 1]);
				continue;
			}
			do i++; while (i + 1 < n && nums[i] == nums[i - 1]);
		}
		return res;
	}
	/* time exceeded again.  */
	//     vector<vector<int>> threeSum(vector<int>& nums) {
	//         vector<vector<int>> res;
	//         set<vector<int>> tri_set;
	//         if (nums.size() < 3) return res;
	//         unordered_map<int, vector<pair<int, int>>> m;
	//         for (int i = 0; i < nums.size() - 1; i++)
	//             for (int j = i + 1; j < nums.size(); j++)
	//                 m[nums[i] + nums[j]].push_back(make_pair(i, j));
	//         for (int i = 0; i < nums.size(); i++) {
	//             if (!m.count(-nums[i])) continue;
	//             for (const auto & p: m[-nums[i]]) {
	// //                cout << nums[p.first] << " " <<  nums[p.second] << " " << nums[i] << "\n";
	//                 if (i == p.first || i == p.second) continue;
	//                 if ( nums[i] < nums[p.first] || nums[i] < nums[p.second]) continue;
	//                 vector<int> v = { min(nums[p.first], nums[p.second]),
	//                     max(nums[p.first], nums[p.second]),
	//                     nums[i]};
	//                 if (tri_set.count(v)) continue;
	//                 tri_set.insert(v);
	// //                cout << "push\n";
	//                 res.push_back(v);
	//             }
	//         }
	//         return res;
	//     }


	/* time exceeded..*/
	// vector<vector<int>> threeSum(vector<int>& nums) {
	//     vector<vector<int>> res;
	//     if (nums.size() < 3) return res;
	//     set<vector<int>> tri_set;
	//     sort(nums.begin(), nums.end());
	//     for (int i = 0; i < nums.size() - 2; i++)
	//     for (int j = i + 1; j < nums.size() - 1; j++)
	//     for (int k = j + 1; k < nums.size(); k++) {
	//         if (nums[i] + nums[j] + nums[k] ) continue;
	//         vector<int> tmp = {nums[i],  nums[j], nums[k]};
	//         tri_set.insert(tmp);
	//     }
	//     for (const auto & v: tri_set) res.push_back(v);
	//     return res;
	// }
};
