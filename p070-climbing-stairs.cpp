class Solution {
public:
	/*AC 1519 fibonacci..*/
	int climbStairs(int n) {
		if (n < 2) return 1;
		int a = 1, b = 1, c;
		for (int i = 2; i <= n; i++) {
			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}

	/*AC 20170524 1515*/
	// int climbStairs(int n) {
	//     if (n < 2) return 1;
	//     vector<int> steps(n + 1, 0);
	//     steps[0] = 1;
	//     steps[1] = 1;
	//     for (int i = 2; i <= n; i++) steps[i] = steps[i - 1] + steps[i - 2];
	//     return steps[n];
	// }
};
