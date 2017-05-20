class Solution {
public:
	/*20170518 15:52*/
	/*20170519 13:48 restart*/
	/*AC       13:54*/
	vector<int> constructRectangle(int area) {
		int cand_w = 1, cand_l = area;
		vector<int> rv;
		for (int w = 1; w <= sqrt(area); w++ ){
			if (area / w * w == area){
				cand_w = w;
				cand_l = area/cand_w;
			}
		}
		rv.push_back(cand_l);
		rv.push_back(cand_w);
		return rv;
	}
};
