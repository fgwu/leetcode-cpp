class Solution {
public:
	/*20170519 17:09*/
	/*         17:49*/
	/*AC       17:40 bug free*/
	int findContentChildren(vector<int>& g, vector<int>& s) {
		int rv = 0, i = 0;
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		for(auto &gn: g){
			while(i<s.size() && s[i] < gn) i++;
			if(i == s.size()) break;
			i++;
			rv++;
		}
		return rv;
	}
};
