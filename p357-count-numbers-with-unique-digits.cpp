class Solution {
public:
	/*AC 20170524 1148*/
	int countNumbersWithUniqueDigits(int n) {
		if (!n) return 1;
		if (n == 1) return 10;
		int rv = 10, tmp = 9, d = 9;
		for (; n - 2 >= 0 && d > 0; tmp *= --d, n--) rv += tmp * 9;
		return rv;
	}
};
