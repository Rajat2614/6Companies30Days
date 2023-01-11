class Solution {
public:
        vector<string> invalidTransactions(vector<string>& transactions) {
        unordered_set<string> res;
        unordered_map<string,vector<vector<string>>> m;
        for(auto& t:transactions){
            istringstream ss(t);
            vector<string> s(4,"");
            int i=0;
            while(getline(ss,s[i++],','));
            if(stoi(s[2])>1000) res.insert(t);
            for(vector<string> j:m[s[0]])
                if((j[3]!=s[3])&&abs(stoi(j[1])-stoi(s[1]))<=60){
                    res.insert(j[0]+","+j[1]+","+j[2]+","+j[3]);
                    if(!res.count(t)) res.insert(t);
                }
            m[s[0]].push_back({s[0],s[1],s[2],s[3]});
        }
        vector<string> ans;
        for(auto& k:res) ans.push_back(k);
        return ans;
    }
};
