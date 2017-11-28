class Solution {
public:
	/*20171125 0807*/
	/*AC       0818*/
	bool validPalindrome(string s) {
		if (!s.size()) return false;
		if (s.size() == 1 || s.size() == 2) return true;

		int l = 0, r = s.size() - 1;

		while(l <= r) {
			if (s[l] != s[r]) break;
			l++, r--;
		}

		if (l > r) return true;

		int i = l + 1, j = r;

		bool rv = true;
		while(i <= j) {
			if (s[i] != s[j]) {
				rv = false;
				break;
			}
			i++, j--;
		}

		if (rv) return true;

		i = l, j = r - 1;
		rv = true;
		while(i <= j) {
			if (s[i] != s[j]) {
				rv = false;
				break;
			}
			i++, j--;
		}
		return rv;
	}
};
