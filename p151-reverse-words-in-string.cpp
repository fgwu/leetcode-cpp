class Solution {
public:
	/*20171109 1004*/
	/*         1021*/
	/*AC       1028*/
	void reverseWords(string &s) {
		size_t i = 0, j = s.find_first_not_of(' ');
		if (j == string::npos) {
			s.resize(0);
			return;
		}

		while(true) {
			while(j < s.size() && s[j] != ' ') s[i++] = s[j++];

			if (j == s.size()) {
				s.resize(i);
				break;
			}

			j = s.find_first_not_of(' ', j);
			if (j == string::npos) {
				s.resize(i);
				break;
			}
			s[i++] = ' ';
		}

		i = 0, j;
		while(i < s.size()) {
			j = s.find_first_of(' ', i);
			if (j == string::npos)
				j = s.size() - 1;
			else
				j = j - 1;

			for (int k = 0; i + k < j - k; k++)
				swap(s[i + k], s[j - k]);

			i = j + 2;
		}

		reverse(s.begin(), s.end());
	}
};
