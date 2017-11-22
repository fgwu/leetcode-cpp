class Solution {
public:
    /*20171121 0058*/
    /*AC       0107*/
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        assert(A.size() && A[0].size() && B.size() && B[0].size() && A[0].size() == B.size());
        
        int m = A.size(), n = A[0].size(), l = B[0].size();
        
        vector<vector<int>> rv (m, vector<int>(l, 0));
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++) {
                if (!A[i][j]) continue;
                for (int k = 0; k < l; k++) {
                    rv[i][k] += A[i][j] * B[j][k];
                }
            }
        }
        
        return rv;
    }
};