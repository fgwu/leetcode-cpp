class Solution {
public:
	/*2017525 2030*/
	/*        2037*/
	/*AC      2047*/
	int integerBreak(int n) {
		if (n == 1 || n == 2) return 1;
		vector<int> m(n + 1, 1);
		m[1] = m[2] = 1;
		for(int i = 3; i <= n; i++) {
			int tmp = INT_MIN;
			// cout << i << "\n";
			for (int j = 1; j < i; j++) {
				tmp = max(tmp, j * max(i - j, m[i - j]));
				// cout << j << " " << i - j << " " << m[i - j] << "\n";
			}
			m[i] = tmp;
		}
		return m[n];
	}
};
