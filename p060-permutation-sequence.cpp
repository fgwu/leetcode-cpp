class Solution {
public:
	/*20170929 2226*/
	/*AC       2258*/
	string getPermutation(int n, int k) {
		int a = 1;
		for (int i = 1; i < n; i++) a *= i;

		vector<int> s(n + 1, 0);
		string res;

		for (int i = n - 1; i > 0; i--) {
			int d = (k - 1) / a + 1;

			for (int j = 1; j <= n; j++) {
				if (s[j]) continue;
				if (!--d) {
					res += '0' + j;
					s[j] = 1;
					break;
				}
			}

			k = (k - 1) % a + 1;
			a /= i;
		}

		for (int j = 1; j <= n; j++)
			if (!s[j]) res += '0' + j;

		return res;
	}
};
