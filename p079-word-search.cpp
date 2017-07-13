class Solution {
public:
	/*20170710 2147*/
	/*AC       2219*/
	bool tryMatch(const vector<vector<char>>& board,
		      vector<vector<bool>>& visited,
		      const string& word, int i, int j, int k) {
		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
		if (visited[i][j] || board[i][j] != word[k]) return false;
		if (k == word.size() - 1) return true;
		visited[i][j] = true;

		if (tryMatch(board, visited, word, i - 1, j, k + 1)) return true;
		if (tryMatch(board, visited, word, i + 1, j, k + 1)) return true;
		if (tryMatch(board, visited, word, i, j - 1, k + 1)) return true;
		if (tryMatch(board, visited, word, i, j + 1, k + 1)) return true;

		visited[i][j] = false;
		return false;
	}

	bool exist(vector<vector<char>>& board, string word) {
		if (!word.size()) return true;
		if (!board.size() || !board[0].size()) return false;
		int m = board.size(), n = board[0].size();
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (tryMatch(board, visited, word, i, j, 0)) return true;
		return false;
	}
};
