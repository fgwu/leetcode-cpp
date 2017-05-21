class Solution {
public:
	/*20170521 0116*/
	/*         0126*/
	/*AC       0126 bug free*/
	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		if (timeSeries.size() == 0) return 0;
		if (timeSeries.size() == 1) return duration;
		int rv = duration;
		for (int i = 1; i < timeSeries.size(); i++) {
			if (timeSeries[i] - timeSeries[i - 1] < duration)
				rv += timeSeries[i] - timeSeries[i - 1];
			else
				rv += duration;
		}
		return rv;
	}
};
