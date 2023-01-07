class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        //we'll check area 
        long long int areaCurr=0;
        
        vector<pair<int,int>>v;
        for(auto c:rectangles){
            areaCurr+=((long long)(c[2]-c[0])*(long long)(c[3]-c[1]));
            v.push_back({c[0],c[1]});
            v.push_back({c[2],c[3]});
        }
        int n=v.size();
        sort(v.begin(),v.end());
        long long int areaExpected=(long long)(v[n-1].first-v[0].first)*(long long)(v[n-1].second-v[0].second);
    
        if(areaCurr!=areaExpected)return false;
        // now check corners
        map<pair<int,int>,int> coord;
        for(auto &it : rectangles){
            coord[{it[0], it[1]}]++;
            coord[{it[0], it[3]}]--;
            coord[{it[2], it[3]}]++;
            coord[{it[2], it[1]}]--;
        }
        int cnt = 0;

        for(auto it:coord){
            if(abs(it.second) == 1){
                cnt++;
            }else if(abs(it.second != 1) && it.second != 0){
                return false;
            }
            
        }
        return cnt == 4;
    }
};