class Solution {
public:
	/*20171003 1224*/
	/*AC       0108*/
	vector<pair<int, int>> merge(vector<pair<int, int>>& a, vector<pair<int, int>>& b) {
		vector<pair<int, int>> res;
		for (int i = 0, j = 0; i < a.size() || j < b.size();) {
			if (i >= a.size()) {
				res.push_back(b[j++]);
				continue;
			}

			if (j >= b.size()) {
				res.push_back(a[i++]);
				continue;
			}

			if (a[i].first == b[j].first) {
				res.push_back(make_pair(a[i].first,max(a[i].second, b[j].second)));
				i++, j++;
				continue;
			}

			if (a[i].first > b[j].first) {
				int h = i ? max(b[j].second, a[i - 1].second): b[j].second;
				res.push_back(make_pair(b[j].first, h));
				j++;
			} else {
				int h = j ? max(a[i].second, b[j - 1].second): a[i].second;
				res.push_back(make_pair(a[i].first, h));
				i++;
			}
		}
		return res;
	}

	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		if (!buildings.size()) return  vector<pair<int, int>>();
		vector<vector<pair<int,int>>> skylines;
	for (auto v: buildings)
		skylines.push_back(vector<pair<int, int>>{make_pair(v[0], v[2]),
					make_pair(v[1], 0)});
	while(skylines.size() > 1) {
		int N = skylines.size();
		vector<vector<pair<int, int>>> tmp_skyline;
	for (int i = 0; i < (N + 1) / 2; i++) {
		if (i * 2 + 1 >= N) {
			tmp_skyline.push_back(skylines[i * 2]);
			continue;
		}

		tmp_skyline.push_back(merge(skylines[i * 2], skylines[i * 2 + 1]));
	}
	swap(skylines, tmp_skyline);
}
	vector<pair<int, int>> res;
for(auto p: skylines[0])
	if (!res.size() || res.back().second != p.second)
		res.push_back(p);
return res;
}
};
