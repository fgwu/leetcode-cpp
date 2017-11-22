class Solution {
public:
	/*20171119 0932*/
	/*AC       0943*/
	string convertToTitle(int n) {
		string rv;
		while(n) {
			rv = (char)(--n % 26 + 'A') + rv;
			n /= 26;
		}
		return rv;
	}
};
