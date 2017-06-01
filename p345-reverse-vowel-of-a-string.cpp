class Solution {
public:
	string reverseVowels(string s) {
		int i = 0, j = s.size() - 1;
		while (i < j) {
			i = s.find_first_of("aeiouAEIOU", i);
			j = s.find_last_of("aeiouAEIOIU", j);
			// if (i == s.npos || j == s.npos) break;
			if (i >= j) break;
			swap(s[i++], s[j--]);
		}
		return s;
	}

	/*AC 20170529 2322*/
	// bool isVowel(char c) {
	//     return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
	//     c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
	// }

	// string reverseVowels(string s) {
	//     for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
	//         while (i < s.size() && !isVowel(s[i])) i++;
	//         if (i == s.size()) break;
	//         while (j >= 0 && !isVowel(s[j])) j--;
	//         if (j == 0) break;
	//         if (i >= j) break;
	//         swap(s[i], s[j]);
	//     }
	//     return s;
	// }
};
