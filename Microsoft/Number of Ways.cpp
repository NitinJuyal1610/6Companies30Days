class Solution {
public:
    int mod=(int)(1e9+7);
    //Dijkstra with additional array
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto c:roads){
            adj[c[0]].push_back({c[1],c[2]});
            adj[c[1]].push_back({c[0],c[2]});
        }

        vector<int>ways(n,0);
        ways[0]=1;
        vector<long long>dist(n,1e18);
        dist[0]=0;

        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            //dist node
            pair<long long int,long long int>m=pq.top();
            pq.pop();
            for(auto c:adj[m.second]){
                //node dist
                int adjNode=c.first;
                long long int adjDis=c.second;

                if(m.first+adjDis<dist[adjNode]){
                    dist[adjNode]=m.first+adjDis;
                    pq.push({m.first+adjDis,adjNode});
                    ways[adjNode]=ways[m.second];
                }else if(m.first+adjDis==dist[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[m.second])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};