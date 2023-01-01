class Solution {
public:

    void helper(int k,int sum,vector<int>&p,vector<vector<int>>&v){
        if(k==0){
            if(sum==0){
                v.push_back(p);   
            }
            return;
        }
        int s=1;
        if(!p.empty()){
            s=p.back()+1;
        }
        for(int i=s;i<=9;i++){
            if(sum>=i){
                p.push_back(i);
                helper(k-1,sum-i,p,v);
                p.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>>v;
        vector<int>p;

        helper(k,n,p,v);
        return v;
    }
};