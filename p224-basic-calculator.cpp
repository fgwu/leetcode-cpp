class Solution {
public:
	int calculate(string s) {
		int rv = 0, sign = 1, num = 0;
		stack<pair<int, int>> state;
		// cout << ' ';
		for (auto c: s) {
			// cout << ' ' << rv << ' ' << sign << ' ' << num << '\n' << c;
			if (isspace(c)) continue;
			if (isdigit(c)) {
				num = num * 10 + c - '0';
				continue;
			}

			if (c == '+' || c == '-') {
				rv += sign * num;
				num = 0;
				sign = c == '+' ? 1 : -1;
				continue;
			}

			if (c == '(') {
				state.emplace(rv, sign);
				rv = 0;
				sign = 1;
			} else {
				rv += sign * num;
				num = rv;
				auto p = state.top();
				state.pop();
				rv = p.first;
				sign = p.second;
				// rv += sign * num;
				// sign = 1;
				// num = 0;
			}
		}
		return rv + sign * num;
	}

	/*20171213  2141*/
	//     int calculate(string s) {
	//         // cout << s << "\n";
	//         int rp = s.find(')');
	//         if (rp != string::npos) {
	//             int lp = s.rfind('(', rp);
	//             string val = to_string(calculate(s.substr(lp + 1, rp - lp - 1)));
	//             return calculate(s.replace(lp, rp + 1 - lp, val));
	//         }


	//         int rv = 0, last = 0, pos, last_sign = 1;

	//         while (true) {
	//             // cout << s << " " << last << " "<< pos<< "\n";
	//             pos = s.find_first_of("0123456789", last);
	//             pos = s.find_first_not_of("0123456789", pos);
	//             rv += last_sign * stoi(s.substr(last, pos - last));

	//             pos = s.find_first_of("+-", pos);
	//             if (pos == string::npos) break;

	//             last_sign = s[pos] == '+'? 1 : -1;

	//             last = pos + 1;
	//         }


	//         return rv;
	//     }
};
