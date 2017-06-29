class Solution {
public:
	/*optmization*/
	int reverse(int x) {
		long res = 0;
		for (; x; x /= 10) {
			int d = x%10;
			res = res * 10 + d;
			if (res > INT_MAX || res < INT_MIN) return 0;
		}
		return res;
	}


	/*20170622 1016*/
	/*AC       1026*/
	// long helper(long x) {
	//     if (!x) return x;
	//     if (x < 0) return -helper(-x);
	//     long res = 0;
	//     while(x) {
	//         long d = x%10;
	//         res = res * 10 + d;
	//         x /= 10;
	//     }
	//     return res;
	// }


	// int reverse(int x) {
	//     long res = helper((long)x);
	//     if ((int)res != res) return 0;
	//     return res;
	// }
};
