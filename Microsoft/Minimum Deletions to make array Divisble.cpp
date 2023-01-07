class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        unordered_map<int,int> map;
        for(auto next : nums) map[next]++;
        priority_queue <int, vector<int>, greater<int>> pq;
        
        for(auto next : map) pq.push(next.first);
        
        int res = 0;
        
        while(!pq.empty()) {
            auto top = pq.top();
            if (!divisible(top, numsDivide)) {
                pq.pop();
                res += map[top];
            } else return res;
        }
        
        return pq.empty() ? -1 : res;
 
    }
    
private:
    bool divisible(int top, vector<int> & numsDivide) {
        for(auto & next : numsDivide) {
            if(next % top != 0) return false;
        }
        return true;
    }
};
