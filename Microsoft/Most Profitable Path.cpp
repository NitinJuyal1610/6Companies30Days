class Solution {
public:
    //dfs to find distance of all node from 0 and path to follow
    void dfs1(int node,int par,int dist,vector<int>& distance,vector<int>& parent,vector<vector<int>>& adjM){
        
        distance[node] = dist;
        parent[node] = par;
        
        for(auto v:adjM[node]){
            if(v == par){
                continue;
            }
            dfs1(v,node,dist +1,distance,parent,adjM);
        }
    }
    
    int dfs2(int node,int par,vector<vector<int>>& adjM,vector<int>& amount){
        
        int ans = INT_MIN;
        for(auto v:adjM[node]){
            if(v != par){
                ans = max(ans,dfs2(v,node,adjM,amount));
            }
        }
        
        if(ans == INT_MIN){
            return amount[node];
        }
        return ans + amount[node];
    }
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();   
        vector<int> parent(n,-1); 
        vector<int> distance(n,0); 
        vector<vector<int>> adjM(n);
        
        for(int i=0;i<edges.size();i++){
            adjM[edges[i][0]].push_back(edges[i][1]);
            adjM[edges[i][1]].push_back(edges[i][0]);
        }
        
        dfs1(0,-1,0,distance,parent,adjM);
        
        //modifying amount array along bob path
        //From Bob to 0
        int cur = bob ,curDis = 0;
        while(cur != 0){
        
            if(curDis < distance[cur]){
                //bob reach before alice
                amount[cur] = 0;
            }
            else if(curDis == distance[cur]){
                //Both reach at same time
                amount[cur] = amount[cur]/2;
            }
            cur = parent[cur];
            curDis++;
        }
        //dfs to find max sum to any leaf node
        return dfs2(0,-1,adjM,amount);
    
    }
};