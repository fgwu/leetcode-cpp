class Solution {
public:
	/*20170608 1421*/
	/*AC  1438*/
	string countAndSay(int n) {
		string s = "1";
		while(--n){
			string tmp = "";
			s += "s"; // sentinel
			int cnt = 0, j = 0;
			for (int j = 0; j < s.size(); j++) {
				if (!j || s[j] == s[j - 1]) { cnt++; continue; }
				tmp += to_string(cnt);
				cnt = 1;
				tmp += s[j - 1];
			}
			s = tmp;
			// cout << s <<"\n";
		}
		return s;
	}
};
