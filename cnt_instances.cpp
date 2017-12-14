

#include <vector>
#include <iostream>
using namespace std;
/*20171210 1949*/
/*AC       1958*/
int find_cnt(vector<int>& nums, int target) {
	int n = nums.size();
	if (!n) return 0;
	int l, r, first, last;

	// first instance

	l = 0;
	r = n - 1;
	while(l < r) {
		int mid = l + (r - l) / 2;

		if (nums[mid] >= target)
			r = mid;
		else
			l = mid + 1;
	}

	if (nums[l] != target) return 0;
	first = l;

	l = 0;
	r = n - 1;
	while(l < r) {
		int mid = l + (r - l + 1) / 2;

		if (nums[mid] > target)
			r = mid - 1;
		else
			l = mid;
	}

	if (nums[l] != target) return 0;
	last = l;
	return last - first + 1;
}

int main() {
	vector<int> input = {1, 2, 2, 2, 2, 100};


	cout << find_cnt(input, 100) << '\n';

	return 0;
}

