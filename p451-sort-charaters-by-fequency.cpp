class Solution {
public:
	/*20170521 1957*/
	/*AC       2116*/
	string frequencySort(string s) {
		unordered_map<char, int> map;
		string rv = "";
		for (const auto & c: s) {
			if (map.find(c) == map.end()) map[c] = 1;
			else map[c]++;
		}

		vector<pair<char, int>> pairs;
		for (const auto & p:map) pairs.push_back(make_pair(p.first, p.second));

		auto cmp  = [](const pair<char, int> & p1, const pair<char, int> & p2){ return p1.second > p2.second; };

		sort(pairs.begin(), pairs.end(), cmp);
		for (const auto & p: pairs){
			int cnt = p.second;
			while (cnt--) rv += p.first;
		}
		return rv;
	}
};
