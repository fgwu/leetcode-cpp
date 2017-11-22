class Solution {
public:
	/*20171120 2212*/
	/*AC       2253*/
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> rv;
		int length, start;
		for (int i = 0; i < words.size();) {
			length = 0, start = i;
			while (i < words.size() && length + 1 + words[i].size() <= maxWidth + 1) {
				length += 1 + words[i++].size();
			}

			if (i >= words.size()) break;

			int num_words = i - start;
			int num_gaps = num_words - 1;
			int num_spaces = maxWidth + 1 - length;
			// printf("words=%d gaps=%d space=%d\n", num_words, num_gaps, num_spaces);

			string tmp;
			if (num_words == 1) {
				tmp += words[start];
				while(num_spaces--) tmp += ' ';
			} else {
				vector<int> spaces (num_words - 1, num_spaces / num_gaps + 1);

				for (int j = 0; j < num_spaces - num_spaces / num_gaps * num_gaps; j++)
					spaces[j]++;

				for (int j = 0; j < num_words; j++) {
					tmp += words[start + j];
					if (j == num_words - 1) break;
					while (spaces[j]--) tmp += ' ';
				}
			}

			rv.push_back(tmp);
		}

		string tmp;
		for (int j = 0; start + j < words.size(); j++) {
			tmp += words[start + j];
			if (start + j == words.size() - 1) break;
			tmp += ' ';
		}
		while (tmp.size() < maxWidth) tmp += ' ';
		rv.push_back(tmp);

		return rv;
	}
};
