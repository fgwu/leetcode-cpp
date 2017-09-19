class Solution {
public:
	/*20170813 0204*/
	/*AC       0256*/
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp (amount + 1, INT_MAX);
		dp[0] = 0;
		for (long i = 0; i <= amount; i++) {
			if (dp[i] == INT_MAX) continue;
			for (auto &c: coins) {
				if (i + (long) c > amount) continue;
				dp[i + (long)c] = min(dp[i + (long)c], dp[i] + 1);
			}
		}
		return dp[amount] == INT_MAX? -1: dp[amount];
	}
};
