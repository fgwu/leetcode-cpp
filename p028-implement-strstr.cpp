class Solution {
public:
	/*20170701 1126 finally got through */
	int strStr(string haystack, string needle) {
		int t, i;
		vector<int> next(needle.size(), -1);
		for (t = -1, i = 0; i < (int)needle.size() - 1;) {
			if (t < 0 || needle[t] == needle[i])
				next[++i] = ++t;
			else
				t = next[t];
		}

		for (t = 0, i = 0; i < haystack.size() && t < (int)needle.size(); ) {
			if (t < 0 || needle[t] == haystack[i])
				t++, i++;
			else
				t = next[t];
		}

		return (t == needle.size()) ? (i - t) : -1;
	}




	/*finally kmp*/
	/*Fails..*/
	/*   int strStr(string haystack, string needle) {
	             if (!haystack.size() && !needle.size()) return 0;
		             if (!needle.size()) return 0;
			             int i, j;
				             vector<int> p(needle.size(), 0);
					             for (i = 0, j = 1; j < needle.size(); j++){
						                 while (needle[i] != needle[j] && i > 0) i = p[i - 1];
								             if (needle[i] != needle[j])
									                     p[j] = 0;
											                 else
													                 p[j] = ++i;
															 // cout << i << ':' << p[j] << '\n';
															         }
																         for (i = 0, j = 0; j < haystack.size(); j++) {
																	 cout << "haystack " << j << ':' << haystack[j] << '\n';
																	             while (needle[i] != haystack[j] && i > 0) {
																		     cout << "  needle " << i << ':' << needle[i] << '\n';
																		                     i = p[i - 1];
																				                 }
																						 // cout << "  needle " << i << ':' << needle[i] << '\n';

																						             if (needle[i] != haystack[j]) continue;
																							                 i++;
																									             if (i == needle.size()) return j - needle.size();
																										             }
																											             return -1;
																												     }*/

	/*avoiding using flag*/
	// int strStr(string haystack, string needle) {
	//     if (!needle.size() && !haystack.size()) return 0;
	//     for (int i = 0, j; i <= (int)haystack.size() - (int)needle.size(); i++) {
	//         for (j = 0; j < needle.size(); j++)
	//             if (haystack[i + j] != needle[j]) break;
	//         if (j == needle.size()) return i;
	//     }
	//     return -1;
	// }


	/*20170622 1044*/
	// size_t is unsigned. if (size_t) 0 - (size_t) 1 != -1. it overflows...
	// i < (int)haystack.size() - (int)needle.size()      here '<' should be '<='
	// nested loop, "continue" will continue the inner loop!!!!
	// int strStr(string haystack, string needle) {
	//     if (!needle.size() && !haystack.size()) return 0;
	//     for (int i = 0; i <= (int)haystack.size() - (int)needle.size(); i++) {
	//         bool check = true;
	//         for (int j = 0; j < needle.size() && check; j++) {
	//             if (haystack[i + j] != needle[j]) check = false;
	//         }
	//         if (check) return i;
	//     }
	//     return -1;
	// }
};
