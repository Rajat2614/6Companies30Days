class Solution {
public:
    int numberOfSubstrings(const string& s) {
        size_t size = s.size();
        int count = 0, i = -1, j = 0;
        vector<int> state(3, 0);
        while(i < j) {
            if(find(state.begin(), state.end(), 0) == state.end()) {
                count += size-j+1;
                --state[s[++i]-'a'];
            } else {
                if(j < size) ++state[s[j++]-'a'];
                else return count;
            }
            
        }
        return count;
    }
};
