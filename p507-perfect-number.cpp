class Solution {
public:
	bool checkPerfectNumber(int num) {
		if (num == 1) return false;
		int cnt = 1, left, right = num/2;
		for (left = 2; left < right; left++) {
			if (num % left) continue;
			right = num/left;
			if (left > right) break;
			cnt += left;
			if (left != right) cnt += right;
			cout << "left=" << left << " right=" << right << " cnt=" << cnt << "\n";
		}
		cout << "left=" << left << " right=" << right << " cnt=" << cnt << "\n";
		return cnt == num;
	}



	/*20170609 1123*/
	/*time exceeded*/
	// bool checkPerfectNumber(int num) {
	//     int cnt = 0;
	//     for (int i = 1; i <= num/2; i++) if (!(num%i)) cnt += i;
	//     return cnt == num;
	// }
};
