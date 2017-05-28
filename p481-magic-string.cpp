class Solution {
public:
	/*seen solution, using short C++ and string operation */
	int magicalString(int n) {
		string s = "122";
		int i = 2;
		while (s.size() < n)
			s += string(s[i++] - '0', (s.back() - '0') ^ 3 + '0');
		return count(s.begin(), s.begin() + n, '1');
	}



	/*20170526 2113*/
	/*AC       2202*/
	// int magicalString(int n) {
	//     int i = 0, res = 0;
	//     string s = "1";
	//     while (s.size() < n) {
	//         int last_size = s.size();
	//         for (; i < last_size; i++) {
	//             // cout << "start: i = " << i << "\n";
	//             char c = s[s.size() - 1];
	//             // cout << "s[" << i << "]=" << s[i] << "\n";
	//             if (s[i] == '2') { s += c; /*cout << "one more " << c << "\n"; */}
	//             s += c == '1'? '2' : '1';
	//             // cout << "switch to " << (c == '1'? '2' : '1') << "\n";
	//             // cout << "end: i = " << i << "\n";
	//         }
	//     }
	//     // cout << s << "\n";
	//     for (int i = 0; i < n; i++) if (s[i] == '1') res++;
	//     return res;
	// }
};
