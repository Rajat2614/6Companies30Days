class Solution {
public:
    int rhombusSum(vector<vector<int>>& grid,int l,int r,int u,int d){
        int c1 = (l+r)/2,c2=(l+r)/2,sum=0;
        bool expand = true;

        for(int row = u;row<=d;row++){
            if(c1 == c2) sum += grid[row][c1];
            else sum += grid[row][c1] + grid[row][c2];

//if c1==l then c2 automatically equal r no need to write both but its okay to write both        
            if(c1 == l && c2==r) expand = false;

            if(expand) c1--,c2++;
            else c1++,c2--;
        }

        return sum;
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        set<int> pq;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int l=j,r=j,d=i; // left,right,down
                while(l>=0 && r<n && d<m){
                    int sum = rhombusSum(grid,l,r,i,d);
                    l--; r++; d += 2;
                    if(pq.size() < 3) pq.insert(sum);
                    else if(pq.size() == 3 && pq.count(sum)==0 && sum > *(pq.begin())) {
                        pq.erase(pq.begin());
                        pq.insert(sum);
                    }
                }
            }
        }

        vector<int> ans;
        for(int it : pq){
            ans.push_back(it);
        }

        //already sorted so reverse it to get decreasing order
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
