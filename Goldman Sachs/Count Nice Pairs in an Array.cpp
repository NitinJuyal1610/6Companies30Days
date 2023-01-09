class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int mod=(int)1e9+7;
        unordered_map<int,int>mpp;
        int ans=0;
        for(auto &c:nums){
            string s=to_string(c);
            reverse(s.begin(),s.end());
            c=(c-stoi(s));
            if(mpp.find(c)!=mpp.end()){
                ans=(ans%mod+mpp[c])%mod;
            }
            mpp[c]++;
        }

        return ans;
        
    }
};