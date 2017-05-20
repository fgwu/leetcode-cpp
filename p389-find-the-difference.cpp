class Solution {
public:
	/*AC      14:47*/
	/*note: 1) sort(beginning itr, ending itr)   2) XOR is a good way of finding single elem*/
	char findTheDifference(string s, string t) {
		char rv = 0;
		for (auto & c: s) rv^=c;
		for (auto & c: t) rv^=c;
		return rv;
	}



	/*20170518 14:34*/
	/*AC       14:44*/
	// char findTheDifference(string s, string t) {
	//     int i;
	//     sort(s.begin(), s.end());
	//     sort(t.begin(), t.end());
	//     for(i = 0; i<s.size(); i++)
	//         if (t[i] != s[i]) return t[i];
	//     return t[i];
	// }
};
