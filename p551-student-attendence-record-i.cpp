class Solution {
public:
	/*AC 20170523 2319*/
	bool checkRecord(string s) {
		int cnt_l = 0, cnt_a = 0;
		for (const auto & c:s) {
			if (c == 'P') {
				cnt_l = 0;
				continue;
			}
			if (c == 'A') {
				if (++cnt_a == 2) return false;
				cnt_l = 0;
				continue;
			}
			if (c == 'L') if (++cnt_l == 3) return false;
		}

		return true;
	}
};
