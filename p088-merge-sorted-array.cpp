class Solution {
public:
	/*try to optmize*/
	/*AC        0030*/
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		while(n) nums1[m + n - 1] = (!m || nums1[m - 1] < nums2[n - 1]) ? nums2[--n]:nums1[--m];
	}


	/*20170610 0007*/
	/*AC       0023*/
	// void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	//     int i = m - 1, j = n - 1, k = m + n - 1;
	//     while (k >= 0) {
	//         // cout << i << " " << nums1[i] << "   ";
	//         // cout << j << " " << nums2[j] << "\n";
	//         if (j < 0) break;
	//         if (i < 0 || nums2[j] > nums1[i])  {
	//             nums1[k--] = nums2[j--];
	//             continue;
	//         }
	//         nums1[k--] = nums1[i--];
	//     }
	// }
};
