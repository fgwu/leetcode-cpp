class Solution {
public:
	/*20171121 0012*/
	/*AC       0056*/
	void findSquare(vector<int>& hist, int &rv) {
		hist.push_back(0);
		stack<pair<int, int>> s; // height, idx
		for (int i = 0; i < hist.size(); i++) {
			int last_idx = i;
			while(!s.empty() && s.top().first > hist[i]) {
				auto p = s.top();
				s.pop();
				int minlen = min(i - p.second, p.first);
				rv = max(rv, minlen * minlen);
				last_idx = p.second;
			}
			s.push(make_pair(hist[i], last_idx));
		}
		hist.pop_back();
	}

	int maximalSquare(vector<vector<char>>& matrix) {
		if (!matrix.size()) return 0;
		int m = matrix.size();
		if (!matrix[0].size()) return 0;
		int n = matrix[0].size();
		int rv = 0;
		vector<int> hist (n, 0);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == '1')
					hist[j]++;
				else
					hist[j] = 0;
			}
			findSquare(hist, rv);
		}
		return rv;
	}
};
