class Solution {
public:
	/*20170805 1:04 try consice solution */
	vector<vector<string>> partition(string s) {
		if (!s.size()) return vector<vector<string>>();
		vector<vector<string>> res;
		unordered_map<int, vector<string>> d;
		stack<pair<vector<string>, int>> my_stack;
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; i - j >= 0 && i + j < s.size(); j++) {
				if (s[i - j] != s[i + j]) break;
				d[i - j].push_back(s.substr(i - j, j * 2 + 1));
			}

			for (int j = 0; i - j >= 0 && i + j + 1 < s.size(); j++) {
				if (s[i - j] != s[i + j + 1]) break;
				d[i - j].push_back(s.substr(i - j, j * 2 + 2));
			}
		}

		my_stack.push(make_pair(vector<string>(), 0));

		while(!my_stack.empty()) {
			auto p = my_stack.top();
			my_stack.pop();
			if (p.second == s.size()) {
				res.push_back(p.first);
				continue;
			}

			for (auto &palin: d[p.second]) {
				my_stack.push(make_pair(p.first, p.second + palin.size()));
				my_stack.top().first.push_back(palin);
			}
		}

		return res;
	}
};

// class Solution {
// private:
//     string s;
//     unordered_map<int, vector<string>> d;
// public:
//     /*20170804 2355*/
//     /*AC       0048*/
//     /*dictionary optimization 1:03*/
//     bool check(int start, int end) {
//         while(start < end - 1) {
//             if (s[start++] != s[end-- - 1]) return false;
//         }
//         return true;
//     }

//     vector<string> getLastPalins(int end) {
//         // if (d.count(end))
//             return d[end];
// //         vector<string> tmp;
// //         for (int p = end - 1; p >= 0; p--) {
// //             if (check(p, end))
// //                 tmp.push_back(s.substr(p, end - p));
// //         }

// //         d[end] = tmp;
// //         return tmp;
//     }


//     vector<vector<string>> partition(size_t end){
//         vector<vector<string>> res;
//         if (end == 0) {
//             // vector<string> tmp = {""};
//             res.push_back(vector<string>());
//             return res;
//         }
//         for (auto& palin: getLastPalins(end)) {
//             printf("%d]", end);
//             for (int i = end; i <= s.size(); i++) printf(" ", end);
//             printf("palin <'%s'>\n", palin.c_str());
//             for (auto& partial: partition(end - palin.size())) {
//                 res.push_back(partial);
//                 res.back().push_back(palin);
//             }
//         }
//         return res;
//     }

//     void preprocess() {
//         for (int i = 0; i < s.size(); i++) {
//             for (int j = 0; i - j >= 0 && i + j < s.size(); j++) {
//                 if (s[i - j] != s[i + j]) break;
//                 d[i + j + 1].push_back(s.substr(i - j, j * 2 + 1));
//             }

//             for (int j = 0; i - j >= 0 && i + j + 1 < s.size(); j++) {
//                 if (s[i - j] != s[i + j + 1]) break;
//                 d[i + j + 2].push_back(s.substr(i - j, j * 2 + 2));
//             }
//         }
//     }

//     vector<vector<string>> partition(string s) {
//         if (!s.size()) return vector<vector<string>>();
//         this->s = s;
//         preprocess();
//         return partition(s.size());
//     }
// };
