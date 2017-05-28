class Solution {
public:
	/*20170521 2346*/
	/*AC       0042*/
	vector<int> nextGreaterElements(vector<int>& nums) {
		stack<pair<int, int>> s; //num, idx
		vector<int> res(nums.size(), -1);
		for (int j = 0; j < 2 * nums.size(); j++) {
			int i = j % nums.size();
			//           cout << "i=" << i << "  s.size()=" <<s.size() << " res[i]=" << res[i] << endl;
			if (s.empty()) {
				if (res[i] == -1) s.push(make_pair(nums[i], i));
				continue;
			}
			while(!s.empty()) {
				pair<int, int> p = s.top();
				//                cout << "new=" << nums[i] << " s.top()=" << p.first << endl;
				if (p.first >= nums[i]) break;
				s.pop();
				res[p.second] = nums[i];
			}
			if (res[i] == -1) s.push(make_pair(nums[i], i));
		}
		return res;
	}
};
