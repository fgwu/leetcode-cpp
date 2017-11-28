class Solution {
public:
	/*20171126 1525*/
	/*AC       1533*/
	int leastBricks(vector<vector<int>>& wall) {
		unordered_map<int, int> bucket;
		for(auto & r: wall) {
			int x = 0;
			for (int i = 0; i < r.size() - 1; i++) {
				x += r[i];
				if (!bucket.count(x))
					bucket[x] = 0;
				bucket[x]++;
			}
		}

		int max_cnt = 0;
		for (auto & p: bucket)
			max_cnt = max(max_cnt, p.second);

		return wall.size() - max_cnt;
	}
};
