class Solution {
public:
	/*20171121 1211*/
	/*20171121 1540 restart*/
	/*         1624 bucket*/
	/*AC       1640*/
	int hIndex(vector<int>& citations) {
		int n = citations.size();
		vector<int> bucket(n + 1, 0);

		for (auto c: citations) {
			if (c >= n) bucket[n]++;
			else bucket[c]++;
		}

		int num_papers = 0, i;
		for (i = n; i >=0; i--) {
			num_papers += bucket[i];
			if (num_papers >= i)  break;
		}

		return i;
	}
};
