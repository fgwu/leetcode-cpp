class NumMatrix {
public:
	/*20170713 Thu 1427*/
	/*             1438 TLE*/
	/*             1526 AC*/
	NumMatrix(vector<vector<int>> matrix) {
		if (!matrix.size() || !matrix[0].size()) return;
		aux = vector<vector<int>> (matrix.size(), vector<int>(matrix[0].size(), 0));
		for (int i = 0; i < matrix.size(); i++){
			int row_tmp = 0;
			for (int j = 0; j < matrix[0].size(); j++) {
				row_tmp += matrix[i][j];
				aux[i][j] = (i - 1 >= 0) ? aux[i - 1][j]: 0;
				aux[i][j] += row_tmp;
			}
		}
	}

	int getSum(int row, int col){
		if (row < 0 || col < 0) return 0;
		return aux[row][col];
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return getSum(row2, col2) - getSum(row1 - 1, col2) -
			getSum(row2, col1 - 1) + getSum(row1 - 1, col1 - 1);
	}

private:
	vector<vector<int>> aux;
};



// class NumMatrix {
// public:
//     /*20170713 Thu 1427*/
//     /*             1438 TLE*/
//     NumMatrix(vector<vector<int>> matrix) {
//         m = matrix;
//     }

//     int sumRegion(int row1, int col1, int row2, int col2) {
//         int sum = 0;
//         for (int i = row1; i <= row2; i++)
//             for (int j = col1; j <= col2; j++)
//                 sum+=m[i][j];
//         return sum;
//     }

// private:
//     vector<vector<int>> m;
// };

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
