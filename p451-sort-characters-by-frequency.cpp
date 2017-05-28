class Solution {
public:
	/* seen the solution, try bucket sorting */
	/*20170521 2157*/
	/*AC       2225*/
	string frequencySort(string s) {
		string rv = "";
		unordered_map<char, int> freq_map;
		vector<string> bucket(s.size() + 1, "");
		for (const auto & c:s) freq_map[c]++;
		for (const auto & entry:freq_map){
			int cnt = entry.second;
			char c = entry.first;
			bucket[cnt] += c;
		}
		for (int i = s.size(); i > 0; i--){
			if (!bucket[i].size()) continue;
			for (const auto & c:bucket[i]) {
				int cnt = i;
				while (cnt--) rv += c;
			}
		}
		return rv;
	}




	/*20170521 1957*/
	/*AC       2116*/
	// string frequencySort(string s) {
	//     unordered_map<char, int> map;
	//     string rv = "";
	//     for (const auto & c: s) {
	//         if (map.find(c) == map.end()) map[c] = 1;
	//         else map[c]++;
	//     }

	//     vector<pair<char, int>> pairs;
	//     for (const auto & p:map) pairs.push_back(make_pair(p.first, p.second));

	//     auto cmp  = [](const pair<char, int> & p1, const pair<char, int> & p2){ return p1.second > p2.second; };

	//     sort(pairs.begin(), pairs.end(), cmp);
	//     for (const auto & p: pairs){
	//         int cnt = p.second;
	//         while (cnt--) rv += p.first;
	//     }
	//     return rv;
	// }
};
