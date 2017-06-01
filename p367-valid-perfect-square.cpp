class Solution {
public:
	/* 1 3 5  trick*/
	/* time exceeded...*/
	// bool isPerfectSquare(int num) {
	//     int i = 1, sum = 0;
	//     do {
	//         sum += i;
	//         i += 2;
	//     } while (sum < num);
	//     if (sum == num) return true;
	//     else return false;
	// }


	/*Newton's method x_{n+1} = x_{n} - f(x_n)/f'{x_n} = x_n - (x_n^2 - num)/(2*x_n)*/
	/*AC    0138*/
	// bool isPerfectSquare(int num) {
	//     double x = 1;
	//     while (true) {
	//         cout << x << " " ;
	//         // int x2 = x - (x * x - num)/ x /2;
	//         double x2 = x / 2  +  num / x / 2;
	//         cout << x2 << "\n";
	//         if (x2 == x) break;
	//         x = x2;
	//     }
	//     if (int(x) * int(x) == num) return true;
	//     else return false;
	// }

	/*Binary search: time exceeded reason: int overflow*/
	/*solution: use long, or use mid == double(num) / double(num) trick */
	bool isPerfectSquare(int num) {
		int left = 1, right = num, mask;
		while(left <= right) {
			int mid = (left + right)/2;
			cout << left << right << mid << mid * mid << "\n";
			if (!(num % mid) && mid == num / mid) return true;
			if (mid > double(num) / double(mid)) right = mid - 1;
			else left = mid + 1;
		}
		return false;
	}


	/*AC 20170601 0109*/
	// bool isPerfectSquare(int num) {
	//     cout << sqrt(num) << " " << sqrt(num) * sqrt(num) << "\n";
	//     return num == int(sqrt(num)) * int(sqrt(num));
	// }
};
