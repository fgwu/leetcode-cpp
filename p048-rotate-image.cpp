class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();

		reverse(matrix.begin(), matrix.end());
		for (int i = 0; i < n; i++)
			for (int j = i; j < n; j++)
				swap(matrix[i][j], matrix[j][i]);

	}





	/*flip flip*/
	//     void rotate(vector<vector<int>>& matrix) {
	//         int n = matrix.size();
	//         for (int i = 0; i < n; i++)
	//             for (int j = i; j < n; j++)
	//                 swap(matrix[i][j], matrix[j][i]);

	//         for (auto& row: matrix)
	//             reverse(row.begin(), row.end());
	//         // for (int i = 0; i < n; i++)
	//         //     reverse(matrix[i].begin(), matrix[i].end());

	//     }

	/*20170721 0944*/
	/*AC       1044*/
	// void rotate(vector<vector<int>>& matrix) {
	//     int n = matrix.size();
	//     if (!n || matrix[0].size() != n) return;
	//     for (int i = 0; i <= (n - 1)/2; i++) {
	//         for(int j = 0; j < n/2; j++) {
	//             int tmp = matrix[i][j];
	//             matrix[i][j] = matrix[n - 1 - j][i];
	//             matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
	//             matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
	//             matrix[j][n - 1 - i] = tmp;
	//         }
	//     }
	// }
};
