class Solution {
public:
	/*AC opt*/
	int minCut(string s) {
		int n = s.size();
		vector<int> t (n + 1, INT_MAX);
		for (int i = 0; i <= n; i++) t[i] = i - 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; j++)
				t[i + j + 1] = min(t[i + j + 1], 1 + t[i - j]);
			for (int j = 0; i - j >= 0 && i + j + 1 < n && s[i - j] == s[i + j + 1]; j++)
				t[i + j + 2] = min(t[i + j + 2], 1 + t[i - j]);
		}
		return t[n];
	}

	/*sln 1517*/
	// int minCut(string s) {
	//     int n = s.size();
	//     vector<int> t (n + 1, INT_MAX);
	//     vector<vector<bool>> m(n, vector<bool>(n, false));
	//     t[0] = -1;
	//     for (int i = 1; i <= n; i++) {
	//         for (int j = 0; j <= i - 1; j++) {
	//             if (s[j] == s[i - 1] && (j >= i - 2 || m[j + 1][i - 2])) {
	//                 t[i] = min(t[i], 1 + t[j]);
	//                 m[j][i - 1] = true;
	//             }
	//         }
	//     }
	//     return t[n];
	// }

	/*sln remove the external check Palin Function */
	/*AC  1459*/
	// int minCut(string s) {
	//     int n = s.size();
	//     vector<int> t (n + 1, INT_MAX);
	//     vector<vector<int>> m(n, vector<int>(n, -1));
	//     t[0] = -1;
	//     for (int i = 1; i <= n; i++) {
	//         for (int j = 0; j <= i - 1; j++) {
	//             for (int start = j, end = i - 1;; start++, end--) {
	//                 if (start >= end) {
	//                     m[j][i - 1] = 1;
	//                     break;
	//                 }
	//                 if (m[start][end] != -1) {
	//                     m[j][i - 1]  = m[start][end];
	//                     break;
	//                 }
	//                 if (s[start] != s[end]) {
	//                     m[j][i - 1] = 0;
	//                     break;
	//                 }
	//             }
	//             if (m[j][i - 1])
	//                 t[i] = min(t[i], 1 + t[j]);
	//         }
	//     }
	//     return t[n];
	// }
	/*AC */
	//     bool checkPalin(string& s, int start, int end, vector<vector<int>>& m) {
	//         if (start >= end) return true;
	//         if (m[start][end] != -1) return m[start][end]; // start < end
	//         // now m[start][end] unknown;
	//         if (s[start] != s[end]) {
	//             m[start][end] = 0;
	//             return m[start][end];
	//         }
	//         if(checkPalin(s, start + 1, end - 1, m))
	//             m[start][end] = 1;
	//         else
	//             m[start][end] = 0;

	//         return m[start][end];
	//     }

	//     int minCut(string s) {
	//         vector<int> t (s.size(), INT_MAX);

	//         //  m[i, j], s[i..j] is palin? -1 unknow, 0 no, 1 yes
	//         vector<vector<int>> m(s.size(), vector<int>(s.size(), -1));

	//         // loop invariant: all problem of size [0, i) is solved.
	//         // t[0.. i - 1) filled.
	//         // s[i] is the current newly added element
	//         for (int i = 0; i < s.size(); i++) {
	//             //j starting point of the possible palindrome.
	//             if (checkPalin(s, 0, i, m)) {
	//                 t[i] = 0;
	//                 continue;
	//             }
	//             for (int j = 1; j <= i; j++) {
	//                 if (checkPalin(s, j, i, m)) t[i] = min(t[i], 1 + t[j - 1]);
	//             }
	//         }
	//         return t[s.size() - 1];
	//     }



	/*20170714 Fri 1042*/
	/*TLE          1113*/
	//     bool checkPalin(string s, int start, int end) {
	//         while (start < end)
	//             if (s[start++] != s[end--]) return false;
	//         return true;
	//     }

	//     int minCut(string s) {
	//         vector<int> t (s.size(), INT_MAX);
	//         // loop invariant: all problem of size [0, i) is solved.
	//         // t[0.. i - 1) filled.
	//         // s[i] is the current newly added element
	//         for (int i = 0; i < s.size(); i++) {
	//             //j starting point of the possible palindrome.
	//             if (checkPalin(s, 0, i)) {
	//                 t[i] = 0;
	//                 continue;
	//             }
	//             for (int j = 1; j <= i; j++) {
	//                 if (checkPalin(s, j, i)) t[i] = min(t[i], 1 + t[j - 1]);
	//             }
	//         }
	//         return t[s.size() - 1];
	// }
	/*DP knowing problem of size k - 1, try problem k.
	  Try every possible palindrone that may result in by adding s[k]*/
};
