class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(1,n,ans,temp,k);
        return ans;
    }
    
    void helper(int ind, int n, vector<vector<int>>& ans, vector<int>& temp, int k){
        if(k==0 && n==0){
            ans.push_back(temp);
            return;
        }

        if(n<0){
            return;
        }

        for(int i=ind;i<=9;i++){
            if(i>n){
                break;
            }

            temp.push_back(i);
            helper(i+1,n-i,ans,temp,k-1);
            temp.pop_back();
        }
    }
};
