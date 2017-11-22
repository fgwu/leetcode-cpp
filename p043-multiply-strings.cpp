class Solution {
public:
	/*20171119 0740*/
	/*AC       0750*/
	void add(string& rv, string& tmp, int offset) { // add("9", "12")
		int carry = 0;
		for (int i = 0; i + offset < rv.size() || i < tmp.size() || carry; i++){
			int s = i + offset >= rv.size() ? 0 : rv[rv.size() - 1 - i - offset] - '0';
			int t = i          >= tmp.size() ? 0 : tmp[tmp.size() - 1 - i]          - '0';
			int sum = s + t + carry;
			carry = sum / 10;
			sum %= 10;
			if (i + offset >= rv.size())
				rv = to_string(sum) + rv;
			else
				rv[rv.size() - 1 - i - offset] = sum + '0';
		}
	}

	string multiply(string num1, string num2) {
		string rv = "0";
		for (int i = 0; i < num1.size(); i++) {
			for (int j = 0; j < num2.size(); j++) {
				string tmp = to_string((num1[num1.size() - 1 - i] - '0') * (num2[num2.size() - 1 - j] - '0'));
				add(rv, tmp, i + j);
			}
		}
		int pos = rv.find_first_not_of('0');
		if (pos == string::npos) return "0";
		return rv.substr(pos);
	}

	/*20171118 1950*/
	/*restart  0134*/
	/*TLE      0736*/
	//     string add(string num1, string num2) { // add("9", "12")
	//         int carry = 0;
	//         string rv = "";
	//         for(int i = 0; i < num1.size() || i < num2.size() || carry; i++) {
	//             int a = i >= num1.size() ? 0 : num1[num1.size() - 1 - i] - '0';
	//             int b = i >= num2.size() ? 0 : num2[num2.size() - 1 - i] - '0';
	//             int sum = a + b + carry;
	//             carry = sum / 10; // 0
	//             // printf("a=%d b=%d sum=%d\n", a, b, sum);
	//             sum %= 10; // 2
	//             rv = to_string(sum) + rv; // "21"
	//         }
	//         int pos = rv.find_first_not_of('0');
	//         if (pos == string::npos) return "0";
	//         return rv.substr(pos);
	//     }

	//     string multiply(string num1, string num2) {
	//         string rv = "0";
	//         string post1 = "";
	//         for (int i = 0; i < num1.size(); i++, post1 += "0") {
	//             string post2 = "";
	//             for (int j = 0; j < num2.size(); j++, post2 += "0") {
	//                 string tmp = to_string((num1[num1.size() - 1 - i] - '0') * (num2[num2.size() - 1 - j] - '0'));
	//                 tmp += post1 + post2;
	//                 string sum = add(rv, tmp);
	//                 // cout << tmp << " " << sum << "\n";
	//                 swap(sum, rv);
	//             }
	//         }
	//         return rv;
	//     }
};
