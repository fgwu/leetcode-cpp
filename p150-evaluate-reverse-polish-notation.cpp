class Solution {
public:
	/*recursive*/
	/*AC 0200*/
	int evalRPN(vector<string>& tokens) {
		string tok = tokens.back();
		tokens.pop_back();
		if (tok.size() != 1 || isdigit(tok[0])) return atoi(tok.c_str());
		int n1 = evalRPN(tokens);
		int n2 = evalRPN(tokens);
		switch (tok[0]) {
		case '+':
			return n2 + n1;
			break;
		case '-':
			return n2 - n1;
		case '*':
			return n2 * n1;
		case '/':
			return n2 / n1;
		default:
			assert(0);
		}
		return 0;
	}


	/*20170813 0122*/
	/*AC 0145*/
	/*be careful with negative numbers.*/
	//     int evalRPN(vector<string>& tokens) {
	//         stack<int> s;
	//         for (auto &tok: tokens) {
	//             if (isdigit(tok[0])) {
	//                 int tmp = 0;
	//                 for (auto d: tok)
	//                     tmp = tmp * 10 + d - '0';
	//                 s.push(tmp);
	//                 continue;
	//             }

	//             if (tok.size() >= 2 && isdigit(tok[1])) {
	//                 int tmp = 0;
	//                 for (int i = 1; i < tok.size(); i++)
	//                     tmp = tmp * 10 + tok[i] - '0';
	//                 switch (tok[0]) {
	//                     case '+':
	//                         s.push(tmp);
	//                         break;
	//                     case '-':
	//                         s.push(-tmp);
	//                         break;
	//                     default:
	//                         assert(0);
	//                 }
	//                 continue;
	//             }

	//             assert(s.size() >= 2);
	//             int n1 = s.top();
	//             s.pop();
	//             int n2 = s.top();
	//             s.pop();
	//             switch(tok[0]) {
	//                 case '+':
	//                     s.push(n2 + n1);
	//                     break;
	//                 case '-':
	//                     s.push(n2 - n1);
	//                     break;
	//                 case '*':
	//                     s.push(n2 * n1);
	//                     break;
	//                 case '/':
	//                     s.push(n2 / n1);
	//                     break;
	//                 default:
	//                     assert(0);
	//             }
	//         }
	//         return s.top();
	//     }
};
