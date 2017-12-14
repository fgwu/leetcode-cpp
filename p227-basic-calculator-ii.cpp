class Solution {
	int calc(int a, char op, int b) {
		int rv;
		switch(op) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
		default:
			assert(0);
		}
	}
public:
	/*20171213 2343*/
	/*AC       0005*/
	int calculate(string s) {
		unordered_map<char, int>prec = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
		int a = 0, b = 0, num = 0;
		char op1 = '+', op2 = '+';
		s += "+0+0";
		for (char c : s) {
			if (isspace(c)) continue;
			if (isdigit(c)) {
				num = num * 10 + c - '0';
				continue;
			}

			if (prec[op2] > prec[op1]) {
				b = calc(b, op2, num);
				op2 = c;
			} else {
				a = calc(a, op1, b);
				b = num;
				op1 = op2;
				op2 = c;
			}
			num = 0;
		}

		return a;
	}
};



// class Solution {
// public:
// 	/*20170710 2308*/
// 	/*20170712 1319 restart*/
// 	/*20170810 1524 restart*/
// 	/*AC       1612*/
// 	int calculate(string s) {
// 		stack<int> is; //integer stack
// 		stack<char> os; //opr stack
// 		unordered_map<char, int> prec;
// 		prec['+'] = 1;
// 		prec['-'] = 1;
// 		prec['*'] = 2;
// 		prec['/'] = 2;
// 		s += "+";
// 		for (int i = 0; i < s.size();) {
// 			char c = s[i];
// 			if (isspace(s[i])) {
// 				i++;
// 				continue;
// 			}
// 			if (isdigit(s[i])) {
// 				int tmp = 0;
// 				for(; isdigit(s[i]); i++)
// 					tmp = tmp * 10 + s[i] - '0';

// 				is.push(tmp);
// 				continue;
// 			}
// 			if (os.empty() || prec[os.top()] < prec[c]) {
// 				os.push(c);
// 				i++;
// 				continue;
// 			}

// 			int n2 = is.top();
// 			is.pop();
// 			int n1 = is.top();
// 			is.pop();
// 			char opr = os.top();
// 			os.pop();
// 			switch (opr) {
// 			case '+':
// 				is.push(n1 + n2);
// 				break;
// 			case '-':
// 				is.push(n1 - n2);
// 				break;
// 			case '*':
// 				is.push(n1 * n2);
// 				break;
// 			case '/':
// 				is.push(n1 / n2);
// 				break;
// 			default:
// 				assert(0);
// 			}
// 		}
// 		return is.top();
// 	}
// };
