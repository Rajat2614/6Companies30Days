class Solution {
unordered_map<int, bool> hash_table;
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k)
            return false;
        int target = sum / k;
        sort(nums.begin(), nums.end(), greater<int>());
        int mask = 0;
        return dfs(nums, mask, k, target, 0, 0);
    }
    
    bool dfs(vector<int>& nums, int& mask, int k, int& target, int curr_sum, int pos){
        if(k == 1)
            return true;
        if(hash_table.count(mask))
            return hash_table[mask];
        if(curr_sum == target){
            return dfs(nums, mask, k - 1, target, 0, 0);
        }
        int n = nums.size();
        for(int i = pos; i < n; i++){
            if((mask & (1 << i)) == 0){
                if(curr_sum + nums[i] > target)
                    continue;
                mask |= 1 << i;
                if(dfs(nums, mask, k, target, curr_sum + nums[i], i + 1))
                    return true;
                mask ^= 1 << i;
            }
        }
        hash_table[mask] = false;
        return false;
    }
};
