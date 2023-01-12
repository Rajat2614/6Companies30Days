class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> umap;
        int res = 0;
        for(int i = 0 ; i < n ; ++i){
            int val = nums[i];
            int reversed_num = 0;
            while(val>0){
                reversed_num = reversed_num * 10 + val % 10;
                val /= 10;
            }            
            res += umap[reversed_num - nums[i]]++ % 1000000007;
            res %= 1000000007;
        }      
        return res;
    }
};
