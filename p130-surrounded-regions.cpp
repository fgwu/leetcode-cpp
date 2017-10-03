/*20171001 2147*/
/*AC    02 0018 Union Find*/
class UF {
private:
	int size;
	int* rank;
	int* id;
public:
	UF(int capacity) {
		rank = new int[capacity];
		id = new int[capacity];

		for (int i = 0; i < capacity; i++) {
			id[i] = i;
			rank[i] = 0;
		}
	}

	~UF() {
		delete [] rank;
		delete [] id;
	}

	int find_set(int i) {
		while (i != id[i]) {
			id[i] = id[id[i]];
			i = id[i];
		}
		return i;
	}

	void union_set(int i, int j) {
		int ri = find_set(i);
		int rj = find_set(j);
		if (ri == rj) return;
		if (rank[ri] > rank[rj]) {
			id[rj] = ri;
		} else if (rank[ri] < rank[rj]) {
			id[ri] = rj;
		} else {
			id[rj] = ri;
			rank[ri]++;
		}
	}

	int same_set(int x, int y) {
		return find_set(x) == find_set(y);
	}
};

class Solution {
public:
	void solve(vector<vector<char>>& board) {
		if (!board.size() || !board[0].size()) return;
		int m = board.size(), n = board[0].size();
		int dummy = m * n;
		UF uf(dummy + 1);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] != 'O') continue;
				if (!i || !j || i == m - 1 || j == n - 1)
					uf.union_set(i * n + j, dummy);
				if (i && board[i - 1][j] == 'O')
					uf.union_set(i * n + j, (i - 1) * n + j);
				if (j && board[i][j - 1] == 'O')
					uf.union_set(i * n + j, i * n + (j - 1));
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 'O' &&
				    !uf.same_set(i * n + j, dummy))
					board[i][j] = 'X';
			}
		}
	}


	/*20171001 2147*/
	/*RT Error 2212*/
	//     void dfs(vector<vector<char>>& board, int i, int j) {
	//         board[i][j] = 'V'; //visited
	//         int m = board.size(), n = board[0].size();
	//         if (i - 1 >= 0 && board[i - 1][j] == 'O') dfs(board, i - 1, j);
	//         if (i + 1 <  m && board[i + 1][j] == 'O') dfs(board, i + 1, j);
	//         if (j - 1 >= 0 && board[i][j - 1] == 'O') dfs(board, i, j - 1);
	//         if (j + 1 <  n && board[i][j + 1] == 'O') dfs(board, i, j + 1);
	//     }

	//     void solve(vector<vector<char>>& board) {
	//         if (!board.size() || !board[0].size()) return;
	//         int m = board.size(), n = board[0].size();
	//         for (int j = 0; j < n; j++) {
	//             if (board[0][j] == 'O') dfs(board, 0, j);
	//             if (m > 1 && board[m - 1][j] == 'O') dfs(board, m - 1, j);
	//         }

	//         for (int i = 1; i < m - 1; i++) {
	//             if (board[i][0] == 'O') dfs(board, i, 0);
	//             if (n > 1 && board[i][n - 1] == 'O') dfs(board, i, n - 1);
	//         }

	//         for (auto & v: board) {
	//             for (char& c: v) {
	//                 if(c == 'O')
	//                     c = 'X';
	//                 else if (c == 'V')
	//                     c = 'O';
	//             }
	//         }
	//     }
};
