class Solution {
public:
	/*20170521 2259*/
	/*AC       2315*/
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> freq;
		vector<int> res;
		vector<unordered_set<int>> bucket(nums.size() + 1);
		for (const auto & n: nums) freq[n]++;
		for (const auto & entry:freq) {
			int cnt = entry.second;
			int elem = entry.first;
			bucket[cnt].insert(elem);
		}

		for (int i = bucket.size() - 1; i >= 0; i--) {
			if (!bucket[i].size()) continue;
			for (const auto & elem: bucket[i]) {
				if (!k) return res;
				res.push_back(elem);
				k--;
			}
		}
		return res;
	}
};
