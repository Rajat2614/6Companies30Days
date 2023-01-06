class Solution {
public:
    #define lli unsigned long long int
    #define pa pair<unsigned long long int,unsigned long long int>
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pa>adj[n];
    lli mod=1e9+7;
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
             adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue<pa,vector<pa>,greater<pa> >q;
         q.push({0,0});
        vector<pa> dist(n);
        for(int i=1;i<n;i++)dist[i]={1e15,0};
         dist[0]={0,1};
         lli vis[n];memset(vis,0,sizeof(vis));
          while(!q.empty())
           {   
	            lli src=q.top().second;
	            lli cost=q.top().first;
	             q.pop();
              
              if(vis[src]==1)continue;
               vis[src]=1;
	           for(int i=0;i<adj[src].size();i++)
	           {    pa temp=adj[src][i];
		           if(dist[temp.first].first >=cost+temp.second)
                   {   lli sum;
                       if(dist[temp.first].first ==cost+temp.second)
                       {
                         sum=(dist[temp.first].second+dist[src].second)%mod;
                       }
                     else
                     {
                        sum=dist[src].second%mod;
                     }
                      dist[temp.first]={cost+temp.second,sum};
                      q.push({dist[temp.first].first,temp.first});
                   }
	           }
           }
        return dist[n-1].second%mod;
        
    }
};
