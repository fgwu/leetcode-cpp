class Solution {
public:
	/*20170710 2308*/
	/*20170712 1319 restart*/
	/*20170810 1524 restart*/
	/*AC       1612*/
	int calculate(string s) {
		stack<int> is; //integer stack
		stack<char> os; //opr stack
		unordered_map<char, int> prec;
		prec['+'] = 1;
		prec['-'] = 1;
		prec['*'] = 2;
		prec['/'] = 2;
		s += "+";
		for (int i = 0; i < s.size();) {
			char c = s[i];
			if (isspace(s[i])) {
				i++;
				continue;
			}
			if (isdigit(s[i])) {
				int tmp = 0;
				for(; isdigit(s[i]); i++)
					tmp = tmp * 10 + s[i] - '0';

				is.push(tmp);
				continue;
			}
			if (os.empty() || prec[os.top()] < prec[c]) {
				os.push(c);
				i++;
				continue;
			}

			int n2 = is.top();
			is.pop();
			int n1 = is.top();
			is.pop();
			char opr = os.top();
			os.pop();
			switch (opr) {
			case '+':
				is.push(n1 + n2);
				break;
			case '-':
				is.push(n1 - n2);
				break;
			case '*':
				is.push(n1 * n2);
				break;
			case '/':
				is.push(n1 / n2);
				break;
			default:
				assert(0);
			}
		}
		return is.top();
	}
};
