class Solution {
public:
	/*20170519 16:05*/
	/*         16:14*/
	/*AC       16:15*/
	/*Note: substr(), to_string(), atoi() */
	string complexNumberMultiply(string a, string b) {
		int r1, i1, r2, i2, r, i;
		extractNum(a, &r1, &i1);
		extractNum(b, &r2, &i2);
		r = r1 * r2 - i1 * i2;
		i = r1 * i2 + r2 * i1;
		return to_string(r) + "+" + to_string(i) + "i";
	}

	void extractNum(string s, int *r, int *i){
		*r = atoi(s.substr(0, s.find('+')).c_str());
		*i = atoi(s.substr(s.find('+') + 1, s.find('i')).c_str());
	}
};
