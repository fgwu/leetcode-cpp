class Solution {
public:
	/*20171119 0942*/
	/*20171128 1540 restart*/
	/*AC       1720*/
	bool valid(const string &s) {
		int cnt = 0;
		for (auto c: s) {
			switch(c) {
			case '(':
				cnt++;
				break;
			case ')':
				if (--cnt < 0) return false;
				break;
			default:
				;
			}
		}
		return cnt == 0;
	}

	vector<string> removeInvalidParentheses(string s) {
		unordered_set<string> tmp;
		unordered_set<string> frontier;
		frontier.insert(s);

		while(true) {
			unordered_set<string> next;
			for (const auto &str: frontier) {
				// cout << "\"" << str << "\"\n";
				if (valid(str))
					tmp.insert(str);
				else {
					for (int i = 0; i < str.size(); i++) {
						if (s[i] != '(' && s[i] != ')') continue;
						string ss(str);
						ss.erase(i, 1);
						next.insert(ss);
					}
				}
			}
			// printf("-------------\n");
			if (tmp.size()) break;
			swap(frontier, next);
		}

		vector<string> rv;
		for (auto & str:tmp)
			rv.push_back(str);
		return rv;
	}
};
