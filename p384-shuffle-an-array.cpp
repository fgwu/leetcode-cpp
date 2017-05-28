class Solution {
	/*AC 20170524 1328*/
private:
	vector<int> orig;
	vector<int> shuf;
	bool shuffled;
public:
	Solution(vector<int> nums) {
		orig = nums;
		shuf = vector<int>(nums.size(), 0);
		shuffled = false;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		if (shuffled) shuf = orig;
		shuffled = false;
		return orig;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		if (shuffled) return shuf;
		for (int i = 0; i < shuf.size(); i++) {
			int r = rand()%(shuf.size() - i);
			swap(shuf[i], shuf[i + r]);
		}
		// int n = orig.size();
		// vector<int> tmp = orig;
		// for (int i = 0; i < n; i++){
		//     int r = rand() % (n - i);
		//     shuf[i] = tmp[r];
		//     tmp.erase(tmp.begin() + r);
		// }
		return shuf;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
