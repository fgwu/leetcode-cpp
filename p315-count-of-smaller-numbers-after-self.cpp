class Solution {
public:
	/*20171006 1629*/
	/*AC       1721*/
	vector<int> ft;
	int N;

	int ft_query(int i) {
		int sum = 0;
		while(i) {
			sum += ft[i];
			i -= (i & -i);
		}
		return sum;
	}

	void ft_add(int i, int delta) {
		i++;
		do {
			ft[i] += delta;
			i += (i & -i);
		} while (i < N);
	}

	vector<int> countSmaller(vector<int>& nums) {
		vector<int> res, clone(nums);
		N = nums.size() + 1;
		ft.resize(N, 0);
		res.resize(nums.size());
		sort(clone.begin(), clone.end());
		unordered_map<int, int> reflect;
		for (int i = 0; i < clone.size(); i++)
			reflect[clone[i]] = i;

		for (int i = nums.size() - 1; i >= 0; i--) {
			res[i] = ft_query(reflect[nums[i]]);
			ft_add(reflect[nums[i]], 1);
		}

		return res;
	}
};
