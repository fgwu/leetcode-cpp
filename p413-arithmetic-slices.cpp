class Solution {
public:
	/*seen the solution */
	/*20170520 1756*/
	/*AC       1759 bug: init the rv!! */
	int numberOfArithmeticSlices(vector<int>& A) {
		int rv = 0;
		for (int i = 2, curr = 0; i < A.size(); i++){
			if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]){
				rv += ++curr;
				continue;
			}
			curr = 0;
		}
		return rv;
	}

	/*20170520 1721*/
	/*         1740*/
	/*AC       1753*/
	/*totally rewritten. Condition between adjacent array elem, use i, i-1. never use interval*/
	// int numberOfArithmeticSlices(vector<int>& A) {
	//     int i, rv = 0, len = 1;
	//     if (A.size() == 0 || A.size() == 1 || A.size() == 2) return rv;
	//     for (i = 2; i < A.size();i++){
	//         if ((A[i] - A[i - 1]) == (A[i - 1] - A[i - 2])) {
	//             len++;
	//             continue;
	//         }
	//         rv += (len - 1) * len / 2;
	//         len = 1;
	//     }
	//     rv += (len - 1) * len / 2;
	//     return rv;
	// }
};
