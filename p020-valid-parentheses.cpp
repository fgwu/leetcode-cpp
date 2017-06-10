class Solution {
public:
	/*20170609 1150*/
	/*AC       1157*/
	/*check whether the stack is emtpy before top/pop */
	bool isValid(string s) {
		stack<char> mystack;
		unordered_map<char, char> closes = {
			{')', '('},
			{']', '['},
			{'}', '{'}};
		for (const auto c:s) {
			if (!mystack.empty() && closes[c] == mystack.top()) {mystack.pop(); continue;}
			mystack.push(c);
		}
		return mystack.empty();
	}
};
