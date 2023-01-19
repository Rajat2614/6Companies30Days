class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes = getPrimes(left, right);
        int n = primes.size();
        if(n <= 1){
            return {-1, -1};
        }
        vector<int> ans = {primes[0], primes[n - 1]};
        for(int i = 1; i < n; i++){
            int cur_diff = primes[i] - primes[i - 1];
            int ans_diff = ans[1] - ans[0];
            if(cur_diff < ans_diff){
                ans = {primes[i - 1], primes[i]};
            }
        }
        return ans;
    }
    
    vector<int> getPrimes(int& left, int& right){
        int n = right + 1;
        vector<bool> primes(n, true);
        primes[1] = false;
        for(int i = 2; i * i <= right; i++){
            if(primes[i]){
                for(int j = i * i; j <= right; j += i){
                    primes[j] = false;
                }
            }
        }
        vector<int> ans;
        for(int i = left; i < n; i++){
            if(primes[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
