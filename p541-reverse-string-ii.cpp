class Solution {
public:
	/*20170523 2334 one line solution*/
	/*20170523 2336*/
	string reverseStr(string s, int k) {
		for (int i = 0; i < s.size(); i += 2 * k) reverse(s.begin() + i, min(s.end(), s.begin() + k + i));
		return s;
	}



	/*20170523 2322*/
	/*AC       2333*/
	// void helper(string &s, int start, int end) {
	//     if (end >= s.size()) end = s.size() - 1;
	//     int cnt = (end - start) / 2;
	//     for (int i = 0; i <= cnt; i++) swap(s[start + i], s[end - i]);
	// }

	// string reverseStr(string s, int k) {
	//     for (int i = 0; i < s.size(); i += 2 * k) helper(s, i, i + k - 1);
	//     return s;
	// }
};
