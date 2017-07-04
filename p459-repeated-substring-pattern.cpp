class Solution {
public:
	/*20170704 1308 KMP*/
	int kmp(string t, string p){ // text and pattern
		vector<int> next((int)p.size(), -1);
		for (int i = -1, j = 0; j < p.size() - 1; ){
			if (i == -1 || p[i] == p[j])
				next[++j] = ++i;
			else
				i = next[i];
		}

		for (int i = 0, j = 1; j < t.size();) {
			if (i == -1 || p[i] == t[j])
				i++, j++;
			else
				i = next[i];
			if (i == p.size()) return j - i;
		}
		return -1;
	}

	bool repeatedSubstringPattern(string s) {
		string l = s + s;
		return kmp(l, s) != s.size();
	}

	/*AC 20170530 1721*/
	// bool repeatedSubstringPattern(string s) {
	//     string l = s + s;
	//     // cout << l << " " << s << " " << l.find(s) << "\n";
	//     return l.find(s,1) != s.size();
	// }
};
