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
	/*20171121 1201*/
	/*AC       1209*/
	bool canAttendMeetings(vector<Interval>& intervals) {
		auto cmp = [](const Interval& a, const Interval& b) {
			if (a.start == b.start) return a.end < b.end;
			return a.start < b.start;
		};
		sort(intervals.begin(), intervals.end(), cmp);

		for (int i = 0, last_end; i < intervals.size(); i++) {
			if (i == 0) {
				last_end = intervals[i].end;
				continue;
			}
			if (intervals[i].start < last_end) return false;
			last_end = intervals[i].end;
		}
		return true;
	}
};
