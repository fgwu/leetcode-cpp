class Solution {
public:
	bool isPowerOfFour(int num) {
		// cout << (num & num-1) <<  " " << (num & 0x55555555) << "\n";
		return ((num & num-1) == 0) && (num & 0x55555555);
	}
};
