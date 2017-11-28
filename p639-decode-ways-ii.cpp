class Solution {
public:
	/*20171126 1551*/
	/*restart 20171127 1414*/
	/*AC        2146*/
	int numDecodings(string s) { // *
		int n = s.size();
		if (!n) return 0;
		vector<long>dp(n + 1); // ways of length of i
		dp[0] = 1;
		for (int len = 1; len <= n; dp[len]%=1000000007, len++) {
			dp[len] = 0;
			switch (s[len - 1]){
			case '*':
				dp[len] += 9 * dp[len - 1];
				break;
			case '0':
				// do nothing
				break;
			default: // 1-9
				dp[len] += dp[len - 1];
			}

			if (len <= 1) continue;
			if (s[len - 1] == '*' && s[len - 2] == '*') {
				dp[len] += 15 * dp[len - 2];
				continue;
			}

			if (s[len - 1] == '*') {
				string tmp = s.substr(len - 2, 2);
				for (char c = '1'; c <= '9'; c++){
					tmp[1] = c;
					if (stoi(tmp) >= 10 && stoi(tmp) <= 26)
						dp[len] += dp[len - 2];
				}
				continue;
			}

			if (s[len - 2] == '*') {
				string tmp = s.substr(len - 2, 2);
				for (char c = '1'; c <= '2'; c++){
					tmp[0] = c;
					if (stoi(tmp) >= 10 && stoi(tmp) <= 26)
						dp[len] += dp[len - 2];
				}
				continue;
			}

			string tmp = s.substr(len - 2, 2);
			if (stoi(tmp) >= 10 && stoi(tmp) <= 26)
				dp[len] += dp[len - 2];
		}

		return dp[n];
	}
};
