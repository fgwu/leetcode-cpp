class Solution {
public:
	/*20170520 0315*/
	/*         0320*/
	/*20170520 0324 too many bugs, restart */
	/*         0328*/
	/*AC       0329*/
	int titleToNumber(string s) {
		int rv = 0;
		for (const auto & c:s)
			rv = rv * 26 + c - 'A' + 1;
		return rv;
	}
};
