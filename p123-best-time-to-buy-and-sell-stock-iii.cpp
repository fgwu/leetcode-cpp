class Solution {
public:
	/*20171130 1626*/
	/*AC       1701*/
	int maxProfit(vector<int>& prices) {
		int sell2 = 0, buy2 = INT_MIN, sell1 = INT_MIN, buy1 = INT_MIN;

		for (int i = 0; i < prices.size(); i++) {
			sell2 = max(sell2, buy2 + prices[i]);
			buy2 = max(buy2, sell1 == INT_MIN? INT_MIN: (sell1 - prices[i]));
			sell1 = max(sell1, buy1 == INT_MIN? INT_MIN: (buy1 + prices[i]));
			buy1 = max(buy1, -prices[i]);
		}

		return max(sell1, sell2);
	}
};

/*
      1 3 2 4 5 10 2 7
      s2  0 0 0 4 5
      b2  X X 0 0 0
      s1  X 2 2 3 4
      b1 -1-1-1-1-1


*/    
