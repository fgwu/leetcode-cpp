class Solution {
public:
	/*20170919 1707*/
	/*20171118 1804 restart*/
	/*AC       1844*/
	void check(vector<int>& bar, int &rv){
		stack<pair<int, int>> s; //pair: height, index
		for(int i = 0; i < bar.size(); i++) {
			// printf("%d, ", bar[i]);
			int idx = -1;
			while(s.size() && bar[i] < s.top().first) {
				rv = max(rv, s.top().first * (i - s.top().second));
				// printf("(%d*%d=%d) ", s.top().first, i - s.top().second, rv);
				idx = s.top().second;
				s.pop();
			}
			if (idx == -1) idx = i;
			s.push(make_pair(bar[i], idx));
		}
		// printf("\n");
	}

	int maximalRectangle(vector<vector<char>>& matrix) {
		int m = matrix.size();
		if (!m) return 0;
		int n = matrix[0].size();
		if (!n) return 0;
		int rv = 0;
		vector<int> bar(n + 1, 0);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == '0')
					bar[j] = 0;
				else
					bar[j]++;
			}
			check(bar, rv);
		}
		return rv;
	}
};
