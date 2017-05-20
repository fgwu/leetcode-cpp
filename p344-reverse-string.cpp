class Solution {
public:
	/*20170517 14:31*/
	/*AC       14:35*/
	string reverseString(string s) {
		string rv;
		int i;
		for (i = s.size() - 1; i >= 0; i--) {
			rv += (s[i]);
		}
		return rv;
	}
};
