class Solution {
public:
    int TLE(vector<int>&nums){
       int x=0;
       int n=nums.size();
       int maxi=INT_MIN;
       for(int i=0;i<n;i++){
           int curr=0;
           int x=i;
           for(auto c:nums){
               curr+=(c)*(x%n);
               x++;
           }
           maxi=max(maxi,curr);
       } 
       return maxi;
    }
    int maxRotateFunction(vector<int>& nums) {    
        //Fk=Fk-1+sum-n*nums[0]
        int n=nums.size();
        int x=0;
        int sum=0;
    
        for(int i=0;i<n;i++){
            sum+=nums[i];
            x+=i*nums[i];
        }
        int maxi=x;
        for(int i=1;i<n;i++){
            x=x+sum-(n*nums[n-i]);
            maxi=max(maxi,x);
        }
        return maxi;
    }
};