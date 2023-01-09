class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        
        unordered_map<int, int> hash;
        int n = cards.size()-1;
        int mn=INT_MAX;
        
        for(int i=n;i>=0;i--){
            
            if(hash.find(cards[i]) != hash.end()){
                mn = min(mn, hash[cards[i]]-i);
                hash[cards[i]]=i;
            }
            else if(hash.find(cards[i]) == hash.end()){
                hash[cards[i]] = i;
            }
        }
        
        if(mn != INT_MAX) return mn+1;
        return -1;
    }
};
