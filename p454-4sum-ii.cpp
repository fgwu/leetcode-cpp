class Solution {
public:
	/*20170524 1104*/
	/*AC       1111*/
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int cnt = 0;
		unordered_map<int, int> abmap;
		for (const auto & a: A ) for(const auto & b:B) abmap[a + b]++;
		for (const auto & c: C ) for(const auto & d:D) cnt += abmap[- (c + d)];
		return cnt;
	}
};
