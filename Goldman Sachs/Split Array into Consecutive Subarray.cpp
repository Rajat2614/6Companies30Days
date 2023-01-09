class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> freq;
        
        for(int n : nums)
            freq[n]++;
        
        unordered_map<int,int> need;
        
        for(int n : nums){
            
            if(freq[n]==0)  // n is already been inserted in a subsequence
                continue;
            
            if(need[n]>0){ // n can be inserted in a already existing subsequence
                need[n]--;
                freq[n]--;
                
                need[n+1]++;
            }   
            
            else if(freq[n]>0 && freq[n+1]>0 && freq[n+2]>0){ // n cannot be inserted in already existing subsequence therefore we need to insert it into a new subseq.
                freq[n]--;
                freq[n+1]--;
                freq[n+2]--;
                
                need[n+3]++;
            }
            
            else{
                return false;
            }
        }
        return true;
    }
};
