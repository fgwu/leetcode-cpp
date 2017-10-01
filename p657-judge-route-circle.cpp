class Solution {
public:
	/*20170930 1428*/
	/*AC 1436*/
	bool judgeCircle(string moves) {
		int i = 0, j = 0;
		for (char c: moves) {
			switch(c) {
			case 'L':
				i--;
				break;
			case 'R':
				i++;
				break;
			case 'U':
				j++;
				break;
			case 'D':
				j--;
				break;
			default:
				return false;
			}
		}
		return !i && !j;
	}
};
