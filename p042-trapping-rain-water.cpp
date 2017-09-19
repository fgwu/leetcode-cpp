class Solution {
public:
	/*SQ 0212*/
	int trap(vector<int>& height) {
		int res = 0, l = 0, r = height.size() - 1, maxl = 0, maxr = 0;
		while (l <= r) {
			if (height[l] < height[r]) {
				if (height[l] > maxl)
					maxl = height[l];
				else
					res += maxl - height[l];
				l++;
			} else {
				if (height[r] > maxr)
					maxr = height[r];
				else
					res += maxr - height[r];
				r--;
			}
		}
		return res;
	}

	/*20170908 0000*/
	/*AC       0147*/
	//     int trap(vector<int>& height) {
	//         int res = 0;
	//         stack<int> hs;
	//         stack<int> ps;
	//         // loop invariant:
	//         // 1) res store current water
	//         // 2) stack stores descendent steps
	//         for (int i = 0; i < height.size(); i++) {
	//             if (hs.empty() || hs.top() > height[i]) {
	//                 hs.push(height[i]);
	//                 ps.push(i);
	//                 continue;
	//             }

	//             while (!hs.empty() && hs.top() <= height[i]) {
	//                 int h = hs.top();
	//                 hs.pop();
	//                 int p = ps.top();
	//                 ps.pop();

	//                 if (hs.empty()) {
	//                     hs.push(height[i]);
	//                     ps.push(i);
	//                     break;
	//                 }

	//                 if (hs.top() <= height[i]) {
	//                     res += (hs.top() - h) * (i - ps.top() - 1);
	//                     continue;
	//                 }

	//                 res += (height[i] - h) * (i - ps.top() - 1);
	//                 hs.push(height[i]);
	//                 ps.push(i);
	//                 break;
	//             }
	//         }

	//         return res;
	//     }
};
