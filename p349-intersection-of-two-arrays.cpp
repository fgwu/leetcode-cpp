class Solution {
public:
	/*20170519 22:37*/
	/*         22:44*/
	/*AC       22:45 bug free*/
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int>map;
		vector<int> rv;
		for (const auto & n:nums1) map[n] = 0;
		for (const auto & n:nums2){
			if (map.find(n) != map.end()) {
				if (map[n]) continue;
				rv.push_back(n);
				map[n] = 1;
			}
		}
		return rv;
	}
};
