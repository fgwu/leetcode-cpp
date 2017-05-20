class Solution {
public:
	/*20170518 12:55*/
	/*         13:23*/
	/*AC       13:24*/
	/*compare use == ...... */
	int findLUSlength(string a, string b) {
		if (a != b) return max(a.size(), b.size());
		return -1;
	}
};
