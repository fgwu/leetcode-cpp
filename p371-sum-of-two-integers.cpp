class Solution {
public:
	/*20170518 14:50*/
	/*AC       15:20*/
	int getSum(int a, int b) {
		int c = a&b;
		int s = a^b;
		while (c) {
			a = c << 1;
			b = s;
			c = a&b;
			s = a^b;
		}
		return s;
	}
};
