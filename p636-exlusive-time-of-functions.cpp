class Solution {
public:
	/*20171125 0834*/
	void parse(string& s, int& id, int& ts, bool& is_start) {
		int pos = s.find(':');
		id = stoi(s.substr(0, pos));
		pos++;
		int pos2 = s.find(':', pos);
		is_start = s.substr(pos, pos2 - pos) == "start";
		ts = stoi(s.substr(pos2 + 1));
		if (!is_start) ts++;
	}

	vector<int> exclusiveTime(int n, vector<string>& logs) {
		vector<int> rv(n, 0);
		stack<int> cs;
		int id, ts, last_ts;
		bool is_start;
		for(auto &s: logs) {
			parse(s, id, ts, is_start);
			if (cs.empty()) {
				assert(is_start);
				cs.push(id);
				last_ts = ts;
				continue;
			}

			int duration = ts - last_ts;
			rv[cs.top()] += duration;
			if (!is_start) {
				assert(id == cs.top());
				cs.pop();
			} else
				cs.push(id);

			last_ts = ts;
		}
		return rv;
	}
};
