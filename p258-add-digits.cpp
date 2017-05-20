class Solution {
public:
	/*20170518 15:30*/
	/*AC       15:34*/
	int addDigits(int num) {
		if (!num) return 0;
		return num%9? num%9: 9;
	}
};
