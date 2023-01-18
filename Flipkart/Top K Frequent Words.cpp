class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hash_table;
        for(string& word : words){
            hash_table[word]++;
        }
        vector<string> ans;
        map<int, vector<string>> count_to_word;
        int left = k;
        for(auto& [word, count] : hash_table){
            count_to_word[count].push_back(word);
        }
        for(auto itr = count_to_word.rbegin(); itr != count_to_word.rend() && left > 0; itr++){
            int size = itr->second.size();
            sort(itr->second.begin(), itr->second.end());
            for(string& word : itr->second){
                ans.push_back(word);
            }
            left -= size;
        }
        while(ans.size() > k){
            ans.pop_back();
        }
        return ans;
    }
};
