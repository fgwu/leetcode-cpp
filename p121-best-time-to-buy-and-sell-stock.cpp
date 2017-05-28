class Solution {
public:
	/*20170524 0132*/
	/*AC       0142*/
	int maxProfit(vector<int>& prices) {
		int last_min = INT_MAX, profit = 0;

		for (const auto & p: prices) {
			if (p < last_min) {
				last_min = p;
				continue;
			}
			profit = max(p - last_min, profit);
		}

		return profit;
	}
};
