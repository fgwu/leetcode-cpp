class Solution {
public:
	/*20170521 1709*/
	/*         1759*/
	/*AC       1819*/
	vector<vector<int>> prepareDigitBoard (vector<vector<char>>& board) {
		int i, j, m = board.size(), n = board[0].size();
		vector<vector<int>> digit(m, vector<int>(n, 0));

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				int d = 0;
				d += (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] == 'M') ? 1:0;
				d += (i - 1 >= 0 && board[i - 1][j] == 'M') ? 1:0;
				d += (i - 1 >= 0 && j + 1 < n && board[i - 1][j + 1] == 'M') ? 1:0;
				d += (j - 1 >= 0 && board[i][j - 1] == 'M') ? 1:0;
				d += (j + 1 < n && board[i][j + 1] == 'M') ? 1:0;
				d += (i + 1 < m && j - 1 >= 0 && board[i + 1][j - 1] == 'M') ? 1:0;
				d += (i + 1 < m && board[i + 1][j] == 'M') ? 1:0;
				d += (i + 1 < m && j + 1 < n && board[i + 1][j + 1] == 'M') ? 1:0;
				digit[i][j] = d;
			}
		return digit;
	}

	void revealRec(vector<vector<char>>& board,
		       vector<vector<int>>& digit, int i, int j) {
		int m = board.size(), n = board[0].size();
		if (board[i][j] == 'B') return;
		if (digit[i][j]) {
			board[i][j] = '0' + digit[i][j];
			return;
		}
		board[i][j] = 'B';
		if (i - 1 >= 0 && j - 1 >= 0) revealRec(board, digit, i - 1, j - 1);
		if (i - 1 >= 0) revealRec(board, digit, i - 1, j);
		if (i - 1 >= 0 && j + 1 < n) revealRec(board, digit, i - 1, j + 1);
		if (j - 1 >= 0) revealRec(board, digit, i, j - 1);
		if (j + 1 < n) revealRec(board, digit, i, j + 1);
		if (i + 1 < m && j - 1 >= 0) revealRec(board, digit, i + 1, j - 1);
		if (i + 1 < m) revealRec(board, digit, i + 1, j);
		if (i + 1 < m && j + 1 < n) revealRec(board, digit, i + 1, j + 1);
	}

	void update (vector<vector<char>>& board,
		     vector<vector<int>>& digit, vector<int>& click) {
		int i = click[0], j = click[1];
		if (board[i][j] == 'M') {
			board[i][j] = 'X';
			return;
		}
		if (board[i][j] == 'E' && digit[i][j]) {
			board[i][j] = '0' + digit[i][j];
			return;
		}
		revealRec(board, digit, i, j);
	}

	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		vector<vector<int>> digit = prepareDigitBoard(board);
		update(board, digit, click);
		return board;
	}
};
