class Solution {
public:
	/*optimized*/
	bool isPalindrome(string s) {
		for (int i = 0, j = s.size() - 1; i < j; ){
			if (!isalnum(s[i]))
				i++;
			else if (!isalnum(s[j]))
				j--;
			else {
				if (tolower(s[i]) != tolower(s[j])) return false;
				i++;
				j--;
			}
		}
		return true;
	}

	/*20170628 1158*/
	/*AC       1224*/
	// bool isLetter(char c) {
	//     return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9';
	// }

	// char lowerCase (char c) {
	//     if (c >= 'A' && c <= 'Z') c += 'a' - 'A' ;
	//     return c;
	// }

	// bool isPalindrome(string s) {
	//     int left = 0, right = s.size() - 1;
	//     while (left < right) {
	//         while(left < right && !isLetter(s[left])) left++;
	//         if (left == right) return true;
	//         while (left < right && !isLetter(s[right])) right--;
	//         if (left == right) return true;
	//         if (lowerCase(s[left]) != lowerCase(s[right])) return false;
	//         left++;
	//         right--;
	//     }
	//     return true;
	// }
};
