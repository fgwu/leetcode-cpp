class Solution {
public:
	/* use vector and swap */
	vector<string> letterCombinations(string digits) {
		vector<string> res;
		if (!digits.size()) return res;
		vector<string> mapping = {" ", "", "abc", "def", "hgi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		res.push_back("");
		for (auto d: digits){
			vector<string> tempres;
			for (auto& str: res)
				for (auto c: mapping[d - '0'])
					tempres.push_back(str + c);
			// res = tempres;
			res.swap(tempres);
		}
		return res;
	}


	/*iterative?   FIFO? the same?*/
	// vector<string> letterCombinations(string digits) {
	//     vector<string> res;
	//     if (!digits.size()) return res;
	//     vector<string> mapping = {" ", "", "abc", "def", "hgi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	//     queue<string> q;
	//     q.push("");
	//     for (int i = 0; i < digits.size(); i++){
	//         char d = digits[i];
	//         int size = q.size();
	//         while(size--) {
	//             string tmp = q.front();
	//             q.pop();
	//             for (auto c: mapping[d - '0']) {
	//                 if (i == digits.size() - 1)
	//                     res.push_back(tmp + c);
	//                 else
	//                     q.push(tmp + c);
	//             }
	//         }
	//     }
	//     return res;
	// }

	/*20170728 2206*/
	/*AC       2220*/
	//     void helper(string& digits, int idx, string& partial, vector<string>& mapping, vector<string>& res) {
	//         if (idx >= digits.size()) {
	//             res.push_back(partial);
	//             return;
	//         }
	//         for (auto c: mapping[digits[idx] - '0']) {
	//             partial.push_back(c);
	//             helper(digits, idx + 1, partial, mapping, res);
	//             partial.pop_back();
	//         }
	//     }

	//     vector<string> letterCombinations(string digits) {
	//         vector<string> mapping = {" ", "", "abc", "def", "hgi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	//         vector<string> res;
	//         if (!digits.size()) return res;
	//         string partial;
	//         helper(digits, 0, partial, mapping, res);
	//         return res;
	//     }
};
