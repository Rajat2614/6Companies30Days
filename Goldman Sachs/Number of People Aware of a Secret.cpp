#define mod 1000000007
class Solution {
public:
    long long dp[1001];
    long long func(int i,int n, int d,int f)
    {
        if(i>n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        dp[i]=0;
        for(int j=i+d;j<i+f;j++)
            dp[i]=(dp[i] + func(j,n,d,f))%mod;
        if(i+f>n)
            dp[i]= (dp[i]+1)%mod;
        return dp[i];
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        for(int i=0;i<1001;i++)
            dp[i]=-1;
        func(1,n,delay,forget);
        return dp[1];
    }
};
