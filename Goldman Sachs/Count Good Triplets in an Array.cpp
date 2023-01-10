class BinaryIndexedTree{
    vector<int>tree;
    int n;
    int lowbit(int i){
        return i&(-i);
    }
    public:
    BinaryIndexedTree(int len):n(len), tree(len+1, 0){}
    void add(int i){
        for(;i<=n;i+=lowbit(i)){
            tree[i]++;
        }
    }
    
    int query(int i){
        int ret = 0;
        for(;i;i-=lowbit(i)){
            ret += tree[i];
        }
        return ret;
    }
    
    int query(int i, int j){
        if(i>j)
            return 0;
        return query(j)-query(i-1);
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        if(!n)
            return 0;
        vector<int>dict(n, 0);
        for(int i = 0;i<n;i++){
            dict[nums2[i]] = i+1;
        }
        auto tree = BinaryIndexedTree(n);
        vector<long long>prefix(n, 0), suffix(n, 0);
        for(int i = 0;i<n;i++){
            int index = dict[nums1[i]];
            prefix[i] = tree.query(1, index-1);
            tree.add(index);
        }
        tree = BinaryIndexedTree(n);
        for(int i = n-1;i>=0;i--){
            int index = dict[nums1[i]];
            suffix[i] = tree.query(index+1, n);
            tree.add(index);
        }
        long long ret = 0;
        for(int i = 0;i<n;i++){
            ret += prefix[i]*suffix[i];
        }
        return ret;
    }
};
