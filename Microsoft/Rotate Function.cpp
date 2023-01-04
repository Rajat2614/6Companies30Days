class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int m = A.size();
        int index = A.size()-1;
        int f0 = 0;
        int sum = 0;
        for(int i=0;i<m;i++){
            f0+=i*A[i];
            sum += A[i];
        }
        int result = f0;
        for(int i=index;i>=0;i--){
            int f = f0+sum-m*A[i];
            f0 = f;
            result = max(result,f);
        }
        return result;
    }
};
