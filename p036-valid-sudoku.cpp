class Solution {
public:
	/*20170802 1600*/ // brute force O(n^3)
	// unordered set Time: O(n^2) Space O(n^2)
	/*AC    1617*/
	bool isValidSudoku(vector<vector<char>>& board) {
		if (board.size() != 9 || board[0].size() != 9) return false;
		vector<unordered_set<char>> row_set(9);
		vector<unordered_set<char>> col_set(9);
		vector<vector<unordered_set<char>>> sqr_set(3, vector<unordered_set<char>>(3));

		for(int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++){
				char c = board[i][j];
				if (c == '.') continue;
				if (c - '0' > 9 || c - '0' < 0) return false;
				if (row_set[i].count(c)) return false;
				row_set[i].insert(c);
				if (col_set[j].count(c)) return false;
				col_set[j].insert(c);
				if (sqr_set[i/3][j/3].count(c)) return false;
				sqr_set[i/3][j/3].insert(c);
			}

		return true;

	}
	};
