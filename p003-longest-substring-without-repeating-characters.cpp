class Solution {
public:
	/*AC 20170621 1551*/
	/*O(n) Time, O(1) Space*/
	int lengthOfLongestSubstring(string s) {
		vector<int> map(256,-1);
		int res = 0, last = 0;
		for (int i = 0; i < s.size(); i++) {
			last = min(last + 1, i - map[s[i]]);
			res = max(last, res);
			map[s[i]] = i;
		}
		return res;
	}

	/*20170621 1512*/
	/*AC       1536*/
	/*O(n^2) Time, O(1) space*/
	// int lengthOfLongestSubstring(string s) {
	//     int res = 0, last = 0;
	//     for (int i = 0; i < s.size(); i++) {
	//         int pos = s.find(s[i], i - last);
	//         if (pos != i)
	//             last = i - pos;
	//         else
	//             if (++last > res) res = last;
	//     }
	//     return res;
	// }
};
