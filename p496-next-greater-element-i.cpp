class Solution {
public:
	/*20170517 15:23*/
	/*         15:31*/
	/*AC       15:45*/
	/* Note: stack pop, return void. use top to retieve elem*/
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		stack<int> s;
		unordered_map<int, int> m;
		vector<int> rv;
		for (auto it = nums.begin(); it != nums.end(); it++){
			if (s.empty()) {
				s.push(*it);
				continue;
			}
			if (s.top() < *it)
				while(!s.empty() && s.top() < *it) {
					m[s.top()] = *it;
					s.pop();
				}
			s.push(*it);
		}

		while(!s.empty()) {
			m[s.top()] = -1;
			s.pop();
		}

		for (auto it = findNums.begin(); it != findNums.end(); it++)
			rv.push_back(m[*it]);

		return rv;
	}
	/*20170517 15:04*/
	/*AC       15:20*/
	// vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
	//     unordered_map<int, int>map;
	//     int i;
	//     vector<int> rv;
	//     if (findNums.size() == 0 || nums.size()==0) return rv;

	//     map[nums.size() - 1] = -1;
	//     for (i = nums.size() - 2; i >= 0; i--) {
	//         int nextIdx = i + 1;
	//         while (nextIdx != -1 && nums[nextIdx] <= nums[i])
	//             nextIdx = map[nextIdx];
	//         map[i] = nextIdx;
	//     }

	//     for (auto it = findNums.begin(); it != findNums.end(); it++) {
	//         if (map[*it] > 0)
	//             rv.push_back(map[*it]);
	//         else
	//             rv.push_back(-1);
	//     }
	//     return rv;
	// }

	/*20170517 14:35*/
	/*         14:43*/
	/*AC       14:54*/
	// vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
	//     vector<int> rv;
	//     for (auto i = findNums.begin(); i != findNums.end(); i++) {
	//         rv.push_back(findNext(*i, nums));
	//     }
	//     return rv;
	// }

	// int findNext(int k, vector<int>& nums) {
	//     auto i = nums.begin();
	//     for (; i!= nums.end(); i++)
	//         if (*i==k) break;
	//     for (; i!= nums.end(); i++)
	//         if (*i > k) return *i;
	//     return -1;
	// }
};
