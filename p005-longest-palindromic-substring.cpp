class Solution {
public:
	/*20170717 1448 DP*/
	/*AC       1512*/
	string longestPalindrome(string s) {
		int n = s.size();
		if (!n) return "";
		vector<vector<bool>> p (n, vector<bool>(n, false));
		for (int i = 0; i < n; i++) p[i][i] = true;

		int maxlen = INT_MIN;
		string res;
		for (int i = 0, k; i < n; i++) {
			for (k = 0; i - k >= 0 && i + k < n; k++) {
				p[i - k][i + k] = (!k || p[i - k + 1][i + k - 1]) && s[i - k] == s[i + k];
				// printf("p[%d][%d]=%s\n", i - k, i + k, p[i - k][i + k]?"true":"false");
				if (!p[i - k][i + k]) break;
			}

			if (2 * k - 1 > maxlen) {
				maxlen = 2 * k - 1;
				res = s.substr(i - k + 1, 2 * k - 1);
			}

			for (k = 0; i - k >= 0 && i + k + 1 < n; k++) {
				p[i - k][i + k + 1] = (!k || p[i - k + 1][i + k]) && (s[i - k] == s[i + k + 1]);
				// printf("p[%d][%d]=%s\n", i - k, i + k + 1, p[i - k][i + k + 1]?"true":"false");
				if (!p[i - k][i + k + 1]) break;
			}

			if (k * 2 > maxlen) {
				maxlen = 2 * k;
				res = s.substr(i - k + 1, 2 * k);
			}
		}
		return res;
	}

	/*20170717 1349 manacher */
	/*AC       1441*/
	//     string longestPalindrome(string s) {
	//         int n = s.size();
	//         if (!n) return "";
	//         int maxlen = INT_MIN;
	//         string res;
	//         vector<int> palin (2 * n + 1, 0);
	//         // filling palin[]
	//         // loop invariant: even elem left to palin[i] is filled.
	//         for (int i = 0, k, c = 0, r = 0, l = 0; i <= 2 * n; i++) {
	//             // printf("c = %d, r = %d, ", c, r);
	//             if (i < r)
	//                 palin[i] = min(palin[2 * c - i], r);

	//             for (k = palin[i]; i - k >= 0 && i + k <= 2*n; k++) {
	//                 if ((i + k) % 2 && s[(i - k - 1) / 2] != s[(i + k - 1)/2]) break;
	//             }
	//             k--;
	//             palin[i] = k;

	//             if (i + k - 1> r) {
	//                 c = i;
	//                 r = i + k - 1;
	//             }
	//             // printf("palin[%d]= %d\n", i, palin[i]);
	//             if (palin[i] > maxlen) {
	//                 res = s.substr((i - k)/2, k);
	//                 maxlen = palin[i];
	//                 // printf("  res=%s\n", res.c_str());
	//             }
	//         }
	//         return res;
	//     }

	/*20170705 1540*/
	/*AC       1626*/
	//     string longestPalindrome(string s) {
	//         vector<char> charv;
	//         vector<int> cntv;
	//         for (int i = 0, cnt = 1; i < s.size(); i++) {
	//             if (i == s.size() - 1 || s[i] != s[i + 1]){
	//                 charv.push_back(s[i]);
	//                 cntv.push_back(cnt);
	//                 cnt = 1;
	//             } else
	//                 cnt++;
	//         }

	//         string candstr = "";
	//         for (int i = 0; i < charv.size(); i++) {
	//             string tmpstr(cntv[i], charv[i]);
	//             for(int k = 1; i - k >= 0 && i + k <charv.size(); k++){
	//                 if (charv[i - k] != charv[i + k]) break;
	//                 int idx = cntv[i - k] < cntv[i + k]? i - k: i + k;
	//                 tmpstr = string(cntv[idx], charv[idx]) + tmpstr + string(cntv[idx], charv[idx]);
	//                 if (cntv[i - k] != cntv[i + k]) break;
	//             }
	//             if (candstr.size() < tmpstr.size()) candstr = tmpstr;
	//         }
	//         return candstr;
	//     }

};
