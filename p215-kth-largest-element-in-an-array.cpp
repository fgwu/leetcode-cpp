class Solution {
public:
	/*20170720 1804*/
	/*AC       2026*/
	int findKthLargest(vector<int>& nums, int k) {
		int left = 0, right = nums.size() - 1;

		while(left < right) {
			int pivot = nums[left], i, j;
			for (i = left + 1, j = right; i <= j;) {
				if (nums[i] >= pivot) {
					i++; continue;
				}
				if (nums[j] < pivot) {
					j--; continue;
				}
				swap(nums[i], nums[j]);
				i++; j--;
			}
			swap(nums[left], nums[j]);
			// printf("left=%d right=%d i=%d j=%d k-1=%d\n", left, right, i, j, k - 1);
			if (k - 1 == j) return nums[j];
			if (k - 1 < j)
				right = j - 1;
			else
				left = j + 1;
			// printf("==> left=%d right=%d\n", left, right);
		}

		return nums[left];
	}
};
