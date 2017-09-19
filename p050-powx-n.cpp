class Solution {
public:
	/*iter  0316*/
	double myPow(double x, long n) {
		if (!n) return 1;
		if (n < 0) return myPow(1 / x, -n);
		double res = 1;
		while(n) {
			if (n & 1) res *= x;
			x *= x;
			n >>= 1;
		}

		return res;
	}

	double myPow(double x, int n) {
		return myPow(x, (long)n);
	}

	/* 20170813 0259 */
	/* AC 0311*/
	//     double myPow(double x, long n) {
	//         if (!n) return 1;
	//         if (n < 0) return myPow(1 / x, -n);
	//         double res = myPow(x * x, n / 2);
	//         if (n % 2) return res * x;
	//         return res;
	//     }

	//     double myPow(double x, int n) {
	//         return myPow(x, (long)n);
	//     }
};
