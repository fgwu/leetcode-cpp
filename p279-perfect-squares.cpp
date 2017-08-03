class Solution {
public:
	/*20170726 1365 try bfs*/
	int numSquares(int n) {
		queue<int> q;
		unordered_map<int, int> m;
		m[n] = 0;
		q.push(n);

		while(!q.empty()) {
			int tmp = q.front();
			q.pop();
			int step = m[tmp];
			for (int root = 1; tmp/root >= root; root++) {
				int remain = tmp - root * root;
				if(m.count(remain)) continue;
				if (!remain) return step + 1;
				m[remain] = step + 1;
				q.push(remain);
			}
		}

		return -1;
	}


	/*20170726 1316*/
	/*AC       1336*/
	//     int numSquares(int n) {
	//         vector<int> m(n + 1, INT_MAX);
	//         m[0] = 0;
	//         for (int i = 1; i <= n; i++)
	//             for (int root = 1; i / root >= root; root++)
	//                 m[i] = min(m[i], m[i - root * root] + 1);

	//         return m[n];
	//     }
};
