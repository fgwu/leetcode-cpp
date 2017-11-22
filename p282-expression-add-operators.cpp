class Solution {
public:
	/*AC   20171119 2319*/
	void dfs(string& num, long target, int pos, vector<string> &rv, string partial, long last_res, long last_opd, char last_opr) {
		// printf("pos=%d, %s\n", pos, partial.c_str());
		if (pos == num.size()) {
			// printf("%s=%d\n", partial.c_str(), last_res);
			if (last_res == target) rv.push_back(partial);
			return;
		}

		for (int i = pos + 1; i <= num.size(); i++) {
			string opd_str = num.substr(pos, i - pos);
			// cout << "  " << pos << " " << i << " " << opd_str << "\n";
			long opd = stol(opd_str);
			if (to_string(opd).size() != opd_str.size()) continue;
			//+
			dfs(num, target, i, rv, partial + '+' + opd_str, last_res + opd, opd, '+');
			dfs(num, target, i, rv, partial + '-' + opd_str, last_res - opd, opd, '-');
			switch(last_opr) {
			case '*':
			case '#':
				dfs(num, target, i, rv, partial + '*' + opd_str, last_res * opd, opd, '*');
				break;
			case '+':
				dfs(num, target, i, rv, partial + '*' + opd_str, last_res - last_opd + last_opd * opd, last_opd * opd, '+');
				break;
			case '-':
				dfs(num, target, i, rv, partial + '*' + opd_str, last_res + last_opd - last_opd * opd, last_opd * opd, '-');
				break;
			default:
				assert(0);
			}
		}
	}


	vector<string> addOperators(string num, int target) {
		vector<string> rv;
		for (int i = 1; i <= num.size(); i++) {
			string opd_str = num.substr(0, i);
			long opd = stol(opd_str);
			if (to_string(opd).size() != opd_str.size()) continue;
			dfs(num, target, i, rv, opd_str, opd, 1, '#');
		}
		// dfs(num, target, 0, rv, "", 1, 1, '*'); // assume we start from 1 *
		return rv;
	}

	/*20171119 1540*/
	/*         1620*/
	/*TLE      1653*/
	//     string mk_str(string& num, string& ops) {
	//         string rv;
	//         for (int i = 0; i < num.size(); i++) {
	//             rv += num[i];
	//             if (num[i])
	//             if (ops[i] != ' ') rv += ops[i];
	//         }
	//         return rv;
	//     }

	//     int binary_operation(int a, int b, char opr, bool &illegal) {
	//         switch(opr) {
	//             case ' ':
	//                 if (a == 0) illegal = true;
	//                 return a * 10 + b;
	//             case '+':
	//                 return a + b;
	//             case '-':
	//                 return a - b;
	//             case '*':
	//                 return a * b;
	//             default:
	//                 assert(0);
	//         }
	//     }

	//     bool calc(string& num, string& ops, int target) {
	//         ops.push_back('#');
	//         stack<char> os;
	//         stack<int> ns;
	//         unordered_map<char, int> prec = {{' ', 3}, {'*', 2}, {'+', 1}, {'-', 1}, {'#', 0}};
	//         bool illegal = false;

	//         for (int i = 0; i < num.size(); i++) {
	//             int a = num[i] - '0';
	//             char o = ops[i];
	//             // printf(" a=%d, o=%c\n", a, o);
	//             while (!os.empty() && prec[o] <= prec[os.top()]) {
	//                 a = binary_operation(ns.top(), a, os.top(), illegal);
	//                 ns.pop();
	//                 os.pop();
	//             }

	//             ns.push(a);
	//             os.push(o);
	//         }
	//         ops.pop_back();
	//         return !illegal && ns.top() == target;
	//     }

	//     void bt(string& num, string& ops, int target, vector<string>& rv ) {
	//         if (ops.size() == num.size() - 1) {
	//             // cout << mk_str(num, ops) << "=" << calc(num, ops, target);
	//             if (calc(num, ops, target)) {
	//                 rv.push_back(mk_str(num, ops));
	//                 // cout << " added ";
	//             }
	//             // cout << "\n";
	//             return;
	//         }

	//         vector<char> operators = {' ', '+', '-', '*'};
	//         for (int i = 0; i < operators.size(); i++) {
	//             ops.push_back(operators[i]);
	//             bt(num, ops, target, rv);
	//             ops.pop_back();
	//         }
	//     }

	//
