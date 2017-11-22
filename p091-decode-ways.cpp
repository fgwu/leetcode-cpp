class Solution {
public:
	/*20171119 1515 restart*/
	/*AC       1538*/
	int numDecodings(string s) {
		if (!s.size()) return 0;
		vector<int> dp(s.size() + 1);
		dp[0] = 1;
		for (int i = 1; i < dp.size(); i++) {
			dp[i] = 0;
			if (s[i - 1] >= '1' && s[i - 1] <= '9')
				dp[i] += dp[i - 1];

			if (i >= 2) {
				int tmp = stoi(s.substr(i - 2, 2));
				if (tmp >= 10 && tmp <= 26)
					dp[i] += dp[i - 2];
			}
		}
		return dp[s.size()];
	}
};
