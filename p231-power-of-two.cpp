class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (!n) return false;
		for (; n; n >>= 1) {
			if (!(n&1)) continue;
			break;
		}

		if (n & (~1)) return false;
		return true;
	}
};
