class Solution {
public:
	/*20170705 1540*/
	/*AC       1626*/
	string longestPalindrome(string s) {
		vector<char> charv;
		vector<int> cntv;
		for (int i = 0, cnt = 1; i < s.size(); i++) {
			if (i == s.size() - 1 || s[i] != s[i + 1]){
				charv.push_back(s[i]);
				cntv.push_back(cnt);
				cnt = 1;
			} else
				cnt++;
		}

		string candstr = "";
		for (int i = 0; i < charv.size(); i++) {
			string tmpstr(cntv[i], charv[i]);
			for(int k = 1; i - k >= 0 && i + k <charv.size(); k++){
				if (charv[i - k] != charv[i + k]) break;
				int idx = cntv[i - k] < cntv[i + k]? i - k: i + k;
				tmpstr = string(cntv[idx], charv[idx]) + tmpstr + string(cntv[idx], charv[idx]);
				if (cntv[i - k] != cntv[i + k]) break;
			}
			if (candstr.size() < tmpstr.size()) candstr = tmpstr;
		}
		return candstr;
	}
};
