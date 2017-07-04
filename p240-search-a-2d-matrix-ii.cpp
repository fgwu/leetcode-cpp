class Solution {
public:
	/*20170703 1339 try saddleback search*/
	/*AC       1346*/
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (!matrix.size() || !matrix[0].size()) return false;
		int m = matrix.size(), n = matrix[0].size(), i = 0, j = n - 1;
		// loop invariant: target is in [i...m-1, 0 ...j]
		while(i < m && j >= 0) {
			if (matrix[i][j] == target) return true;
			if (matrix[i][j] > target) j--;
			else i++;
		}
		return false;
	}
};
/* http://cs.geneseo.edu/~baldwin/math-thinking/saddleback.html*/
