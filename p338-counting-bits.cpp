class Solution {
public:
	/*20170519 17:24*/
	/*         17:35*/
	/*AC       17:46*/
	/*Note: variable initial value!!! and corner case */
	vector<int> countBits(int num) {
		vector<int> rv(num + 1);
		int pow = 1, i = 1;
		rv[0] = 0;
		while(i <= num){
			if (i >= pow * 2){
				pow *= 2;
				continue;
			}
			rv[i] = rv[i-pow] + 1;
			i++;
		}
		return rv;
	}
};
