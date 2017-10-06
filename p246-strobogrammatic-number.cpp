class Solution {
public:
	/*20171006 1322*/
	/*AC       1330*/
	bool isStrobogrammatic(string num) {
		if (!num.size()) return false;
		vector<int> m = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
		for (int i = 0; i < (num.size() + 1) / 2; i++) {
			int d1 = num[i] - '0';
			int d2 = num[num.size() - 1 - i] - '0';
			if (m[d1] != d2) return false;
		}
		return true;
	}
};
