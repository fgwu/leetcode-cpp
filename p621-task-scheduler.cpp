class Solution {
public:
	/*20171120 2258*/
	/*20171121 1441*/
	/*AC       1502 Math*/
	int leastInterval(vector<char>& tasks, int n) {
		unordered_map<char, int> m;
		int most = 0, cnt = 0;
		for (auto c: tasks) {
			if(!m.count(c))
				m[c] = 1;
			else
				m[c]++;

			if (m[c] == most) cnt++;

			if (m[c] > most) {
				most = m[c];
				cnt = 1;
			}
		}
		int at_least = (most - 1) * (n + 1) + cnt;
		return max(at_least, (int)tasks.size());
	}
};
