class Solution {
public:
	/*OK i thought it to be too complicated. after seen the solution, here is my version*/
	/*20170520 00:38*/
	/*AC       00:42*/
	int maxProfit(vector<int>& prices) {
		int rv = 0;
		if (prices.size() == 0 || prices.size() == 1) return rv;
		for (int i = 1; i<prices.size(); i++) {
			rv += prices[i] > prices[i - 1]? prices[i] - prices[i - 1]:0;
		}
		return rv;
	}


	/*20170519 23:19*/
	/*         23:36*/
	/*20170519 23:45 too many bugs, restart */
	/*AC       00:33 simple bug: low should be p after a transaction */
	// int maxProfit(vector<int>& prices) {
	//     int rv = 0, low = INT_MAX, high = INT_MIN;
	//     if (!prices.size()) return rv;
	//     prices.push_back(INT_MIN);

	//     for(const auto & p: prices){
	//         if (high == INT_MIN && low >= p) {
	//             low = p;
	//             continue;
	//         }

	//         if (high < p) {
	//             high = p;
	//             continue;
	//         }

	//         rv += high - low;
	//         low = p;
	//         high = INT_MIN;
	//     }
	//     return rv;
	// }

};
