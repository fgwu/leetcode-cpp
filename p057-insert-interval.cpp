/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
	/*20171121 1128*/
	/*AC       1159*/
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> rv;
		bool inserted = false;
		for (auto &iv: intervals) {
			if (iv.start > newInterval.end || iv.end < newInterval.start) {
				if (!inserted && iv.start > newInterval.end) {
					rv.push_back(newInterval);
					inserted = true;
				}
				rv.push_back(iv);
				continue;
			}

			newInterval.start = min(newInterval.start, iv.start);
			newInterval.end = max(newInterval.end, iv.end);
		}

		if (!inserted) rv.push_back(newInterval);
		return rv;
	}
};
