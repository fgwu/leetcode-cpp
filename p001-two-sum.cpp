class Solution {
public:
	/*20170519 14:34*/
	/*         14:42*/
	/*AC       14:47*/
	/*Note: unordered_map, find will return map.end(). operator[] and at will insert if not found*/
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int,int> map; // number to index map
		vector<int> rv;
		for(int i = 0; i<nums.size(); i++){
			if (map.find(target - nums[i]) != map.end()){
				rv.push_back(i);
				rv.push_back(map.at(target - nums[i]));
				return rv;
			}
			map[nums[i]] = i;
		}
		return rv;
	}
};
