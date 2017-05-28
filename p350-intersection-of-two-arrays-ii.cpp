class Solution {
public:
	/*AC 20170523 2204*/
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> hash;
		vector<int> res;
		for (const auto & n:nums1) hash[n]++;
		for (const auto & n:nums2){
			if (hash.find(n) == hash.end()) continue;
			res.push_back(n);
			if(--hash[n] == 0) hash.erase(n);
		}
		return res;
	}
};
