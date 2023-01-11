class Solution {
public:
    vector<string> invalidTransactions(vector<string>& strr) {
        int n = strr.size();
        vector<vector<string>> arr;
        vector<bool> check(n,true);
        vector<string> ans;
        
        for(auto it : strr){
            stringstream sstr(it);
            vector<string> v;
            while(sstr.good()){
                string substr;
                getline(sstr, substr, ',');
                v.push_back(substr);
            }
            arr.push_back(v);
        }
        
        sort(arr.begin(),arr.end(),[&](auto &a,auto &b) {return stoi(a[1]) < stoi(b[1]);});
        
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<i;j++){
                if(stoi(arr[j][1]) + 60 >= stoi(arr[i][1]) and arr[j][0] == arr[i][0] and arr[j][3] != arr[i][3]){
                    check[j] = check[i] = false;
                }
            }
            if(stoi(arr[i][2]) > 1000){
                check[i] = false;
            }
        }
        
        for(int i=0;i<n;i++){
            if(!check[i]){
                ans.push_back({arr[i][0] + "," + arr[i][1] + "," + arr[i][2] + "," + arr[i][3]});
            }
        }
        
        return ans;
    }
};
