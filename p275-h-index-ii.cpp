class Solution {
public:
	/*20171122 1156*/
	/*AC       1209*/
	int hIndex(vector<int>& citations) {
		int n = citations.size(), l = 0, r = n;
		while (l < r) {
			int mid = l + (r - l) / 2 + (r - l) % 2;
			if (citations[n - mid] >= mid)
				l = mid;
			else
				r = mid - 1;
		}
		return l;
	}
};
