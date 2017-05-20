class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		vector<char>row1 = {'q','w','e','r','t','y','u','i','o','p','Q','W','E','R','T','Y','U','I','O','P'};
		vector<char>row2 = {'a','s','d','f','g','h','j','k','l','A','S','D','F','G','H','J','K','L'};
		vector<char>row3 = {'z','x','c','v','b','n','m','Z','X','C','V','B','N','M'};
		vector<string>rv;

		unordered_map<char, int> map;
		for (auto cit = row1.begin(); cit!=row1.end(); cit++)
			map[*cit] = 1;
		for (auto cit = row2.begin(); cit!=row2.end(); cit++)
			map[*cit] = 2;
		for (auto cit = row3.begin(); cit!=row3.end(); cit++)
			map[*cit] = 3;

		for (auto itword = words.begin(); itword != words.end(); itword++) {
			int row_num = -1; // uninitilized
			auto cit = (*itword).begin();
			for (; cit != (*itword).end(); cit++ )
				if(row_num == -1)
					row_num = map[*cit];
				else
					if (row_num != map[*cit])
						break;
			if (cit == (*itword).end())
				rv.push_back(*itword);
		}
		return rv;
	}
};

/* Upper case and lower case is different!! */

/*test cases: */
