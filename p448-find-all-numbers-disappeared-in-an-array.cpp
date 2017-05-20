class Solution {
public:
	/*20170518 14:11*/
	/*20170518 14:20*/
	/*AC       14:22*/
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		int i, tmp, last;
		vector<int> rv;
		for (i = 0; i < nums.size(); i++){
			tmp = nums[i];
			while (nums[tmp - 1] != tmp){
				last = nums[tmp - 1];
				nums[tmp - 1] = tmp;
				tmp = last;
			}
		}

		for (i = 0; i < nums.size(); i++)
			if (nums[i] != i + 1)
				rv.push_back(i + 1);
		return rv;
	}
};
