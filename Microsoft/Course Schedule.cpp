class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       int count=0;
		//create an adjacency list
        vector<vector<int>>adj(numCourses);
        for(int i=0; i<prerequisites.size();i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
		//create indegree vector
        vector<int>indegree(numCourses, 0);
        for(int i=0;i<numCourses;i++)
        {
            for(int x:adj[i])
                indegree[x]++;
        }
        queue<int>q;
		//push all the nodes having indegree==0
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(q.empty()==false)
        {
            int c= q.front();
            q.pop();
            for(int x: adj[c])
            {
                indegree[x]--;
                if(indegree[x]==0)
                    q.push(x);
            }
            count++;
        }
        return (count==numCourses);
    }
};
