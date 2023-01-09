class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans=0;
        int n=points.size();

        for(int i=0;i<n;i++){
            unordered_map<long long ,int>mpp;
            for(int j=0;j<n;j++){
                if(i!=j){
                    long long int x=(points[j][0]-points[i][0])*(points[j][0]-points[i][0])+(points[j][1]-points[i][1])*(points[j][1]-points[i][1]);
                    mpp[x]++;
                }
            }

            for(auto c:mpp){
               if(c.second>=2)ans+=(c.second)*(c.second-1); 
            }
        }
        return ans;
    }
};