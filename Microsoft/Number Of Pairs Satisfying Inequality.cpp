class Solution {
public:
    vector<int> seg;
    int n=0;
    
    int query(int left, int right){
        int res=0;
        for(left+=n, right+=n; left<right; left>>=1, right>>=1){
            if(left&1){
                res+=seg[left++];
            }
            if(right&1){
                res+=seg[--right];
            }
        }
        
        return res;
    }
    
	// update the tree
    void update(int index){
        for(seg[index+=n]+=1; index>1; index>>=1){
            seg[index>>1]=seg[index]+seg[index^1];
        }
    }
    
    long long numberOfPairs(vector<int>& n1, vector<int>& n2, int diff) {
        int shift=20000;
        n=200001;
        vector<int> d1;
        
        seg.resize(n*2, 0);
        
		// precaculate nums1[i]-nums2[i]
        for(int i=0; i<n1.size(); i++){
            d1.push_back(n1[i]-n2[i]);
        }
        
        long long ans=0;
        update(d1[0]+shift);
		// query and update the tree
        for(int i=1; i<n1.size(); i++){
            ans+=query(0, d1[i]+1+shift+diff);
            update(d1[i]+shift);
        }
              
        return ans;
    }
};
