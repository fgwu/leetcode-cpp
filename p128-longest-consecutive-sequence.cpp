class Solution {
public:
	/*SQ*/
	/*20170907 2353*/
	int longestConsecutive(vector<int>& nums) {
		unordered_map<int, int> m;
		int res = 0;
		for (int i: nums) {
			if (m[i]) continue;
			res = max(res, m[i] = m[i - m[i - 1]] = m[i + m[i + 1]] = m[i - 1] + 1 + m[i + 1]);
		}
		return res;
	}

	/*20170906 2305*/
	/*AC  0907 2345*/
	//     int longestConsecutive(vector<int>& nums) {
	//         unordered_map<int, pair<int, int>> begin_map;
	//         unordered_map<int, pair<int, int>> end_map;

	//         int res = 0;

	//         for (auto & n: nums) {
	//             pair<int, int> p;
	//             if (begin_map.count(n + 1) && end_map.count(n - 1)) {
	//                 p =  make_pair(end_map[n - 1].first, begin_map[n + 1].second);
	//                 begin_map.erase(n + 1);
	//                 end_map.erase(n - 1);

	//             } else if (begin_map.count(n + 1)) {
	//                 p = make_pair(n, begin_map[n + 1].second);
	//                 begin_map.erase(n + 1);
	//                 end_map.erase(p.second);
	//             } else if (end_map.count(n - 1)) {
	//                 p = make_pair(end_map[n - 1].first, n);
	//                 end_map.erase(n - 1);
	//                 begin_map.erase(p.first);
	//             } else {
	//                 p = make_pair(n, n);
	//             }

	//             int len = p.second - p.first + 1;

	//             if (begin_map.count(p.first) && begin_map[p.first].second - begin_map[p.first].first >= len ||
	//                end_map.count(p.second) && end_map[p.second].second - end_map[p.second].first >= len)
	//                 continue;

	//             begin_map[p.first] = p;
	//             end_map[p.second] = p;

	//             res = max(res, len);
	//         }

	//         return res;
	//     }
};
