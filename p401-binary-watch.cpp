class Solution {
public:
	/*20170523 2119*/
	/*AC       2141*/
	int getHour(const vector<int> &b){
		return b[0] * 8 + b[1] * 4 + b[2] * 2 + b[3];
	}

	int getMin(const vector<int> &b){
		//        cout << "b:" << b[4] << b[5] << b[6] << b[7] << b[8] << b[9] << b[1] << b[4] << "\n";
		return b[4] * 32 + b[5] * 16 + b[6] * 8 + b[7] * 4 + b[8] * 2 + b[9];
	}

	bool isValid(const vector<int> &b){
		int h = getHour(b);
		int m = getMin(b);
		return h <= 11 && m <= 59;
	}

	void searchRec(vector<int> b, int pos, int num, vector<string> & res) {
		if (!num) {
			int h = getHour(b);
			int m = getMin(b);
			string s = to_string(h);
			s += ":";
			if (m < 10) s += "0";
			s += to_string(m);
			res.push_back(s);
			return;
		}
		if (pos < 0 || pos >= 10) return;
		searchRec(b, pos + 1, num, res);
		b[pos] = 1;
		if (isValid(b)) searchRec(b, pos + 1, num - 1, res);
	}

	vector<string> readBinaryWatch(int num) {
		vector<int> b(10, 0);
		vector<string> res;
		searchRec(b, 0, num, res);
		return res;
	}
};
