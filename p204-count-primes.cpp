class Solution {
public:
	/*DP       1152*/
	/*AC       1157*/
	int countPrimes(int n) {
		int cnt = 0;
		vector<bool> prime(n, true);
		for(int i = 2; i < n; i++) {
			if (!prime[i]) continue;
			cnt++;
			for (int j = 2; i * j < n; j++) prime[i * j] = false;
		}
		return cnt;
	}

	/*20170628 1141*/
	/*AC       1149*/
	// int countPrimes(int n) {
	//     int cnt = 0;
	//     vector<int> primes;
	//     for (int i = 2; i < n; i++) {
	//         if (primes.empty()) {
	//             cnt++;
	//             primes.push_back(i);
	//             continue;
	//         }
	//         bool isPrime = true;
	//         for (const auto p: primes) {
	//             if (p > sqrt(i)) break;
	//             if (i % p == 0) {
	//                 isPrime = false;
	//                 break;
	//             }
	//         }
	//         if (isPrime) {
	//             cnt++;
	//             primes.push_back(i);
	//         }
	//     }
	//     return cnt;
	// }
};
