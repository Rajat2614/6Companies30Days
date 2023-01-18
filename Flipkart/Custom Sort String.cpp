class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> char_count(26, 0);
        string ans = "";
        for(char& c : s){
            int bucket = c - 'a';
            char_count[bucket]++;
        }
        for(char& c : order){
            int bucket = c - 'a';
            ans += string(char_count[bucket], c);
            char_count[bucket] = 0;
        }
        for(int i = 0; i < 26; i++){
            if(char_count[i]){
                char cur_char = i + 'a';
                int cur_char_count = char_count[i];
                ans += string(cur_char_count, cur_char);
            }
        }
        return ans;
    }
};
