class Solution {
public:
	/*
	  1
	  1 1
	  1 2 1
	  1 3 3 1
	*/
	/*AC 20170607 1237*/
	vector<int> getRow(int rowIndex) {
		vector<int> res(rowIndex + 1, 1);
		res[0] = 1;
		for (int i = 1; i <= rowIndex; i++)
			for (int j = i - 1; j > 0; j--)
				res[j] += res[j - 1];
		return res;
	}
};
