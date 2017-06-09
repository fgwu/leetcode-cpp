// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
	/*20170608 1408*/
	/*AC       1418*/
	/*NOTE: overflow solution:
	 * int mid = ((long)start + (long)end) / 2;
	 * or
	 * int mid = (end - start) / 2 + start;
	 */
	int helper(int start, int end) {
		if (start > end) return -1;
		int mid = ((long)start + (long)end) / 2;
		if (!guess(mid)) return mid;
		if (guess(mid) == -1) return helper(start, mid - 1);
		return helper(mid + 1, end);
	}

	int guessNumber(int n) {
		return helper(1, n);
	}
};
