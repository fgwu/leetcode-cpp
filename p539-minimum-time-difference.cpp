class Solution {
public:
	/*20170526   2050*/
	/*           2103*/
	/*AC         2108*/
	int toMinutes(string s) {
		int rv = (s[0] - '0') * 10 * 60 +
			(s[1] - '0') * 60 + (s[3] - '0') * 10 + (s[4] - '0');
		// cout << s[0] <<  (s[0] - '0') * 10 * 60 << "\n";
		// cout << s[1] <<  (s[1] - '0') * 60 << "\n";
		// cout << s[3] <<  (s[3] - '0') * 10 << "\n";
		// cout << s[4] <<  (s[4] - '0') << "\n";
		// cout << s << rv << "\n";
		return rv;
	}

	int findMinDifference(vector<string>& timePoints) {
		vector<int> minute_list;
		int min_interval = 1440;
		for (const auto & s:timePoints) {
			int t = toMinutes(s);
			minute_list.push_back(t);
			minute_list.push_back(t + 1440);
		}
		sort(minute_list.begin(), minute_list.end());
		for (int i = 1; i < minute_list.size(); i++)
			min_interval = min(min_interval, minute_list[i] - minute_list[i - 1]);
		return min_interval;
	}
};
