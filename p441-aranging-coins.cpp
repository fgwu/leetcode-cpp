class Solution {
public:
	/*Newton's method*/
	// int arrangeCoins(int n) {
	//     double x = 0, tmp;
	//     while (true){
	//         cout << x << " " << (x/2) << " " << -(x/4 - double(n))/(x + 0.5) << "\n";
	//         tmp = x/2 - (x/4 - double(n))/(x + 0.5);
	//         if (abs(tmp - x) < 0.01) break;
	//         x = tmp;
	//     }
	//     cout << x << "\n";
	//     cout << sizeof(long) << "\n";
	//     cout << sizeof(int) << "\n";
	//     return int(x);
	// }

	/*20170606 1848*/
	/*AC be careful of overflow*/
	int arrangeCoins(int n) {
		return (sqrt(1 + (long)8*n) - 1)/2;
		// return (sqrt(1 + (double)8*n) - 1)/2;  // this also works
	}
};
