class Solution {
public:
	/* 20170730 2045 seen sln */
	int maxArea(vector<int>& height) {
		int i = 0, j = height.size() - 1, res = INT_MIN;
		while (i < j) {
			int area = min(height[i], height[j]) * (j - i);
			res = max(res, area);
			if (height[i] < height[j])
				i++;
			else
				j--;
		}
		return res;
	}

	/*20170726 1406*/
	/*TLE      1419*/
	//     int maxArea(vector<int>& height) {
	//         int n = height.size();
	//         assert(n >= 2);
	//         int res = INT_MIN;
	//         for (int i = 1; i < n; i++)
	//             for (int j = 0; j < i; j++)
	//                 res = max(res, (i - j) * min(height[i], height[j]));

	//         return res;
	//     }
};
