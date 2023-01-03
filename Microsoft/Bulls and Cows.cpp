class Solution {
public:
    string getHint(string secret, string guess) {
        int bull=0;
        int cow=0;
        unordered_map<int,int>m;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]) bull++;
            m[secret[i]]++;
        }
        for(auto x:guess) if(m[x]>0) m[x]--,cow++;
        cow-=bull;
        return to_string(bull)+"A"+to_string(cow)+"B";
    }
};
