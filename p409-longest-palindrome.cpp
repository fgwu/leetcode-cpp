class Solution {
public:
	/*20170520 1948*/
	/*AC       1955*/
	int longestPalindrome(string s) {
		vector<int> map(52, 0);
		int rv = 0;
		for (const auto & c:s) {
			if (c >= 'a' && c <= 'z') map[c - 'a']++;
			if (c >= 'A' && c <= 'Z') map[26 + c - 'A']++;
		}

		for (const auto & cnt:map){
			if (cnt%2 == 0) {
				rv += cnt;
				continue;
			}

			if (rv % 2 == 0)
				rv += cnt;
			else
				rv += cnt - 1;

		}
		return rv;
	}
};
