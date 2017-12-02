class Solution {
public:
	/*try left right*/
	/*AC    0009*/
	int longestValidParentheses(string s) {
		int left = 0, right = 0, pos = -1;
		int rv = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				left++;
			} else {
				right++;
				if (left == right) {
					rv = max(rv, i - pos);
				} else if (left < right) {
					left = right = 0;
					pos = i;
				}
			}
		}

		pos = s.size();
		left = right = 0;
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] == ')') {
				right++;
			} else {
				left++;
				if (left == right) {
					rv = max(rv, pos - i);
				} else if (right < left) {
					left = right = 0;
					pos = i;
				}
			}
		}

		return rv;
	}

	/*20171128 1731*/
	/*AC       2336*/
	// int longestValidParentheses(string s) {
	//     stack<int> cs; // the location
	//     int rv = 0, cnt = 0;
	//     cs.push(-1);
	//     for (int i = 0; i < s.size(); i++) {
	//         if (s[i] == '(')
	//             cs.push(i);
	//         else { // ')'
	//             cs.pop();
	//             if (cs.empty()) {
	//                 cs.push(i);
	//             } else {
	//                 int pos = cs.top();
	//                 rv = max(rv, i - pos);
	//             }
	//         }
	//     }
	//     return rv;
	// }
};
