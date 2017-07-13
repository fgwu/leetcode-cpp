class Solution {
public:
	/*20170710 2245*/
	/*AC       2258*/
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> m;
		vector<vector<string>> res;
		for (const auto str: strs) {
			string keystr = str;
			sort(keystr.begin(), keystr.end());
			m[keystr].push_back(str);
		}

		for (const auto pair: m) {
			vector<string>tmp;
			for(const auto str: pair.second)
				tmp.push_back(str);
			res.push_back(tmp);
		}

		return res;
	}
};
