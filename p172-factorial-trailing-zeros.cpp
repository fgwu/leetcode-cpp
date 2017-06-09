class Solution {
public:
	/*AC 20170607 1326*/
	int trailingZeroes(int n) {
		int res = 0;
		for(n/=5; n; n/=5) res += n;
		return res;
	}
};
