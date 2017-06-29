class Solution {
public:
	/*20170628 1021*/
	/*AC       1025*/
	uint32_t reverseBits(uint32_t n) {
		uint32_t res = 0;
		for(int i = 0; i < 32; i++) {
			res *= 2;
			if (n%2) res += 1;
			n /= 2;
		}
		return res;
	}
};
