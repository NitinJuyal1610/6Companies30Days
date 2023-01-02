class Solution {
public:
    
    // bool dfs(int el,vector<bool>&dfsvis,vector<bool>&vis,vector<vector<int>>&adj){
    //     vis[el]=true;
    //     dfsvis[el]=true;
      
    //     for(auto c:adj[el]){
               
    //             if(!vis[c]){
    //                 if(dfs(c,dfsvis,vis,adj))return true;
    //             }
    //             else if(dfsvis[c]){
    //                 return true;
    //             }
    //     }
        
    //     dfsvis[el]=false;
    //     return false;
    // }
    bool canFinish(int n, vector<vector<int>>&edges) {
        
        vector<vector<int>>adj(n);
        vector<int>indegree(n);
        for(auto c:edges){
            adj[c[0]].push_back(c[1]);
            indegree[c[1]]++;
        }

        queue<int>q;

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int>topoSort;

        while(!q.empty()){
            int x=q.front();
            q.pop();
            topoSort.push_back(x);
            for(auto c:adj[x]){
                indegree[c]--;
                if(indegree[c]==0){
                    q.push(c);
                }
            }
        }

       
        return topoSort.size()==n; 
        
    }
};