class Solution {
public:
	/*even shorter code using for*/
	int hammingWeight(uint32_t n) {
		int res = 0;
		for (; n; n &= (n - 1)) res++;
		return res;
	}


	/*seen solution: n&(n-1) trick*/
	// int hammingWeight(uint32_t n) {
	//     int res = 0;
	//     while (n) {
	//         res ++;
	//         n &= (n - 1);
	//     }
	//     return res;
	// }


	/*AC*/
	// int hammingWeight(uint32_t n) {
	//     int cnt = 0;
	//     for (int i = 0; i< 32; i++) cnt += n&(1 << i) ? 1: 0;
	//     return cnt;
	// }
};
