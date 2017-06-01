class Solution {
public:
	/*AC 20170530 0057*/
	vector<int> plusOne(vector<int>& digits) {
		int carry = 1;
		vector<int> res;
		for (int i = digits.size() - 1; i >= 0; i-- ) {
			int sum = digits[i] + carry;
			res.insert(res.begin(), sum%10);
			carry = sum/10;
		}
		if (carry) res.insert(res.begin(), 1);
		return res;
	}
};
