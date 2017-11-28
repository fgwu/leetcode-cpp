class Solution {
public:
	/*Multi-source 1535*/
	/*AC        1653*/
	void wallsAndGates(vector<vector<int>>& rooms) {
		queue<pair<int, int>> q;
		for (int i = 0; i < rooms.size(); i++)
			for (int j = 0; j < rooms[0].size(); j++)
				if (!rooms[i][j]) q.push(make_pair(i, j));

		while(!q.empty()) {
			int i = q.front().first;
			int j = q.front().second;
			q.pop();

			if (i - 1 >= 0 && rooms[i - 1][j] > rooms[i][j] + 1) {
				rooms[i - 1][j] = rooms[i][j] + 1;
				q.push(make_pair(i - 1, j));
			}

			if (i + 1 < rooms.size() && rooms[i + 1][j] > rooms[i][j] + 1) {
				rooms[i + 1][j] = rooms[i][j] + 1;
				q.push(make_pair(i + 1, j));
			}

			if (j - 1 >= 0 && rooms[i][j - 1] > rooms[i][j] + 1) {
				rooms[i][j - 1] = rooms[i][j] + 1;
				q.push(make_pair(i, j - 1));
			}

			if (j + 1 < rooms[0].size() && rooms[i][j + 1] > rooms[i][j] + 1) {
				rooms[i][j + 1] = rooms[i][j] + 1;
				q.push(make_pair(i, j + 1));
			}
		}
	}

	/*BFS    1249*/
	/*AC     1534*/
	//     void expand(vector<vector<int>>& rooms, int x, int y) {
	//         queue<pair<int, int>> q;
	//         q.push(make_pair(x, y));

	//         while (!q.empty()) {
	//             auto p = q.front();
	//             int i = p.first, j = p.second;
	//             q.pop();
	//             if (i - 1 >= 0 && rooms[i - 1][j] > rooms[i][j] + 1) {
	//                 rooms[i - 1][j] = rooms[i][j] + 1;
	//                 q.push(make_pair(i - 1, j));
	//             }

	//             if (i + 1 < rooms.size() && rooms[i + 1][j] > rooms[i][j] + 1) {
	//                 rooms[i + 1][j] = rooms[i][j] + 1;
	//                 q.push(make_pair(i + 1, j));
	//             }

	//             if (j - 1 >= 0 && rooms[i][j - 1] > rooms[i][j] + 1) {
	//                 rooms[i][j - 1] = rooms[i][j] + 1;
	//                 q.push(make_pair(i, j - 1));
	//             }

	//             if (j + 1 < rooms[0].size() && rooms[i][j + 1] > rooms[i][j] + 1) {
	//                 rooms[i][j + 1] = rooms[i][j] + 1;
	//                 q.push(make_pair(i, j + 1));
	//             }
	//         }
	//     }


	//     void wallsAndGates(vector<vector<int>>& rooms) {
	//         int m = rooms.size();
	//         if (!m) return;
	//         int n = rooms[0].size();
	//         if (!n) return;

	//         for (int i = 0; i < m; i++) {
	//             for (int j = 0; j < n; j++) {
	//                 if (rooms[i][j]) continue;
	//                 printf("expand [%d %d]", i, j);
	//                 expand(rooms, i, j);
	//             }
	//         }
	//     }

	/*20171122 1336*/
	/*20171123 1123 restart*/
	/*         1233 */
	/*AC       1247 DFS */
	//     void expand(vector<vector<int>>& rooms, int i, int j) {
	//         if (i - 1 >= 0 && rooms[i - 1][j] > rooms[i][j] + 1) {
	//             rooms[i - 1][j] = rooms[i][j] + 1;
	//             expand(rooms, i - 1, j);
	//         }

	//         if (i + 1 < rooms.size() && rooms[i + 1][j] > rooms[i][j] + 1) {
	//             rooms[i + 1][j] = rooms[i][j] + 1;
	//             expand(rooms, i + 1, j);
	//         }

	//         if (j - 1 >= 0 && rooms[i][j - 1] > rooms[i][j] + 1) {
	//             rooms[i][j - 1] = rooms[i][j] + 1;
	//             expand(rooms, i, j - 1);
	//         }

	//         if (j + 1 < rooms[0].size() && rooms[i][j + 1] > rooms[i][j] + 1) {
	//             rooms[i][j + 1] = rooms[i][j] + 1;
	//             expand(rooms, i, j + 1);
	//         }
	//     }

	//     void wallsAndGates(vector<vector<int>>& rooms) {
	//         int m = rooms.size();
	//         if (!m) return;
	//         int n = rooms[0].size();
	//         if (!n) return;

	//         for (int i = 0; i < m; i++) {
	//             for (int j = 0; j < n; j++) {
	//                 if (rooms[i][j]) continue;
	//                 expand(rooms, i, j);
	//             }
	//         }
	//     }
};
