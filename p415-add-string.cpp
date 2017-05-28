class Solution {
public:
	/*20170524 0056*/
	/*AC       0108*/
	string addStrings(string num1, string num2) {
		int carry = 0, s1 = num1.size(), s2 = num2.size();
		string s = "";
		for (int i = 0; i < max(num1.size(), num2.size()) || carry ; i++) {
			int a1 = (s1 - 1 - i >= 0) ? (num1[s1 - 1 - i] - '0') : 0;
			int a2 = (s2 - 1 - i >= 0) ? (num2[s2 - 1 - i] - '0') : 0;
			int sum = a1 + a2 + carry;
			s = char(sum % 10 + '0') + s;
			carry = sum / 10;
		}
		return s;
	}
};
