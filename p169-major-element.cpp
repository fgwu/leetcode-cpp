class Solution {
public:
	/*20170520 1437 seen the solution, implement Moore vote, O(1) space */
	/*AC       1442*/
	int majorityElement(vector<int>& nums) {
		int major, count = 0;
		for (const auto & n:nums) {
			if (count && (major != n))
				count--;
			else {
				count++;
				major = n;
			}
		}
		return major;
	}
	/*20170520 1218*/
	/*AC       1246*/
	/*bug: !s.empty() => e.empty()*/
	// int majorityElement(vector<int>& nums) {
	//     stack<int>s;
	//     for (const auto & n:nums){
	//         if (s.empty() || s.top() == n)
	//             s.push(n);
	//         else
	//             s.pop();
	//     }
	//     if (s.empty()) return -1;
	//     return s.top();
	// }
};
