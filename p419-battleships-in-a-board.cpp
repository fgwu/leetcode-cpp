class Solution {
public:
	/*20170519 16:47*/
	/*         17:05*/
	/*AC       17:08*/
	/*Note: inner loop, max is board[0].size instread of board.size*/
	int countBattleships(vector<vector<char>>& board) {
		int cnt = 0, i, j;
		if (board.size() == 0) return cnt;
		if (board[0].size() == 0) return cnt;

		for (i = 0; i < board.size(); i++)
			for (j = 0; j < board[0].size(); j++){
				if (board[i][j] == '.')
					continue;
				if (i > 0 && board[i - 1][j] == 'X')
					continue;
				if (j > 0 && board[i][j - 1] == 'X')
					continue;
				cnt++;
			}
		return cnt;
	}
};
