class Solution {
public:
	/*try another of upper_bound, the first elem that is >= target*/
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (!matrix.size()) return false;
		// search for the index of the first element >= target.
		int m = matrix.size(), n = matrix[0].size(), lo = 0, hi = m * n - 1;
		while (lo <= hi) {
			if (lo == hi) {
				if (matrix[lo/n][lo%n] < target) lo++;
				break;
			}
			int mid = lo + (hi - lo) / 2;
			if (matrix[mid/n][mid%n] < target)
				lo = mid + 1;
			else
				hi = mid;
		}
		return (lo < m * n && matrix[lo/n][lo%n] == target);
	}

	/*try my own upper_bound implementation of binary search */
	//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
	//         if (!matrix.size()) return false;
	//         // search for the index of the first element that is greater than target.
	//         int m = matrix.size(), n = matrix[0].size(), lo = 0, hi = m * n - 1;
	//         while (lo <= hi) {
	//             if (lo == hi) {
	//                 if (matrix[lo/n][lo%n] <= target) lo++;
	//                 break;
	//             }
	//             int mid = lo + (hi - lo) / 2;
	//             if (matrix[mid/n][mid%n] <= target)
	//                 lo = mid + 1;
	//             else
	//                 hi = mid;
	//         }
	//         // retrieve by one to find possible location.
	//         lo--;
	//         return (lo >= 0 && matrix[lo/n][lo%n] == target);
	//     }


	/*seen sln, treat the matrix as a sorted list*/
	//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
	//         if (!matrix.size()) return false;
	//         int m = matrix.size(), n = matrix[0].size(), lo = 0, hi = m * n - 1;
	//         while (lo <= hi) {
	//             if (lo == hi) return matrix[lo/n][lo%n] == target;
	//             int mid = lo + (hi - lo) / 2;
	//             if (matrix[mid/n][mid%n] == target) return true;
	//             if (matrix[mid/n][mid%n] > target)
	//                 hi = mid - 1;
	//             else
	//                 lo = mid + 1;
	//         }
	//         return false;
	//     }



	/*20170703 1352*/
	/*20160704 0904 restart*/
	/*AC       1231*/
	//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
	//         if (!matrix.size() || !matrix[0].size()) return false;
	//         int m = matrix.size(), n = matrix[0].size(), lo, hi, row;

	//         lo = 0, hi = m - 1;
	//         // find the first elemen that is greater than target.
	//         while(lo <= hi) {
	//             if (lo == hi) {
	//                 if (matrix[lo][0] <= target) lo++;
	//                 break;
	//             }
	//             int mid = lo + (hi - lo) / 2;
	//             //if (matrix[mid][0] == target) return true;
	//             if (matrix[mid][0] <= target)
	//                 lo = mid + 1;
	//             else
	//                 hi = mid;
	//         }
	//         row = lo - 1;
	//         // index may go out of boundary
	//         if (row < 0) return false;
	//         lo = 0, hi = n - 1;
	//         while (lo <= hi) {
	//             if (lo == hi)
	//                 return matrix[row][lo] == target;
	//             int mid = lo + (hi - lo) / 2;
	//             if (matrix[row][mid] == target) return true;
	//             if (matrix[row][mid] < target)
	//                 lo = mid + 1;
	//             else
	//                 hi = mid - 1;
	//         }
	//         return false;
	//     }
};
