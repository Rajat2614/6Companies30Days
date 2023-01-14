class Solution {
public:
    int findIntegers(int num) {
        string str="";
        while(num>0)str+=num%2+'0',num/=2;
        int l=str.length();
        vector<int> arr(l+1,1);
        for(int i=2;i<=l;i++)arr[i]=arr[i-1]+arr[i-2];
        int result=1,pre=0;
        for(int i=l;i>=0;i--)
        {
            if(str[i-1]=='1')
            {
                result+=arr[i];
                if(pre==1)break;
            }
            pre=str[i-1]=='1';
        }
        return result-pre;
    }
};
