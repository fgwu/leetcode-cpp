class Solution {
public:
/*20170519 17:54*/
/*         18:00*/
/*AC       18:03  --i => ++i */ 
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> rv;
        if (numbers.size() < 2) return rv;
        int i = 0, j = numbers.size() - 1;
        
        while ((numbers[i] + numbers[j] != target) && (i < j)){
            if (numbers[i] + numbers[j] > target) 
                --j;
            else
                ++i;
        }
        
        if (numbers[i] + numbers[j] == target){
            rv.push_back(i+1);
            rv.push_back(j+1);
        } 
        
        return rv;
    }
};