class Solution {
public:
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       //similiar to LIS
       vector<int>dp(nums.size(),1);
       int end=0;
       int maxi=0;
       vector<int>track(nums.size());
       for(int i=1;i<nums.size();i++){
           track[i]=i;
           for(int j=0;j<i;j++){
               //pick 
               if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                   dp[i]=dp[j]+1;
                   track[i]=j;
               }
           }

           if(dp[i]>maxi){
               maxi=dp[i];
               end=i;
           }
       }
       
       
       vector<int>ans;
    
       ans.push_back(nums[end]);
       while(end!=track[end]){
           ans.push_back(nums[track[end]]);
           end=track[end];
       }
       return ans;
    }
};