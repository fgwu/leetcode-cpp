class Solution {
public:
	/*20170605 2121*/
	/*AC       2123*/
	int countSegments(string s) {
		int res = 0, i;
		s.push_back(' ');
		for (i = 0; i < s.size(); i++)
			if (s[i] != ' ' & s[i + 1] == ' ') res++;
		return res;
	}



	/*20170605 2117*/
	/*AC       2120*/
	// int countSegments(string s) {
	//     int res = 0, i;
	//     for (int i = 0; i < s.size(); i++)
	//         if (s[i] != ' ' && (!i || s[i - 1] == ' ')) res++;
	//     return res;
	// }



	/*20170605 1919*/
	/*AC 2113*/
	// int countSegments(string s) {
	//     int res = 0, i = 0;
	//     while (true) {
	//         while (i < s.size() && s[i] == ' ') i++;
	//         if (i == s.size()) break;
	//         while (i < s.size() && s[i] != ' ') i++;
	//         res++;
	//         if (i == s.size()) break;
	//     }
	//     return res;
	// }
};
