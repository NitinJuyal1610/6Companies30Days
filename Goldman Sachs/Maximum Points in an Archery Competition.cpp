class Solution {
public:
    vector<int>ans;
    int maxi=-1;
    void helper(int i,vector<int>&v,vector<int>&aliceArrows,int numArrows,int sum){
        if(numArrows<0)return;
        if(i==aliceArrows.size()){
            if(sum>maxi){
                maxi=sum;
                ans=v;
                if(numArrows!=0){
                    ans[0]+=numArrows;
                }
            }
            return;
        }
        if(aliceArrows[i]<=numArrows){
            v[i]=aliceArrows[i]+1;
            helper(i+1,v,aliceArrows,numArrows-v[i],sum+i);
            v[i]=0;
        }
        helper(i+1,v,aliceArrows,numArrows,sum);
        return;
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int>v(aliceArrows.size());
        helper(0,v,aliceArrows,numArrows,0);
        return ans;
    }
};