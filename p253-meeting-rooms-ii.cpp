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
	/*20171119 2351*/
	/*AC       0012*/
	int minMeetingRooms(vector<Interval>& intervals) {
		priority_queue<pair<int, int>> pq; // pair<pos, start?1:0>
		for (auto & iv:intervals) {
			pq.push(make_pair(iv.start, 1));
			pq.push(make_pair(iv.end, 0));
		}

		int curr = 0, max = 0;
		while(!pq.empty()) {
			auto p = pq.top();
			pq.pop();
			if (p.second)
				--curr;
			else
				if (++curr > max) max = curr;
		}
		return max;
	}
};
