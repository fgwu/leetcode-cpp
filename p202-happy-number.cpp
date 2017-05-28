class Solution {
public:
	/*AC 20170524 0244*/
	bool isHappy(int n) {
		unordered_set<int> s;
		while (s.find(n) == s.end() && n != 1) {
			int next = 0;
			s.insert(n);
			for (int tmp = n; tmp; tmp /= 10) {
				int d = tmp%10;
				next += d * d;
			}
			n = next;
		}

		if (n == 1) return true;
		return false;
	}
};
