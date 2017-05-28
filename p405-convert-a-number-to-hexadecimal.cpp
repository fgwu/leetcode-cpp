class Solution {
public:
	/*AC 20170524 0131*/
	string toHex(int num) {
		if (!num) return "0";
		string s = "";
		int mask = 15;
		for (int i = 0; num && i < 32; num >>= 4, i += 4) {
			int tmp = num & mask;
			char c;
			if (tmp >= 10) c = 'a' + tmp - 10;
			else c = '0' + tmp;
			s = c + s;
		}
		return s;
	}
};
