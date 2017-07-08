class Solution {
public:
	/*20170619 1553*/
	/*20170705 1348 restart*/
	/*AC       1507*/
	int findnth(vector<int>& nums1, int l1, int s1,
		    vector<int>& nums2, int l2, int s2, int n) {
		printf("l1=%d s1=%d l2=%d s2=%d n=%d\n",l1, s1, l2, s2, n);
		assert(n <= s1 + s2 && n >= 1);
		if (!s1) return nums2[n - 1];
		if (!s2) return nums1[n - 1];
		if (n == 1) {
			printf("nums1[%d]=%d, nums2[%d]=%d\n", l1, nums1[l1], l2, nums2[l2]);
			int rv = min(nums1[l1], nums2[l2]);
			printf("return %d\n", rv);
			return rv;
		}
		int try1 = min(s1, n/2), try2 = min(n - try1, s2);
		try1 = n - try2;
		int pivot1 = nums1[l1 + try1 - 1], pivot2 = nums2[l2 + try2 - 1];
		printf("p1=%d p2=%d\n", pivot1, pivot2);
		if (pivot1 == pivot2) return pivot1;
		if (pivot1 > pivot2)
			return findnth(nums1, l1, try1, nums2, l2 + try2, s2 - try2, n - try2);
		else
			return findnth(nums1, l1 + try1, s1 - try1, nums2, l2, try2, n - try1);
	}

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int s1 = nums1.size(), s2 = nums2.size();
		if ((s1 + s2)%2) return findnth(nums1, 0, s1, nums2, 0, s2, (s1 + s2 + 1)/2);
		return (findnth(nums1, 0, s1, nums2, 0, s2, (s1 + s2)/2) + findnth(nums1, 0, s1, nums2, 0, s2, (s1 + s2)/2 + 1))/2.0;
	}
};
