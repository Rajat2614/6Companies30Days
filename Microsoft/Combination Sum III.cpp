class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        return helper(k, n, 1);
    }
    
    vector<vector<int>> helper(int k, int n, int start){
        vector<vector<int>> result;
        
        if(k < 1 || n < 1) return result;
        if(k > 9 || n > 45 || n/k > 9 || start > 9) return result;
        if(k == 1 && n >= start){
            result.push_back(vector<int>{n});
            return result;
        }
        
        for(int i = start; i < 10; i++){
            vector<vector<int>> subResult = helper(k-1, n-i, i+1);
            if(subResult.empty()) continue;
            for(vector<int> sol : subResult){
                sol.push_back(i);
                result.push_back(sol);
            }
        }
        
        return result;
    }
};
