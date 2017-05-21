class Solution {
public:
	/*20170520 1942*/
	/*AC       1947*/
	string convertToBase7NonNeg(int num) {
		if (!num) return "0";
		string s = "";
		while (num) {
			s = to_string(num%7) + s;
			num/=7;
		}
		return s;
	}

	string convertToBase7(int num) {
		if (num < 0) return "-" + convertToBase7NonNeg(-num);
		return convertToBase7NonNeg(num);
	}
};
