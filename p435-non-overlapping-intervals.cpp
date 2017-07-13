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
	/*20170713 Thu 1305*/
	/*AC           1344*/
	int eraseOverlapIntervals(vector<Interval>& intervals) {
		auto cmp = [](const Interval& a, const Interval& b) {return a.end > b.end; };
		priority_queue<Interval, vector<Interval>, function<bool(Interval, Interval)>> pq(cmp);

		for(const auto & intv:intervals)
			pq.push(intv);
		int cnt = 0;
		Interval last;
		for(; !pq.empty(); pq.pop()) {
			Interval intv = pq.top();
			// if (cnt)
			// printf("%lu, last[%d, %d], ", &last, last.start, last.end);
			// printf("intv[%d, %d]\n", intv.start, intv.end);

			if (cnt && last.end > intv.start) continue;
			// printf("added\n");
			last = Interval(intv.start, intv.end);
			cnt++;
		}

		return intervals.size() - cnt;
	}

	//     /*20170713 Thu 1305*/
	//     int eraseOverlapIntervals(vector<Interval>& intervals) {
	//         auto cmp = [](const Interval& a, const Interval& b) {return a.end > b.end; };
	//         priority_queue<Interval, vector<Interval>, function<bool(Interval, Interval)>> pq(cmp);

	//         for(const auto & intv:intervals)
	//             pq.push(intv);
	//         int cnt = 0;
	//         Interval& last; // wrong: reference must be initialized.
	//         for(; !pq.empty(); pq.pop()) {
	//             Interval intv = pq.top();
	//             if (cnt)
	//                 printf("last[%d, %d], ", last.start, last.end);
	//             printf("intv[%d, %d]\n", intv.start, intv.end);

	//             if (cnt && last.end > intv.start) continue;
	//             printf("added\n");
	//             last = intv;
	//             cnt++;
	//         }

	//         return intervals.size() - cnt;
	//     }


	//     /*20170713 Thu 1305*/
	//     int eraseOverlapIntervals(vector<Interval>& intervals) {
	//         auto cmp = [](const Interval& a, const Interval& b) {return a.end > b.end; };
	//         priority_queue<Interval, vector<Interval>, function<bool(Interval, Interval)>> pq(cmp);

	//         for(const auto & intv:intervals)
	//             pq.push(intv);
	//         int cnt = 0;
	//         Interval *last = nullptr;
	//         for(; !pq.empty(); pq.pop()) {
	//             Interval intv = pq.top();
	//             const Interval* tmp = &pq.top();
	//             intv.start = 100;
	//             if (last)
	//                 printf("%lu, last[%d, %d], ", last, last->start, last->end);
	//             printf("intv %lu [%d, %d], top %lu [%d, %d]\n", &intv, intv.start,
	//                 intv.end, &pq.top(), pq.top().start, pq.top().end);

	//             if ((last != nullptr) && (last->end > intv.start)) continue;
	//             printf("added\n");
	//             last = &intv;
	//             cnt++;
	//         }

	//         return intervals.size() - cnt;
	//     }
};
