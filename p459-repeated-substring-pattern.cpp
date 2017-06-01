class Solution {
public:
	/*AC 20170530 1721*/
	bool repeatedSubstringPattern(string s) {
		string l = s + s;
		// cout << l << " " << s << " " << l.find(s) << "\n";
		return l.find(s,1) != s.size();
	}
};
