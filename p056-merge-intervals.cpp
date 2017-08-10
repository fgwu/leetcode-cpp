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
	/*2243 using vector sort */
	/*AC 2246*/
	vector<Interval> merge(vector<Interval>& intervals) {
		sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
		vector<Interval> res;
		for (auto & interval: intervals) {
			if (res.empty() || res.back().end < interval.start)
				res.push_back(interval);
			else
				res.back().end = max(res.back().end, interval.end);
		}
		return res;
	}

	/*20170809 2208*/
	/*AC       2238*/
	//     vector<Interval> merge(vector<Interval>& intervals) {
	//         auto cmp = [](const Interval& a, const Interval& b) {return a.start > b.start;};
	//         // priority_queue<Interval, vector<Interval>, decltype(cmp)> q;
	//         priority_queue<Interval, vector<Interval>, decltype(cmp)> q(cmp);
	//         for (auto & interval: intervals)
	//             q.push(interval);

	//         vector<Interval> res;
	//         while (!q.empty()) {
	//             auto interval = q.top();
	//             if (res.empty() || res.back().end < interval.start) {
	//                 res.push_back(interval);
	//                 continue;
	//             }

	//             res.back().end = max(res.back().end, interval.end);
	//             q.pop();
	//         }

	//         return res;
	//     }
};
