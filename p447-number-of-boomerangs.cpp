class Solution {
public:


	/*AC 20170523 2226 next: counting version */
	/*faster if using counting. O(n^2)  currently O(n^3)*/
	int dist(pair<int, int> a, pair<int, int> b) {
		return (a.first - b.first) * (a.first - b.first) +
			(a.second - b.second) * (a.second - b.second);
	}

	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		int rv = 0, i, j, k;
		for (i = 0; i< points.size(); i++)
			for (j = 0; j < points.size() - 1; j++) {
				if (i == j) continue;
				for (k = j + 1; k < points.size(); k++) {
					if (i == k) continue;
					if (dist(points[i], points[j]) == dist(points[i], points[k]))  rv += 2;
				}
			}
		return rv;
	}
};
