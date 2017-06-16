class Solution {
public:
	/*20170614 2307*/
	/*AC       2326*/
	/*Note: "0" is no 0, ASCII conversion..*/
	string addBinary(string a, string b) {
		string res = "";
		int i = a.size() - 1, j = b.size() - 1, carry = 0;
		while (i >= 0 || j >= 0 || carry) {
			cout <<  i << " " << j << " ";
			int da = i >= 0 ? a[i--] - '0' : 0;
			int db = j >= 0 ? b[j--] - '0': 0;
			cout  << da <<  " " << db << " " << carry << " ";
			int sum = da + db + carry;
			cout << sum << "\n";
			res = to_string(sum % 2) + res;
			carry = sum / 2;
		}
		return res;
	}
};
