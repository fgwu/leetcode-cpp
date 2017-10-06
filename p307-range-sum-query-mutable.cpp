class NumArray {
private:
    vector<int> A;
    vector<int> V;
    int N;
public:
    /*20171006*/
    /*AC   1453*/
    NumArray(vector<int> nums) {
        N = nums.size();
        A.resize(N + 1);
        V.resize(N);
        
        for (int i = 0; i < nums.size(); i++)
            update(i, nums[i]);
    }
    
    void update(int i, int val) {
        int delta = val - V[i];
        int idx = i + 1;
        do {
            A[idx] += delta;
            idx += (idx & -idx);
        } while (idx <= N);
        
        V[i] = val;
    }
    
    
    int query(int i) {
        int rv = 0;
        while (i > 0) {
            rv += A[i];
            i -= (i & -i);
        }
        return rv;
    }
    
    int sumRange(int i, int j) {
        return query(j + 1) - query(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */