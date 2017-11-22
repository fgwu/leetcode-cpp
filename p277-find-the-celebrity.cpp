// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
	/*two pass 1018  */
	/*AC       1024 O(n)*/
	int findCelebrity(int n) {
		if (!n) return -1;
		int cand = 0;
		for (int i = 1; i < n; i++)
			if (knows(cand, i)) cand = i;

		for (int i = 0; i < n; i++) {
			if (i == cand) continue;
			if (knows(cand, i) || !knows(i, cand)) return -1;
		}

		return cand;
	}

	/*20171121 0959*/
	/*AC       1015 O(nlogn)*/
	//     int findCelebrity(int l, int r) { // [l, r)
	//         if (l >= r) return -1;
	//         if (l == r - 1) return l;
	//         int mid = l + (r - l) / 2;
	//         int cele_l = findCelebrity(l, mid);
	//         int cele_r = findCelebrity(mid, r);

	//         if (cele_l == -1 && cele_r == -1) return -1;

	//         if (cele_l != -1 && cele_r == -1) {
	//             for(int i = mid; i < r; i++) {
	//                 if (!knows(i,cele_l) || knows(cele_l, i)) return -1;
	//             }
	//             return cele_l;
	//         }

	//         if (cele_r != -1 && cele_r == -1) {
	//             for(int i = l; i < mid; i++) {
	//                 if (!knows(i, cele_r) || knows(cele_r, i)) return -1;
	//             }
	//             return cele_r;
	//         }

	//         bool flag = true;  // whether cele_l is the cele;
	//         for(int i = mid; flag && i < r; i++) {
	//             if (!knows(i,cele_l) || knows(cele_l, i)) flag = false;
	//         }

	//         if (flag) return cele_l;

	//         for(int i = l; i < mid; i++) {
	//             if (!knows(i, cele_r) || knows(cele_r, i)) return -1;
	//         }

	//         return cele_r;
	//     }

	//     int findCelebrity(int n) {
	//         return findCelebrity(0, n);
	//     }
};
