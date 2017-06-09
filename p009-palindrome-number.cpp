class Solution {
public:
	/*20170608 1358*/
	/*AC       1403*/
	bool isPalindrome(int x) {
		if (x < 0) return false;
		int a = 0, b;
		for(b = x; b; b/=10) a = a * 10 + b % 10;
		return x == a;
	}
};
