class Solution {
public:
	/*20171006 1334*/
	/*AC       1356*/
	vector<string> helper(int n){
		unordered_map<string, string> m ({
				{"0", "0"},
				{"1", "1"},
				{"6", "9"},
				{"8", "8"},
				{"9", "6"}
			});
		if (!n) return vector<string>(1, "");
		if (n == 1) return vector<string> {"0", "1", "8"};
		vector<string>tmp = helper(n - 2);
		vector<string>res;
		for (auto & v: tmp) {
			for (auto &p : m) {
				string s = p.first;
				s += v;
				s += p.second;
				res.push_back(s);
			}
		}
		return res;
	}

	vector<string> findStrobogrammatic(int n) {
		if (!n) return vector<string>();
		vector<string> tmp = helper(n);
		vector<string> res;
		for (string & s: tmp){
			if (s.size() == 1 || s[0] != '0')
				res.push_back(s);
		}
		return res;
	}

};
