class Solution {
public:
	/*20170519 22:14 there is buildin pair!!!*/
	/*         22:21*/
	/*AC       22:22*/
	/*always pop() afer top()! */
	vector<string> findRelativeRanks(vector<int>& nums) {
		priority_queue<pair<int, int>> q;
		for (int i = 0; i < nums.size(); i++) q.push(make_pair(nums[i], i));
		int rank = 1;
		vector<string> rv(nums.size(), "");
		while(!q.empty()){
			switch (rank) {
			case 1:
				rv[q.top().second] = "Gold Medal";
				break;
			case 2:
				rv[q.top().second] = "Silver Medal";
				break;
			case 3:
				rv[q.top().second] = "Bronze Medal";
				break;
			default:
				rv[q.top().second] = to_string(rank);
			}
			rank++;
			q.pop();
		}
		return rv;
	}


	/*20170519 20:22*/
	/*         22:00*/
	/*AC       22:03*/
	/*class def end with ;*/
	/*help class, all field and method declare with public: */
	// class Pair{
	// public:
	//     int val;
	//     int idx;
	//     Pair(int v, int i){val = v; idx = i;}
	// };

	// class Compare{
	// public:
	//     bool operator() (Pair p1, Pair p2) {
	//         return p1.val < p2.val;
	//     }
	// };

	// vector<string> findRelativeRanks(vector<int>& nums) {
	//     priority_queue<Pair, vector<Pair>, Compare> q;
	//     vector<string> rv(nums.size());
	//     for (int i = 0; i < nums.size(); i++) q.push(Pair(nums[i], i));
	//     int rank = 1;
	//     while (!q.empty()) {
	//         string s;
	//         switch (rank) {
	//         case 1:
	//             s = "Gold Medal";
	//             break;
	//         case 2:
	//             s = "Silver Medal";
	//             break;
	//         case 3:
	//             s = "Bronze Medal";
	//             break;
	//         default:
	//             s = to_string(rank);
	//         }
	//         rv[q.top().idx] = s;
	//         q.pop();
	//         ++rank;
	//     }
	//     return rv;
	// }
};
