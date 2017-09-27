class Solution {
public:
	/*20170925 1956*/
	/*AC       2052*/
	int maximumSwap(int num) {
		if (num <= 0) return 0;
		vector<int>d;
		vector<int>m;
		while(num) {
			int digit = num % 10;
			d.push_back(digit);
			if (!m.size() || d[m.back()] < digit)
				m.push_back(m.size());
			else
				m.push_back(m.back());
			num /= 10;
		}

		for (int i = d.size() - 1; i >= 0; i-- ) {
			if (i != m[i] && d[i] != d[m[i]]) {
				swap(d[i], d[m[i]]);
				break;
			}
		}

		int res = 0;
		for (int i = 0, base = 1; i < d.size(); i++, base *= 10) {
			res += d[i] * base;
		}

		return res;
	}
};
