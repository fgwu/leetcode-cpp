class Solution {
public:
	/*classic newton*/
	int mySqrt(int x) {
		if (x <= 0) return x;
		double r = x;
		while (abs((double)x / r - r) > 0.0000001) {
			// cout << r << "\n";
			r = (r + x / r) / 2;
		}
		// cout << r << "\n";
		return (int) r;
	}


	/*Newton*/
	/*         1104*/
	// int mySqrt(int x) {
	//     if (x <= 0) return x;
	//     long res = x;
	//     while (res > (x / res)) {
	//         res = (x / res + res) / 2;
	//     }
	//     return res;
	// }


	/*20170628 1033*/
	/*AC       1050*/
	// int mySqrt(int x) {
	//     if (x <= 0 ) return x;
	//     int left = 1, right = x;
	//     while (left < right) {
	//         if (left <= x / left && (left + 1) > x / (left + 1)) return left;
	//         if (right <= x / right && (right + 1) > x / (right + 1)) return right;
	//         int mid = (left + right) / 2;
	//         if (mid <= x / mid && (mid + 1) > x / (mid + 1)) return mid;
	//         if (mid > x / mid)
	//             right = mid - 1;
	//         else
	//             left = mid + 1;
	//     }
	//     return min(left, right);
	// }
};
